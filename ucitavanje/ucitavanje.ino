/* Simple Serial ECHO script : Written by ScottC 04/07/2012 */
/* Stage 2 : Delimiters */

/* Use a variable called byteRead to temporarily store
   the data coming from the computer */
int byteRead[20];
int i=0;


void setup() {                
// Turn the Serial Protocol ON
  Serial.begin(9600);
}

void loop() {
  
   /*  check if data has been sent from the computer: */
  while (Serial.available()) {
    i++;
    Serial.print("t");
    delay(1000);
    /* read the most recent byte */
    byteRead[i] = Serial.read();
    }
    /*Listen for a comma which equals byte code # 44 /
    if(byteRead==44){
      Serial.println();
    }else
      ECHO the value that was read, back to the serial port. */
      for(int j=0;j<=10;j++){
       Serial.write(byteRead[j]);
       //Serial.print("n");
      }
    
  
}
