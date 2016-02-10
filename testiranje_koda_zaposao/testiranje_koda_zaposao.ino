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
         //Serial.println("sort");
          int i,j;
     
          for(i=0; i<(sizee-1); i++)
          {
              for(j=0; j<(sizee-(i+1)); j++)
              {
                  {
                      if(cvorovi[j].dist > cvorovi[j+1].dist){ 
                          Serial.println(cvorovi[j].dist); 
                          Serial.println(cvorovi[j+1].dist);   
                         
                          cvor temp=cvorovi[j];
                          cvorovi[j]=cvorovi[j+1];
                          cvorovi[j+1]=temp;
                          Serial.println(cvorovi[j].dist); 
                          Serial.println(cvorovi[j+1].dist); 
                      }
                          
                  }
       
              }
          }
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
   }
 ////////////////////////////////////////////////////////////
 /////////////// sortiranje vektora //////////////////////////
/////////////////////////////////////////////////////////////////
     distanca();
     buble_sort();
    
    for(int j=0; j < i; j++ ){
       
        cvor a =cvorovi[j];
        Serial.println(a.dist);}
    
   
      
      }
