#include <SPI.h> // biblioteka za komunikaciju
#include <MFRC522.h> // biblioteka za rad sa karticama

int recdata[3];
int bytes = 0;

void setup() {
  Serial.begin(9600);
  SPI.begin();


}
void loop() {
      if (Serial.available() > 0)
      {     
            while(Serial.available())
            {
              recdata[bytes]=Serial.read();
              bytes++;
            }
            if (bytes >= 3)
            {
              //checkdata(); //function which checks the received data
                       for(int temp=0;temp<=3;temp++)
                           {
                                  Serial.println(recdata[temp]);
                            }
              bytes = 0;
            }
      }
}
