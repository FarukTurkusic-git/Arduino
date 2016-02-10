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
  cilj.init(5, 1, 0);
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
    node trenutna = list.pop();
    final_list.push(trenutna);

    Serial.println(k);
    //Serial.println(list.count());
    /////////// kreira lista celija komsija///////////
    neigh();
    Serial.println(neighbours.count());
    Serial.println("pocetak test je potreban");
    Serial.print(list.count());
    ///////// provjera uslova 1 za list //////////////
    for (int n = 0; n < list.count(); n++) {
      node temp = list.dequeue();
      temp.ispis();
      check = true;
      for (int m = 0; m < wall.count(); m++) {
        node temp2 = wall.dequeue();
        ////////////////////// uslov 1: ako je komsija zid izbaci iz komsija ///////
        if (temp.x == temp2.x && temp.y == temp2.y) check = false;
        trans2.push(temp2);         // wall nova
      }
      if (check) trans.push(temp);  // lista nova
    }

    //////// vrati list bez izbacenih elemetata i wall ne izmjenjen/////
    while (!list.isEmpty ()) {
     list.pop();
    }
    while (!trans.isEmpty ()) {
      node med = trans.pop(); list.push(med);
    }

    while (!wall.isEmpty ()) {
     wall.pop();
    }
    while (!trans2.isEmpty ()) {
      node med = trans2.pop(); wall.push(med);
    }
    while (!trans.isEmpty ()) {
     trans.pop();
    }
    while (!trans2.isEmpty ()) {
     trans2.pop();
    }
    Serial.println("testiranje u toku");
    ///////// provjera uslova 1 za neighbours //////////////
    int tajmer = neighbours.count();
    for (int x = 0; x < tajmer; x++) {

      node temp = neighbours.dequeue();
      check = true;
      for (int y = 0; y < wall.count(); y++) {
        node temp2 = wall.dequeue();
        temp2.ispis();
        ////////////////////// uslov 1: ako je komsija zid izbaci iz komsija ///////
        if (temp.x == temp2.x && temp.y == temp2.y) check = false;
        trans2.push(temp2);  // wall novi
      }
      if (check) trans.push(temp); // neighbours novi
    }

    //////// vrati list bez izbacenih elemetata i wall ne izmjenjen/////
     while (!neighbours.isEmpty ()) {
      neighbours.pop(); 
    }
     while (!trans.isEmpty ()) {
      node med = trans.pop(); neighbours.push(med);
    }
     while (!wall.isEmpty ()) {
      wall.pop(); 
    }
     while (!trans2.isEmpty ()) {
      node med = trans2.pop(); wall.push(med);
    }
 
    //trans = zero;
    //trans2 = zero; 

    delay(500);
   
    ///////// uslov 2:  ako je u main listi cvor sa istim koordinatama a vecom distancom ili jednakom izbaci///
    int tajmer1 = neighbours.count();
    Serial.println(tajmer1);
    int tajmer2 = list.count ();
    Serial.println(tajmer2);


    for (int c = 0; c < tajmer1; c++) {
      node temp = neighbours.dequeue();
      Serial.println(neighbours.count());
      boolean check1 = true;
      QueueArray <node> trans4;
      temp.ispis();
      for (int d = 0; d < tajmer2; d++) {
        node temp2 = list.dequeue();
        temp2.ispis();
        delay(500);
        Serial.println("proslo provjeru2");
        ////////////////////// uslov 1: ako je komsija zid izbaci iz komsija ///////
        if (temp.x == temp2.x && temp.y == temp2.y && temp.d <= temp2.d) check1 = false;

        trans4.push(temp2);
        delay(500);
      }

      //list = trans4;
       while (!list.isEmpty ()) {
         list.pop();
       }
    
       while (!trans4.isEmpty ()) {
         node tre=trans4.pop(); list.push(tre);
       }
    Serial.println("dovde sam stigao, test1 je potreban");
    Serial.println(list.count());
      //trans4=zero;
      //prazno(trans4);
      if (check1) trans3.push(temp);
    
      delay(500);


    }

    delay(500);
    Serial.println("ispod");
   // neighbours = trans3;
     while (!neighbours.isEmpty ()) {
       neighbours.pop();
     }
     while (!trans3.isEmpty ()) {
         node tre=trans3.pop();  neighbours.push(tre);
     }
    
    

   // prazno(trans3);
    
    while (!trans3.isEmpty ()) {
       trans3.pop();
     }
    //prazno(neighbours);

    ////////////////////////////////////////////////////
    String tstring = "broj cvorova koji ce biti dodan :";
    tstring += neighbours.count();
    Serial.println(tstring);
    //////////////////////////////////////////////////////
    //korak 3: kopiranje komsija u listu cvorova/////////


    while (!neighbours.isEmpty ()) {
      node temp = neighbours.pop();
      if (temp.x < 100 && temp.y < 100 && temp.d < 100) {

        //temp.ispis();
        temp.d = k + 1;
        trans.push(temp);
        list.push(temp);
        final_list.push(temp);

      }
    }
  while (!neighbours.isEmpty ()) {
   neighbours.pop();
 }
    

    Serial.println("kraj!");
  }
  Serial.println(list.count());
  //Serial.println( a.d);
  while (1) {
    Serial.print("s");
    delay(2500);
  }
}
