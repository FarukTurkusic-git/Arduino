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
void prazno(QueueArray <node> lista) {
  while (!lista.isEmpty ()) {
    //Serial.println("test33");
    lista.pop();
  }


};

QueueArray <node> wall;
QueueArray <node> neighbours;
QueueArray <node> list;
QueueArray <node> final_list;
QueueArray <node> trans;
QueueArray <node> trans2;
QueueArray <node> trans3;


node trenutna;
boolean check;
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
  //node path_list[35];
  //node matrix[7][5];


}
void loop() {
  node a, cilj;
  int k = -1;

  a.init(2, 1, 0);
  trenutna.init(1, 1, 0);
  cilj.init(6, 2, 0);
  list.push(trenutna);
  boolean prekid=false;

  while (!list.isEmpty ()) {
   QueueArray <node> testnalista;
    while (!final_list.isEmpty ()) {
      node med = final_list.pop(); testnalista.push(med);
      if (cilj.x == med.x && cilj.y == med.y ) {
        Serial.println("nasao cilj");
        prekid=true;
        break;
        }
    }
    while (!testnalista.isEmpty ()) {
      node med=testnalista.pop();  final_list.push(med);
    }
    if(prekid) break;

    
    k++;
    trenutna = list.pop();
    final_list.push(trenutna);

    //Serial.println(list.count());
    /////////// kreira lista celija komsija///////////
    neigh();
    Serial.println(neighbours.count());
    ///////// provjera uslova 1 za list //////////////
   
    
      delay(500);

    
  
    
    ////////////////////////////////////////////////////
    String tstring = "broj cvorova koji ce biti dodan :";
    tstring += neighbours.count();
    Serial.println(tstring);
    //////////////////////////////////////////////////////
    //korak 3: kopiranje komsija u listu cvorova/////////


    while (!neighbours.isEmpty ()) {
      node temp = neighbours.pop();
      if (temp.x < 100 && temp.y < 100 && temp.d < 100) {

        temp.ispis();
        temp.d = k + 1;
        trans.push(temp);
        list.push(temp);
        final_list.push(temp);

      }
    }
  while (!neighbours.isEmpty ()) {
   neighbours.pop();
 }
   String tstrin = "k :";
   tstrin += list.count();
   Serial.println(tstrin);
   ////////////////////////////////////////////////////
    String tstrin = "broj cvorova u listu :";
    tstrin += list.count();
    Serial.println(tstrin);
    //////////////////////////////////////////////////////
    
}
    Serial.println("kraj!");
  
  Serial.println(list.count());
  //Serial.println( a.d);
  while (1) {
    Serial.print("s");
    delay(2500);
  }
}
