#define INPUT_SIZE 30
#include <SPI.h> // biblioteka za komunikaciju
#include <MFRC522.h> // biblioteka za rad sa karticama
//#include <EEPROMex.h> // biblioteka sa rad sa EEPROM memorijom
#include <Servo.h> // biblioteka za rad sa servo motorima
// kreiramo dva objekta tipa servo , jedan će nam
// predstavljati desni a drugi lijevi motor
Servo servoLijevi;
Servo servoDesni;
// definišemo pinove potrebne za RC522 čitač
#define SS_PIN 10
#define RST_PIN 9
byte sizee;
int i=0,z=0;


struct cvor
{
   int x;
   int y;
   double dist=0;
};

cvor trenutna,pocetna,cilj;
cvor cvorovi[35];
int pomjeraj_x,pomjeraj_y;

void distanca(){
      for(int j=0; j < i; j++ ){
        cvor a =cvorovi[j];
        a.dist=sqrt( pow(trenutna.x-a.x,2)+ pow(trenutna.y-a.y,2));
        cvorovi[j]=a;
        Serial.println(a.dist);
        }}
        
void buble_sort()
      {
         Serial.println("sort");
          int p,l;
       
          for(p=0; p<(i-1); p++)
          {
              for(l=0; l<(i-(p+1)); l++)
              {
                  {
                      if(cvorovi[l].dist > cvorovi[l+1].dist){ 
                        Serial.println("RADI KONACNO");
                          //Serial.println(cvorovi[j]); 
                          //Serial.println(cvorovi[j+1]);    
                         
                          cvor temp=cvorovi[l];
                          cvorovi[l]=cvorovi[l+1];
                          cvorovi[l+1]=temp;
                          //Serial.println(cvorovi[j]); 
                          //Serial.println(cvorovi[j+1]); 
                      }
                          
                  }
       
              }
          }
      }
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

void setup() 
{
    Serial.begin(9600);
    trenutna.x=0;
    trenutna.y=1;
    
    z=0;
}
  


void loop() 
{
  if(Serial.available()>0 ){
  ////////// popunjavanje vektora cvorova///////////////
     char input[INPUT_SIZE + 1];
     byte sizee = Serial.readBytes(input, INPUT_SIZE);
     input[sizee] = 0;
     Serial.println(input);
     Serial.println(sizee);
    // cvor cvorovi[35];
     i=0;

  char* command = strtok(input, ":");
    while (command != 0)
    {
        // Split the command in two values
        char* separator = strchr(command, '.');
        if (separator != 0)
        {
            // Actually split the string in 2: replace ':' with 0
            *separator = 0;
            int servoId = atoi(command);
            ++separator;
            int position = atoi(separator);
            //uvacivanje u kontejner cvorova
            
            cvor var;
            var.x=servoId;
            var.y=position;
            
            //cvor var=f(servoId,position);
            cvorovi[i]=var;
            i++;
            //Serial.println(servoId);
            //Serial.println(position); 

            // Do something with servoId and position
        }
        // Find the next command in input string
        command = strtok(0, ":");
    }
   
 ////////////////////////////////////////////////////////////
 /////////////// sortiranje vektora //////////////////////////
 

        /*
        Serial.print(a.x);
        Serial.print(".");
        Serial.print(a.y);
        
        
        String stringOne = "A long integer: ";
        stringOne += 123456789;
        char charBuf[50];
        stringOne.toCharArray(charBuf, 50);
        Serial.println(charBuf);
        */
        
/////////////////////////////////////////////////////////////////
     distanca();
     buble_sort();
    
    for(int j=0; j < i; j++ ){
       
        cvor a =cvorovi[j];
        Serial.println(a.dist);
        delay(1000);
      }
    //exit(0);
    //Serial.println();
    for(int c=0;c<i;c++){
      cilj=cvorovi[c];
      ///////////// pomjeranje po x osi /////////////////
      pomjeraj_x=cilj.x-trenutna.x;
      if(pomjeraj_x!=0){
      while(pomjeraj_x>0){
        Serial.print(pomjeraj_x);
        pomjeraj_x--;
        delay(1000);
      //okret_desno()
      }
      Serial.println("");
      while(pomjeraj_x<0) {
        Serial.print(pomjeraj_x);
        pomjeraj_x++;
        delay(1000);
        //okret__lijevo();
      }
      Serial.println("");
      }
      ///////////// pomjeranje po y osi /////////////////
      pomjeraj_y=cilj.y-trenutna.y;
      if(pomjeraj_y!=0){
          while(pomjeraj_y>0){
         Serial.print(pomjeraj_y);
          pomjeraj_y--;
        delay(1000);
      //kreatanje();
      }
      Serial.println("");
      while(pomjeraj_y<0) {
        Serial.print(pomjeraj_y);
         pomjeraj_y++;
        delay(1000);
        //okret_dole();
      }
      }
      Serial.println("");
      trenutna=cilj;
      
      
      }
 
      }
      }
