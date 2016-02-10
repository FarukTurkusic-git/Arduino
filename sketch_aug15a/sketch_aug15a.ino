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


node wall[35];
node neighbours[4];
node trenutna;

void neigh(){
  node u=trenutna;
  u.x=u.x+1;
  neighbours[0]=u;
  
  node d=trenutna;
  d.x=d.x-1;
  neighbours[1]=d;
  
  node r=trenutna;
  r.y=r.y+1;
  neighbours[2]=r;
  
  node l=trenutna;
  l.y=l.y-1;
  neighbours[3]=l;
}

void setup() {
  Serial.begin(9600);
  node path_list[35];
  node list[35];
  
  node matrix[7][5];

}


void loop() {
  
  node a;
  a.init(2,1,0);
  
  trenutna.init(1,1,0);
  /////////// kreira lista celija komsija///////////
  neigh();
  ///////// provjera uslova //////////////
  for(int n=0;n<sizeof(neighbours);n++){
    for(int m=0;m<sizeof(wall);m++){
      if(neighbours[n].x==wall[m].x && neighbours[n].y==wall[m].y){
        ////////////////////// uslov 1: ako je komsija zid izbaci iz komsija ///////
        neighbours[n].d=100;
      }
      
    }
  }
  ///////// uslov 2:  ako je u main listi cvor sa istim koordinatama a vecom distancom izbaci///
  for(int n=0;n<sizeof(list);n++){
    for(int m=0;m<sizeof(neighbours);m++){
      if(list[n].x==neighbours[m].x && list[n].y==neighbours[m].y && list[n].d<=neighbours[m].d){
        
        list[n].d=100;
      }
      
    }
  }
  
  
  Serial.println( a.d);
}
