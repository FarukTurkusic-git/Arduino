#include <StackArray.h>

using namespace std;

class node{
  public:
    int x=0;
    int y=0;
    int d=0;
    void init(int a,int b,int c) {
      x=a;
      y=b;
      d=c;
 
    }
    
};
int  search(){
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

void neigh(){
  node u=trenutna;
  u.x=u.x+1;
  neighbours.push(u);
  
  node d=trenutna;
  d.x=d.x-1;
  neighbours.push(d);
  
  node r=trenutna;
  r.y=r.y+1;
  neighbours.push(r);
  
  node l=trenutna;
  l.y=l.y-1;
  neighbours.push(l);
}

void setup() {
  Serial.begin(9600);
  node path_list[35];

  
  node matrix[7][5];
  

}


void loop() {
  
  node a;
  a.init(2,1,0);
  
  trenutna.init(1,1,0);
  list.push(trenutna);
  /////////// kreira lista celija komsija///////////
  neigh();
  //kopiranje komsija u listu cvorova/////////
  for(int n=0;n<neighbours.count();n++){
    node temp=neighbours.pop();
    trans.push(temp);
    list.push(temp);
    }
    neighbours=trans;
    trans=zero;

  ///////// provjera uslova //////////////
  for(int n=0;n<list.count();n++){
    node temp = list.pop();
    for(int m=0;m<wall.count();m++){
      node temp2 = wall.pop();
      ////////////////////// uslov 1: ako je komsija zid izbaci iz komsija ///////
      if(temp.x==temp2.x && temp.y==temp2.y){
        
      }else{
        trans.push(temp);
      }
      trans2.push(temp2);
      
    }
  }
  //////// vrati list bez izbacenih elemetata i wall ne izmjenjen/////
  list=trans;
  wall=trans2;
  trans=zero;
  trans2=zero;
  ///////// uslov 2:  ako je u main listi cvor sa istim koordinatama a vecom distancom ili jednakom izbaci///
 for(int n=0;n<list.count();n++){
   trans=list;
   node temp = list.pop();
    for(int m=n+1;m<trans.count();m++){
      node temp2 = trans.pop();
      ////////////////////// uslov 1: ako je komsija zid izbaci iz komsija ///////
      if(temp.x==temp2.x && temp.y==temp2.y && temp.d<=temp2.d){
        
      }else{
        trans2.push(temp);
      }
      trans2.push(temp2);
      
    }
  }
  
  
  Serial.println( a.d);
}
