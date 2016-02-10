#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
byte buffer_polje[16]={};
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.
void setup()
{
Serial.begin(9600); // Initialize serial communications with the PC
SPI.begin(); // Init SPI bus
mfrc522.PCD_Init(); // Init MFRC522 card
}
void loop()
{
if ( mfrc522.PICC_IsNewCardPresent())
{
if ( mfrc522.PICC_ReadCardSerial())
{
if(char c = Serial.read())
{Serial.println(c);}
delay(1200);
//Serial.write(c);


}
}
}
