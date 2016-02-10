char inData[20]; // Allocate some space for the string
char inChar=-1; // Where to store the character read
byte index = 0; // Index into array; where to store the character

void setup() {
    Serial.begin(9600);
    Serial.write("Power On");
}

void loop() {
  
  while (Serial.available() > 0) // Don't read unless
                                   // there you know there is data
    {   char znak  = Serial.read();
        char kraj = 'k';
        if(znak != kraj) // One less than the size of the array
        {
            //inChar = Serial.read(); // Read a character
            inData[index] = znak; // Store it
            index++; // Increment where to write next
            //inData[index] = '\0'; // Null terminate the string
        }
        Serial.end();
    }
    Serial.write(inData);
    

}
