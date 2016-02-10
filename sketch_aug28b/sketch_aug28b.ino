#include <QueueArray.h>
using namespace std;

QueueArray <int> zero;
QueueArray <int> zero1;
QueueArray <int> zero2;

void prazno(QueueArray <int> lista1, QueueArray <int> lista2) {
  while (!lista1.isEmpty ()) {

    int temp = lista1.pop();
    lista2.push(temp);

    Serial.println(temp);
    delay(2500);

  };
}

void setup() {

  Serial.begin(9600);


}

void loop() {
  for(int a =0; a<4;a++){
    int v= random(10);
    zero.push(v);
    Serial.println(v);
  }

  Serial.println(zero.count());

  //prazno(zero, zero1);
  while (!zero.isEmpty ()) {
    zero1.push(zero.pop());
  }
  delay(2500);
  Serial.println(zero.count());
  Serial.println(zero1.count());

  delay(2500);
  Serial.println("/////////////////////////////////7");
}
