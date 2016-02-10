int cvorovi[10];
byte sizee=10;
void buble_sort()
      {
         Serial.println("sort");
          int i,j;
     
          for(i=0; i<(sizee-1); i++)
          {
              for(j=0; j<(sizee-(i+1)); j++)
              {
                  {
                      if(cvorovi[j] > cvorovi[j+1]){ 
                          //Serial.println(cvorovi[j]); 
                          //Serial.println(cvorovi[j+1]);   
                         
                          int temp=cvorovi[j];
                          cvorovi[j]=cvorovi[j+1];
                          cvorovi[j+1]=temp;
                          //Serial.println(cvorovi[j]); 
                          //Serial.println(cvorovi[j+1]); 
                      }
                          
                  }
       
              }
          }
      }
void setup() {
 Serial.begin(9600);

 byte sizee = sizeof(cvorovi);
  
}

void loop() {
   cvorovi[0]= random(20);
 cvorovi[1]= random(20);
 cvorovi[2]= random(20);
 cvorovi[3]= random(20);
 cvorovi[4]= random(20);
 cvorovi[5]= random(20);
 cvorovi[6]= random(20);
 cvorovi[7]= random(20);
  Serial.println( "");
  for(int c=0;c<sizee;c++){
    Serial.print(cvorovi[c]);
    Serial.print(":");
    delay(1500);
   }
  Serial.println( "");
  buble_sort();
  for(int c=0;c<sizee;c++){
    Serial.print(cvorovi[c]);
    Serial.print(":");
    delay(1500);
   }

}
