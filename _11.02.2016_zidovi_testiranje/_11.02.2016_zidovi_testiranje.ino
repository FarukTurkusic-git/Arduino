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

void prebaci(QueueArray <node> &lista1,QueueArray <node> &lista2) {
  while (!lista1.isEmpty ()) {
    //Serial.println("test33");
    node tra = lista1.pop();
    lista2.push(tra);
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
  trenutna.init(2, 1, 0);
  cilj.init(3, 2, 0);
  zid.init(6,1,0);
  
  list.push(trenutna);
  trenutna.ispis();
  final_list.push(trenutna);

   
    while (!list.isEmpty ()){
        
        k++;
        //if(k>4) break;
        node temp = list.pop();
        temp.ispis();
        
        if (cilj.x == temp.x && cilj.y == temp.y) {
          Serial.println("nasao Cilj !!!");
          break;
        }
        
        neigh(temp);
      
        Serial.print("broj komsija :");
        Serial.println(neighbours.count());
        Serial.print("broj u listi :");
        Serial.println(list.count());
        
        
        //while (!neighbours.isEmpty ()) {
        //  node med = neighbours.pop();
        //  med.ispis();
        //}
        prazni(trans);
        prazni(trans2);
        
       /* 
       int broj = neighbours.count();
        
       while (!neighbours.isEmpty ()) {
         node temp = neighbours.dequeue();
         Serial.println(neighbours.count());
         temp.ispis();
       }
       
        Serial.println(neighbours.count());

        while(1){} */
        
        while (!neighbours.isEmpty ()) {
          node temp1 = neighbours.dequeue();
          temp1.d = temp.d+1;
          temp1.ispis();
          check = true;
          while (!wall.isEmpty ()) {
            node temp2 = wall.dequeue();
            ////////////////////// uslov 1: ako je komsija zid izbaci iz komsija ///////
            if (temp1.x == temp2.x && temp1.y == temp2.y) {
              check = false;
              Serial.println("nasao ZID");
            }
            trans2.push(temp2);
          }
          if(check) trans.push(temp1);
          prebaci(trans2,wall);
          prazni(trans2);
          
        }
        
        prebaci(trans,list);
        //prebaci(trans2,wall);
        prazni(neighbours);
        prazni(trans);
        prazni(trans2);
        
        Serial.print("broj komsija :");
        Serial.println(neighbours.count());
        Serial.print("broj u listi :");
        Serial.println(list.count());
         /*while(k>20){
           Serial.println("usao u petlju");
         } */
}
  while(1){}
}
