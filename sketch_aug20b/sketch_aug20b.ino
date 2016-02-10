#include <QueueArray.h>


QueueArray <int> trans;
QueueArray <int> trans2;
QueueArray <int> zero;



void setup() {
  Serial.begin(9600);

}

void loop() {
  trans.push(1);
  trans.push(2);
  trans.push(3);
  trans.push(4);
  Serial.println(trans.count());
  Serial.println("--------------------------");
  int c=trans.count();
   for (int k = 0; k < c; k++) {
     int a = trans.dequeue();
     Serial.println(a);
     trans2.push(a);
   }

   Serial.println(trans2.count());
   trans2=zero;
   Serial.println(trans2.count());
   
while(true){}
}
