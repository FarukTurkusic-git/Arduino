#include <SPI.h> // biblioteka za komunikaciju
#include <MFRC522.h> // biblioteka za rad sa karticama

byte buffer_cilj[10]={};
 char incomingByte;
 int integerValue;

void setup() {
  Serial.begin(9600);
  SPI.begin();
}

void loop() {
     
      if(Serial.available() > 0) integerValue = 0;
  while(1){
      incomingByte = Serial.read();
      if(incomingByte == '\n') break;
      integerValue = (incomingByte - 48) + integerValue;
          }
          
       Serial.println(integerValue);

          
}
