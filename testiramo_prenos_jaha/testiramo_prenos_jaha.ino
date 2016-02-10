#include <SPI.h> // biblioteka za komunikaciju
#include <MFRC522.h> // biblioteka za rad sa karticama

#include <Servo.h> 

byte buffer_cilj[10]={};


void setup() {
  Serial.begin(9600);
  SPI.begin();


}

void loop() {
     if (Serial.available() > 0)
          {
// pročitamo primljeno
          char c=Serial.read();
           if(c=='E')
          {
            int bRead= Serial.readBytesUntil('q',buffer_cilj,10);
          }
          if(c=='p')
          {
           for(int temp=0;temp<10;temp++)
            {
              Serial.println(buffer_cilj[temp]);
            }
          }
          }
}
