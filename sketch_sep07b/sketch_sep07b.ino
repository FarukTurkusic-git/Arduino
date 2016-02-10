#include <QueueArray.h>
using namespace std;
class node {
  public:
    int x = 0;
    int y = 0;
    int d = 0;
    void init(int a, int b, int c) {
      x = a;
      y = b;
      d = c;
    }
    void ispis() {
      String izlaz = "(";
      izlaz += x;
      izlaz += ".";
      izlaz += y;
      izlaz += ".";
      izlaz += d;
      izlaz += ")";
      Serial.println(izlaz);
    }

};

QueueArray <node> zero;
QueueArray <node> zero1;
QueueArray <node> zero2;
QueueArray <node> neighbours;
node trenutna;

void neigh() {
  node u = trenutna;
  u.x = u.x + 1;
  neighbours.push(u);
  node d = trenutna;
  d.x = d.x - 1;
  neighbours.push(d);
  node r = trenutna;
  r.y = r.y + 1;
  neighbours.push(r);
  node l = trenutna;
  l.y = l.y - 1;
  neighbours.push(l);
}
void setup() {

  Serial.begin(9600);


}

void loop() {
  trenutna.init(1, 1, 0);
  neigh();
  int a= neighbours.count();
  Serial.println(a);
  delay(2500);
    while (!neighbours.isEmpty ()) {
    neighbours.pop();}
  a= neighbours.count();
  Serial.println(a);
  Serial.println("/////////////////////////////////7");
}
