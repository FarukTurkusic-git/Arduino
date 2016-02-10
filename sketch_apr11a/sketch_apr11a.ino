#include <SPI.h> // biblioteka za komunikaciju
#include <MFRC522.h> // biblioteka za rad sa karticama
#include <EEPROMex.h> // biblioteka sa rad sa EEPROM memorijom
#include <Servo.h> // biblioteka za rad sa servo motorima
// kreiramo dva objekta tipa servo , jedan će nam
// predstavljati desni a drugi lijevi motor
Servo servoLijevi;
Servo servoDesni;
// definišemo pinove potrebne za RC522 čitač
#define SS_PIN 10
#define RST_PIN 9
// kreiramo nizove podataka koji će nam biti potrebni
// za adekvatnu pohranu podataka
byte buffer_preuzimanje_cilj[5]={0};
byte buffer_cilj_temp[2]={0};
byte buffer_prenos_temp[49]={0};
// za lakši rad koristit ćemo strukturu čvor koja se
// sastoji od :
// polja koordinate x ose , polja koordinate y ose , te
// polja težine prelaza potrebnih za proračun
struct cvor{
    byte x=0;
    byte y=0;
            };
// kreiramo strukturu cilj gdje ćemo smjestiti ciljne
// koordinate
cvor cilj;
// pomoćne strukture za rad sa podacima
cvor trenutna;
// odredjuje smjer kojim se krece, za kretanje ka cilju "true", od cilja "false"
bool smjer = true;



// za rad sa EEPROM memorijom potrebne su nam adrese
// gdje ćemo ih smjestiti
int address_cilj=0;
int address_putanja=200;

byte i=1;
byte j=0;
byte temp_smijer=0;


MFRC522 mfrc522(SS_PIN, RST_PIN);

// dio koda koji se samo jednom odradi na početku
// izvršenja koda
void setup()
{
// postavimo bit-rate
Serial.begin(9600);
// uspostavimo komunikaciju
SPI.begin();
// inicijaliziramo mfrc
mfrc522.PCD_Init();
// učitamo strukturu cilj iz memorije
ucitaj_cilj();
}

// petlja
void loop()
{
// ukoliko je kartica prisutna
if ( mfrc522.PICC_IsNewCardPresent())
{
// ukoliko je validna (može se uspješno pročitati i
// identificirati)
    if ( mfrc522.PICC_ReadCardSerial())
    {
// funkcija koja pročita trenutnu karticu
// smjesti podatke smjerova u adekvatne cvorove
// za proračun je potreban broj koraka , to je riješeno
// proslijeđivanjem običnog brojača
      ucitavanje_proracun_sa_kartice(i);
      delay(200);
// provjeravamo da li su koordinate trenutne kartice
// jednake koordinatama cilja
      if (cilj.x==trenutna.x && cilj.y==trenutna.y)
       {
// snimanje koordinata trenutne kartice u zatvorenu
// listu ( obični niz ) koja čini putanju
          snimi_trenutnu_u_zatvorenu(i-1);
          delay(200);
        }
      else
      {
        delay(200);

        if (trenutna.y < cilj.y)
        {
          kretanje();      
            delay(200);

         }
         else 
         {
           if(trenutna.x > 0)
           {
             okret_desno();
           }
           else 
           {
             okret_lijevo();
           }
         }
         }
     }
         
          




// ukoliko je primljena komanda preko porta
          if (Serial.available() > 0)
          {
// pročitamo primljeno
          char c=Serial.read();
// na ovu komandu vrši se preuzimanje podataka
// u ovom slučaju koordinata cilja
// i snimanje u EEPROM memoriju
          if(c=='E')
          {
            int bRead= Serial.readBytesUntil('q',buffer_preuzimanje_cilj,10);
            EEPROM.writeBlock(address_cilj,buffer_preuzimanje_cilj);
          }
// na ovu komandu vršimo čitanje podataka iz
// EEPROM memorije
// i njihovo spremanje u adekvatne strukture
          if(c=='X')
          {
            EEPROM.readBlock( address_cilj,buffer_cilj_temp,5);
            cilj.x =buffer_cilj_temp[1];
            Serial.write(cilj.x);
            cilj.y =buffer_cilj_temp[2];
          }
// komanda za slanje podataka iz zatvorene liste
          if(c=='Z')
          {
            for (byte i=0;i<48;i++)
            {
                if (zatvorena[i].x!=0 && zatvorena[i].y!=0)
                {
                  Serial.write(zatvorena[i].x);
                  Serial.write(zatvorena[i].y);
                }

           }
        }
// komanda za slanje podataka iz otvorene liste
         if(c=='O')
          {
            for (byte i=0;i<48;i++)
              {
               if(otvorena[i].x!=0 && otvorena[i].y!=0)
               {
                 Serial.write(otvorena[i].x);
                 Serial.write(otvorena[i].y);
                }
               }
            }
           }
           }
   }
// funkcija koja na početku programa učita
// koordinate cilja
    void ucitaj_cilj()
    {
      EEPROM.readBlock(address_cilj,buffer_cilj_temp,5);
      cilj.x =buffer_cilj_temp[1];
      cilj.y =buffer_cilj_temp[2];

    }

    void ucitavanje_proracun_sa_kartice(int i)
    {
// buffer u koji smještamo podatke
    byte buffer[18];
    byte size = sizeof(buffer);
// za trenutnu samo se vrši čitanje, bez proračuna
// funkcija koja vrši čitanje podataka
// prvi parametar (koji blok treba pročitati)
// drugi parametar (gdje smjestiti pročitane
// podatke)
// smještamo podatke u adekvatne strukture
    byte status5 = mfrc522.MIFARE_Read(5, buffer, &size);
    trenutna.x=buffer[0];
    trenutna.y=buffer[1];
}
// funkcija određivanja : da li je koja
// koordinata nula
bool nije_nula(byte a, byte b)
{
  if (a==0 || b==0)
  {
    return false ;
  }
  else
  {
    return true;
  }
}

// izvršavanje okreta
void okret_lijevo()
{
// dodijelimo pinove servomotorima
servoLijevi.attach(3);
servoDesni.attach(2);
// koliko dugo dajemo impuls
servoLijevi.writeMicroseconds(1300);
servoDesni.writeMicroseconds(1300);
delay(495);
// nakon izvršenja oduzmemo pinove od
// servomotora
servoLijevi.detach();
servoDesni.detach();
}
void okret_desno()
{
servoLijevi.attach(3);
servoDesni.attach(2);
servoLijevi.writeMicroseconds(1700);
servoDesni.writeMicroseconds(1700);
delay(495);
servoLijevi.detach();
servoDesni.detach();
}
96
void okret_dole()
{
servoLijevi.attach(3);
servoDesni.attach(2);
servoLijevi.writeMicroseconds(1300);
servoDesni.writeMicroseconds(1300);
delay(2*590);
servoLijevi.detach();
servoDesni.detach();
}
// funkcija kretnje robota poslije
// odrađenog okreta
void kretanje()
{
servoLijevi.attach(3);
servoDesni.attach(2);
servoLijevi.writeMicroseconds(1700);
servoDesni.writeMicroseconds(1300);
delay(700);
servoLijevi.detach();
servoDesni.detach();
}

