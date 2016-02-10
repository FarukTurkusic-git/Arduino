#include <StackArray.h>
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
    void ispis(){
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
int  search() {
  node a;
  return 0;
};
StackArray <node> wall;
StackArray <node> neighbours;
StackArray <node> list;
StackArray <node> trans;
StackArray <node> trans2;
StackArray <node> zero;
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
  node path_list[35];
  node matrix[7][5];

}
void loop() {
  node a, cilj;
  boolean prekid = false;
  a.init(2, 1, 0);
  trenutna.init(1, 1, 0);
  cilj.init(5, 1, 0);
  list.push(trenutna);
  for (int k = 0; k < list.count(); k++) {
    Serial.println(k);
    Serial.println(list.count());
    /////////// kreira lista celija komsija///////////
    neigh();
    Serial.println(neighbours.count());
    ///////// provjera uslova 1 za list //////////////
    for (int n = 0; n < list.count(); n++) {
      node temp = list.pop();
      temp.ispis();
      boolean check = true;
      for (int m = 0; m < wall.count(); m++) {
        node temp2 = wall.pop();
        ////////////////////// uslov 1: ako je komsija zid izbaci iz komsija ///////
        if (temp.x == temp2.x && temp.y == temp2.y) check = false;
        trans2.push(temp2);
      }
      if(check) trans.push(temp);
    }
    //////// vrati list bez izbacenih elemetata i wall ne izmjenjen/////
    list = trans;
    wall = trans2;
    trans = zero;
    trans2 = zero;
    ///////// provjera uslova 1 za neighbours //////////////
    for (int x = 0; x < neighbours.count(); x++) {
      node temp = neighbours.pop();
      boolean check = true;
      for (int y = 0; y < wall.count(); y++) {
        node temp2 = wall.pop();
        ////////////////////// uslov 1: ako je komsija zid izbaci iz komsija ///////
        if (temp.x == temp2.x && temp.y == temp2.y) check = false;
        trans2.push(temp2);
      }
      if (check) trans.push(temp);
    }

    //////// vrati list bez izbacenih elemetata i wall ne izmjenjen/////
    neighbours = trans;
    wall = trans2;
    trans = zero;
    trans2 = zero;
        ////////////////////////////////////////////////////
String ttstring= "broj cvorova komsija posle uslova 1 :";
ttstring+= neighbours.count();
Serial.println(ttstring);
//////////////////////////////////////////////////////
    ///////// uslov 2:  ako je u main listi cvor sa istim koordinatama a vecom distancom ili jednakom izbaci///
    for (int c = 0; c < neighbours.count(); c++) {
      node temp = neighbours.pop();
      boolean check = true;
      for (int d = 0; d < list.count(); d++) {
        node temp2 = list.pop();
        ////////////////////// uslov 1: ako je komsija zid izbaci iz komsija ///////
        if (temp.x == temp2.x && temp.y == temp2.y && temp.d <= temp2.d)
          check = false;
        trans.push(temp2);
      }
      if (check) trans2.push(temp);
    }
    list = trans;
    neighbours = trans2;

    trans2 = zero;
    trans = zero;
    ////////////////////////////////////////////////////
    String tstring= "broj cvorova koji ce biti dodan :";
    tstring+= neighbours.count();
    Serial.println(tstring);
    //////////////////////////////////////////////////////
    //korak 3: kopiranje komsija u listu cvorova/////////
    for (int n = 0; n < neighbours.count(); n++) {
      node temp = neighbours.pop();
      temp.d = k+1;
        trans.push(temp);
      list.push(temp);
      if (temp.x == cilj.x && temp.y == cilj.y ) prekid = true;
        temp.ispis();
      }
    neighbours = zero;
    trans = zero;
    trans2=zero;
    //if (prekid) break;
  }

  //Serial.println( a.d);
  exit(0);
}
