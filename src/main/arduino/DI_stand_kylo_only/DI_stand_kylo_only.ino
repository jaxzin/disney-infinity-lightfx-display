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
#define KYLO_RST_PIN    12   // 
#define KYLO_PIN    11    //


MFRC522 jedi(SS_PIN, RST_PIN);  // Create MFRC522 instance
MFRC522 kylo(KYLO_PIN, KYLO_RST_PIN);  // Create MFRC522 instance

void setup() {
	SPI.begin();			// Init SPI bus
  jedi.PCD_Init();   // Init MFRC522
  kylo.PCD_Init();   // Init MFRC522
}

boolean antennaState = true;
void loop() {

  antennaState ? kylo.PCD_AntennaOn() : kylo.PCD_AntennaOff();
  antennaState = !antennaState;
  
  delay(random(20,150));
}

