#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); // Kreiranje MFRC522 instance.
void setup()
{
Serial.begin(9600); // Inicijalizacija serijske komunikacije.
SPI.begin(); // Inicijalizacija SPI bus-a.
mfrc522.PCD_Init(); // Inicijalizacija MFRC522 kartice.
Serial.println("Uspješno učitana kartica : ");
}
void loop()
{
if ( ! mfrc522.PICC_IsNewCardPresent()) // Traži novu karticu
{
return;
}
if ( ! mfrc522.PICC_ReadCardSerial()) // Selektovanje kartice.
{
return;
}

mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}

