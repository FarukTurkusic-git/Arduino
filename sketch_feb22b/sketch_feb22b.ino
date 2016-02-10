#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);	// Create MFRC522 instance.

void setup() {
	Serial.begin(9600);	// Initialize serial communications with the PC
	SPI.begin();			// Init SPI bus
	mfrc522.PCD_Init();	// Init MFRC522 card
	Serial.println("Scan PICC to see UID and type...");
}
void loop() {
	// Look for new cards
	if ( ! mfrc522.PICC_IsNewCardPresent()) {
		return;
	}

	// Select one of the cards
	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
}
byte valueBlockA = 4;
byte value1Block[] = { 1,2,2,2, 3,3,4,4, 5,5,5,5, 6,6,6,6};
byte status = mfrc522.MIFARE_Write(valueBlockA, value1Block, 16);

if (status != MFRC522::STATUS_OK) {
  Serial.print("MIFARE_Write() failed: ");
  Serial.println(mfrc522.GetStatusCodeName(status));
	}

	// Dump debug info about the card. PICC_HaltA() is automatically called.
	mfrc522.PICC_DumpToSerial(&(mfrc522.uid));




}
