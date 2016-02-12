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
  node zid;
  for(int a = -1 ; a<7; a++ ){
      zid.init(a,-1,0);
      wall.push(zid);     
  }
  for(int a = -1 ; a<7; a++ ){
      zid.init(a,6,0);
      wall.push(zid);     
  }
  for(int a =  -1; a<7; a++ ){
      zid.init(8,a,0);
      wall.push(zid);     
  }
  for(int a = -1; a<7; a++ ){
      zid.init(-1,a,0);
      wall.push(zid);     
  }


}
void loop() {
  node a, cilj,zid;
  int k = -1;
  
  int p = wall.count();
  Serial.println(p);
  
  while (!wall.isEmpty ()) {
          node med = wall.pop(); list.push(med);
          med.ispis();
        }
  
  while(1){};
  
  a.init(2, 1, 0);
  trenutna.init(1, 1, 0);
  cilj.init(3, 1, 0);
  zid.init(2,1,0);
  
  list.push(trenutna);
  trenutna.ispis();

   
    while (k<2){
        neigh();
        k++;
      
        Serial.print("broj komsija :");
        Serial.println(neighbours.count());
        Serial.print("broj u listi :");
        Serial.println(list.count());
        
        int t= neighbours.count();
        
        while (!neighbours.isEmpty ()) {
          node med = neighbours.pop(); list.push(med);
        }
        
        Serial.print("broj komsija :");
        Serial.println(neighbours.count());
        Serial.print("broj u listi :");
        Serial.println(list.count());
}
  while(1){}
}
