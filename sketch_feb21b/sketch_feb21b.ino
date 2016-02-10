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
// funkcija koja vrši upis u blokove kartice
for (int q=1;q<sizeof(buffer_polje);q+=3)
{
byte buffer_temp[4]={buffer_polje[q],buffer_polje[q+1],0,buffer_polje[q+2]};
byte status = mfrc522.MIFARE_Write(buffer_polje[q+2], buffer_temp,16);
}
}
}
if (Serial.available() > 0)
{
char c=Serial.read();
if(c=='w')
{
// za kontrolu šta je poslano , vraća primljene podatke
for(int i=0;i<sizeof(buffer_polje);i++)
{
Serial.write(buffer_polje[i]);
}
}
if(c =='P')
{
//primanje podataka
int bRead= Serial.readBytesUntil('q',buffer_polje,19);
}
}
}

