void setup() {
  Serial.begin(9600);

}

void loop() {
  for(int a=0;a<10;a++){
    Serial.println(a);
    for(int b=0;b<10;b++){
    Serial.println(b);}
  }
while(1){}
}
