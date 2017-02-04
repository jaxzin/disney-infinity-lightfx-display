/*
 * ----------------------------------------------------------------------------
 * Disney Infinity Light FX/Skylanders Light Core Stand
 * ----------------------------------------------------------------------------
 * When used with a MFRC522 based RFID Reader on the Arduino SPI interface.
 * 
 * Requires the MFRC522 Arduino library found here: https://github.com/miguelbalboa/rfid
 * 
 */

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN		9		// 
#define SS_PIN		10		//

MFRC522 mfrc522(SS_PIN, RST_PIN);	// Create MFRC522 instance

void setup() {
	SPI.begin();			// Init SPI bus
	mfrc522.PCD_Init();		// Init MFRC522
}

void loop() {
  mfrc522.PCD_SetAntennaGain(01110000b);
  delay(1000);
}

