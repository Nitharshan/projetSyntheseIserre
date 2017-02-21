#include "app.h"
#include "sensor.h"
#include "1wire/onewire.h"
#include "stdio.h"
#include "StringUtility.h"
#include "console.h"

float temp; // Derniere temperature mesuree
uint64_t sink_address = 0xFFFF;
iSN_FrameCommand last_command;


/**
 * Envoie une trame contenant le message de temperature au sink
 */
void envoi_mesure() {

	uint8_t buffer_temp[4] = {0};

	DS18B20_LireTemperature(&temp);

	convertFloat2Buffer(temp, buffer_temp);

	// Creer trame iSN_Measure
	iSN_FrameMeasure isn_frame = createMeasureFrame(buffer_temp);

	uint8_t xb_payload[5] = {0};

	xb_payload[0] = isn_frame.frameType;
	for(int i = 1; i < sizeof(xb_payload); i++) {
		xb_payload[i] = isn_frame.measure[i-1];
	}

	sendFrame(sink_address, xb_payload, sizeof(xb_payload));

}

/*
 * Mettre le contenu du fifo dans le buffer passé en paramètre. (XB_API 2)
 */
void lire_contenu_fifo(struct Fifo *fifo, uint8_t *contenu_fifo) {
	uint8_t byte = 0;
	int length = 0;

	while (fifo->begin != fifo->end) {
		lire_fifo_buffer(fifo, &byte);

		if (byte == XB_FRAME_START_DELIMITER) {
			contenu_fifo[0] = byte;
			lire_fifo_buffer(fifo, &byte);
			contenu_fifo[1] = byte;
			lire_fifo_buffer(fifo, &byte);
			if(byte != 0x7D) {
				length = byte;
			}
			else {
				length = byte ^ 0x20;
			}
			contenu_fifo[2] = byte;

			for (int i = 3; i <= length+4; i++) {
				lire_fifo_buffer(fifo, &byte);
				if(byte == 0x7D) {
					length++;
				}
				contenu_fifo[i] = byte;
			}
			break;
		}
	}
}

/**
 * Verifie le buffer de reception s'il y'a une trame iSN.
 * Si trame complète trouvée, retourne le iSN_FrameType correspondant.
 * Sinon, retourne -1.
 */
int check_trame_recue() {

	uint8_t trame_brute[XB_PAYLOAD_MAX_SIZE] = { 0 };

	int data_length = 0;
	if (fifo_xbee.end > fifo_xbee.begin) {
		data_length = fifo_xbee.end - fifo_xbee.begin;
	} else if (fifo_xbee.begin == fifo_xbee.end) {
		return -1 ; // Buffer de reception vide
	} else {
		data_length = FIFO_SIZE - (fifo_xbee.begin - fifo_xbee.end);
	}

	// Recuperer le contenu du fifo_buffer -> la trame brute
	lire_contenu_fifo(&fifo_xbee, trame_brute);

	// Trame Xbee recue
	xbee_rx_frame trame_xb = createRxFrame(trame_brute);

	if (trame_xb.checksum == 0xFF)
		return -1; // Trame incomplète

	// Mettre à jour l'adresse du sink
	sink_address = trame_xb.rx_header.source_address;

	// Decodage trame iSN selon le frame_type trouvé
	switch(trame_xb.payload[0]) {
		case  iSN_FrameType_Command:
			if(trame_xb.payload_size == sizeof(iSN_FrameCommand)) {
				last_command = createCommandFrame(trame_xb.payload[1]);

				return iSN_FrameType_Command;
			}
			break;
		default:
			return -1;
			break;
	}
}


void app_run() {

	init_fifo(&fifo_xbee);
	DS18B20_LireTemperature(&temp); // Première lecture non envoyée (calibrage)

	for(;;)
		{
			switch(check_trame_recue()) {
				case iSN_FrameType_Command:
					// Commande reçue, last_command est à jour.
					switch(last_command.command) {
						case 0:
							// Desactiver relais
							break;
						case 1:
							// Activer relais
							break;
						case 2:
							envoi_mesure();
							//last_command = 0;
							break;
						default:
							break;
					}
					break;
				default:
					break;


			}
			OSA_TimeDelay(3000); // Délai avant de relire le buffer de reception. Nécessaire pour pouvoir lire toute la trame.
		}
}
