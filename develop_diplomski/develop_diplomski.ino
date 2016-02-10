void setup() 
{
    Serial.begin(9600);
}

char buffer[64];
char *p = buffer;

void loop() 
{
    char ch = ' ';
    while (Serial.available() > 0)
    {
       ch = Serial.read();
       *p++ = ch;    

       if (ch == 'k')
       {
         *p = 0;
         Serial.print("got ");
         Serial.println(buffer);      
         p = buffer;
         break;
      }
   }
 }
