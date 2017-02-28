#include "Xbee_Driver.h"


// création du header de la frame tx
xbee_tx_frame_header createTxHeader(uint64_t address)
{
	xbee_tx_frame_header header;
	header.frame_type = DM_API_CMD_TX_REQUEST;
	header.frame_id = 0x01;
	header.destination_address = address;
	header.network_address_be = 0xFFFE;
	header.broadcast_radius = 0x0;
	header.options = 0x0;

	return header;
}

// remplissage de la structure de donnée

uint8_t* createSearchsSinkformat(uint8_t type)
{
	uint8_t  SearchFrame[3];
	SearchFrame[0] = 0x01;
	SearchFrame[1] = type;

	return SearchFrame;
}

// création du header de la frame rx
xbee_rx_frame_header createRxHeader(uint64_t address)
{
	xbee_rx_frame_header header;
	header.frame_type = DM_API_CMD_RECEIVE_PACKET;
	header.source_address = address;
	header.network_address_be = 0xFFFE;
	header.options = 0x01;

	return header;
}

// calcul de la valeur checksum de la frame tx en paramètre
void calculate_tx_checksum(xbee_tx_frame *frame)
{
	// Checksum is FF minus 8-bit sum of bytes between length and checksum
	uint8_t sum = 0;
	for (int i = 3; i < frame->raw[2] + 3; i++) {
		sum +=  frame->raw[i];
	}

	uint8_t checksum = 0xFF - sum;

	// replace dummy checksum with calculated value in raw
	frame->raw[TX_HEADER_LENGTH + frame->payload_size - 1] = checksum;

	frame->checksum = checksum;

}

// calcul de la valeur checksum de la frame rx
void check_rx_checksum(xbee_rx_frame *frame)
{
	uint8_t sum = 0;
	for(int i = 3; i < frame->raw[2]+3; i++) {
		sum += frame->raw[i];
	}

	uint8_t checksum = 0xFF - sum;

	if(checksum == frame->raw[RX_HEADER_LENGTH + frame->payload_size -1]) {
		// Valid checksum, don't do anything
		frame->checksum = checksum;
	}
	else {
		// Signals error, must be processed by calling method.
		frame->checksum = 0xFF;
	}
}

/**
 * Extract byte array from a 64-bit number
 */
void address_to_byte_array(uint64_t address, uint8_t *byte_array)
{
	for (int i = 0; i < 8; i++) {
		*byte_array++ = ( address >> (64 - (8*(i+1))) ) & 0xFF;
	}
}

/*
 *génére la valeur raw de la frame tx en paramètre
 */
void tx_frame_generate_raw(xbee_tx_frame *frame)
{
	frame->raw[0] = frame->start_delimiter;
	frame->raw[1] = frame->length_msb;
	frame->raw[2] = frame->length_lsb;
	frame->raw[3] = frame->tx_header.frame_type;
	frame->raw[4] = frame->tx_header.frame_id;

	// address
	uint8_t address_bytes[8];
	address_to_byte_array(frame->tx_header.destination_address, address_bytes);

	for (int i = 5; i < 13; i++) {
		frame->raw[i] = address_bytes[i-5];
	}

	frame->raw[13] = (frame->tx_header.network_address_be >> 2) & 0xFF;
	frame->raw[14] = frame->tx_header.network_address_be & 0xFF;
	frame->raw[15] = frame->tx_header.broadcast_radius;
	frame->raw[16] = frame->tx_header.options;

	// Puts payload in the raw data
	// (starts at header_length -1 because checksum must be at the end)
	for (int i = 17; i < 17 + frame->payload_size; i++) {
		frame->raw[i] = frame->payload[i-17];
	}

	// dummy checksum because checksum is calculated after this method
	frame->raw[17 + frame->payload_size] = 0xFF;
}

/*
 * création de la frame tx avec les paramètres d'adresse, de données et de la taille des données
 */
xbee_tx_frame createTxFrame (uint64_t address, uint8_t *data, uint8_t data_length)
{
	xbee_tx_frame txFrame;

	txFrame.payload_size = data_length;
	txFrame.length_msb = 0x00;

	// Length = Number of bytes between length and checksum (Header length + Data length)
	// Header length = type (1) + ID(1) + address (8) + network(2) + broadcast(1) + options(1)
	// Header length = 14 (dec) = 0xE (hex)
	txFrame.length_lsb = data_length + 0xE;

	txFrame.start_delimiter = XB_FRAME_START_DELIMITER;

	for(int i = 0; i < data_length; i++) {
		txFrame.payload[i] = *data++;
	}

 	txFrame.tx_header = createTxHeader(address);

 	tx_frame_generate_raw(&txFrame);
 	calculate_tx_checksum(&txFrame);

 	return txFrame;

}

/*
 * convertit de à partir de l'API des données convertit en données bruts dans les paramètres
 */
void convertFromApi2(uint8_t *raw_data, uint8_t *converted_data) {
	int frameLength = 0;
	int i = 0;
	int j = 0;
	converted_data[0] = raw_data[0];
	converted_data[1] = raw_data[1];

	if(raw_data[2] != 0x7D) {
		frameLength = raw_data[2];
		i = 3;
	}
	else {
		frameLength = raw_data[3] ^ 0x20;
		i = 4;
	}

	converted_data[2] = frameLength;

	j = 3;
	while(j < frameLength + 4) {
		if(raw_data[i] == 0x7D) {
			converted_data[j] = raw_data[i+1] ^ 0x20;
			i+= 2;
			j++;
		}
		else {
			converted_data[j] = raw_data[i];
			i++;
			j++;
		}
	}
}

/*
 * convertit vers l'API des données brut en valeurs brut dans les paramètres
 */
int convertToApi2(uint8_t *raw_data, uint8_t *converted_data) {
	int frameLength = raw_data[2];
	int i = 2;
	int j = 2;
	int size = frameLength + 4;

	converted_data[0] = raw_data[0];
	converted_data[1] = raw_data[1];

	while(i < frameLength + 4) {
		if ((raw_data[i] == 0x7E) || (raw_data[i] == 0x7D) || (raw_data[i] == 0x11) || (raw_data[i] == 0x13) ) {
			converted_data[j] = 0x7D;
			converted_data[j+1] = raw_data[i] ^ 0x20;
			i++;
			j+=2;
			size++;
		}
		else {
			converted_data[j] = raw_data[i];
			i++;
			j++;
		}
	}
	return size;
}

/**
 * Creates an actual rx_frame from raw bytes
 */
xbee_rx_frame createRxFrame(uint8_t raw_data[]) //, uint8_t datalength
{
	uint8_t converted_data[XB_PAYLOAD_MAX_SIZE] = {0};

	convertFromApi2(raw_data, converted_data);

	xbee_rx_frame rxFrame;

	rxFrame.start_delimiter = XB_FRAME_START_DELIMITER;
	rxFrame.length_msb = converted_data[1];
	rxFrame.length_lsb = converted_data[2];

	uint64_t address = 0;
	for(int i = 4; i < 12; i++) {
		address <<= 8;
		address |= (uint64_t)converted_data[i];
	}

	xbee_rx_frame_header header = createRxHeader(address);
	header.options = converted_data[14];
	rxFrame.rx_header = header;
	rxFrame.payload_size = rxFrame.length_lsb - 12;

	// Get payload
	for(int i = 0; i < rxFrame.payload_size; i++) {
		rxFrame.payload[i] = converted_data[i+15];
	}
	for (int i = 0; i < rxFrame.length_lsb + 4; i++) {
		rxFrame.raw[i] = converted_data[i];
	}

	// Fill checksum value if it's valid. If not valid checksum = 0xFF (signals error somewhere)
	check_rx_checksum(&rxFrame);

	return rxFrame;

}

/*
 * envoie la trame avec les paramètres adress, données et taille des données
 */
void sendFrame(uint64_t address, uint8_t *data, uint8_t data_length)
{
	xbee_tx_frame frame = createTxFrame(address, data, data_length);

	uint8_t converted_data[XB_PAYLOAD_MAX_SIZE] = {0};
	uint8_t size = convertToApi2(frame.raw, converted_data);

	for(int i = 0; i < size; i++) {
		UART_DRV_SendDataBlocking(uart_xb_IDX, &converted_data[i], 1, 10);
	}
}



