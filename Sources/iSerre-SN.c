/*
 * iSerre-SN.c
 *
 *  Created on: Dec 16, 2016
 *      Author: cheikh
 */

#include "iSerre-SN.h"
#include "Xbee_Driver.h"

iSN_FrameCommand createCommandFrame(uint8_t commande) {

	iSN_FrameCommand isn_frame;
	isn_frame.frameType = iSN_FrameType_Command;

	isn_frame.command = commande;

	return isn_frame;
}

iSN_FrameMeasure createMeasureFrame(uint8_t *valeur) {
	iSN_FrameMeasure frame;
	frame.frameType = iSN_FrameType_Measure;
	for (int i = 0; i < 4; i++) {
		frame.measure[i] = valeur[i];
	}


	return frame;

}

void convertFloat2Buffer(const float f, uint8_t* buffer)
{
	for(int i = 0 ; i < sizeof(float) ; i++)
		buffer[i] = ((uint8_t*)&f)[i];
}

void convertBuffer2Float(const uint8_t* buffer, float* f)
{
	*f = *((float*)buffer);
}
