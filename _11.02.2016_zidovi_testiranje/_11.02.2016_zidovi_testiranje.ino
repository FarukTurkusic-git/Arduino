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
void prazni(QueueArray <node> &lista) {
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

void neigh(node kom = trenutna) {
  node u = kom;
  u.x = u.x + 1;
  neighbours.push(u);
  node d = kom;
  d.x = d.x - 1;
  neighbours.push(d);
  node r = kom;
  r.y = r.y + 1;
  neighbours.push(r);
  node l = kom;
  l.y = l.y - 1;
  neighbours.push(l);
};
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
  
  a.init(2, 1, 0);
  trenutna.init(1, 1, 0);
  cilj.init(3, 1, 0);
  zid.init(2,1,0);
  
  list.push(trenutna);
  trenutna.ispis();

   
    while (!list.isEmpty ()){
        
        k++;
        if(k>4) break;
        
        node temp = list.pop();
        temp.x = 4;
        neigh();
      
        Serial.print("broj komsija :");
        Serial.println(neighbours.count());
        Serial.print("broj u listi :");
        Serial.println(list.count());
        
        
         while (!neighbours.isEmpty ()) {
          node med = neighbours.pop();
          med.ispis();
        }
        
        while(1){}
        
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
