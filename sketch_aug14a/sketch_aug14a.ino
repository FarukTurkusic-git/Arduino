void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

void izvrsavanje_kretanja(cvor trenutna, cvor cilj){
  while(trenutna!=cilj){
  cvor lista[4];
   cvor z.x=trenutna.x-1;
   cvor z.y=trenutna.y;
   cvor.add(z);
   cvor z.x=trenutna.x+1;
   cvor z.y=trenutna.y;
   cvor.add(z);
   cvor z.x=trenutna.x;
   cvor z.y=trenutna.y-1;
   cvor.add(z);
   cvor z.x=trenutna.x;
   cvor z.y=trenutna.y+1;
   cvor.add(z);
   for(int a=0;a<4;a++){
     list[a].dist=10+(abs(list[a].x-cilj.x)+abs(list[a].y-cilj.y));
   }
   bubble_sort(lista);
   cvor smjer=lista[0];
   
   }
  
}
