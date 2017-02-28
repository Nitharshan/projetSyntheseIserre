#include "iSerre-SN.h"
#include "Xbee_Driver.h"

/*
 * création de la frame de commande avec en paramètre la commande
 */
iSN_FrameCommand createCommandFrame(uint8_t commande) {

	iSN_FrameCommand isn_frame;
	isn_frame.frameType = iSN_FrameType_Command;

	isn_frame.command = commande;

	return isn_frame;
}

/*
 * création de la frame de mesure avec en paramètre la valeur
 */
iSN_FrameMeasure createMeasureFrame(uint8_t *valeur) {
	iSN_FrameMeasure frame;
	frame.frameType = iSN_FrameType_Measure;
	for (int i = 0; i < 4; i++) {
		frame.measure[i] = valeur[i];
	}


	return frame;

}

/*
 *conversion du float au buffer
 */
void convertFloat2Buffer(const float f, uint8_t* buffer)
{
	for(int i = 0 ; i < sizeof(float) ; i++)
		buffer[i] = ((uint8_t*)&f)[i];
}

/*
 * conversion du buffer en float
 */
void convertBuffer2Float(const uint8_t* buffer, float* f)
{
	*f = *((float*)buffer);
}
