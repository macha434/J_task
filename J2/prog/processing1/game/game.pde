void setup(){
  size(650, 650);
  background(255);
}
void draw(){
  
  /*int i, j;
  int col[][];
  
  colorMode(HSB, 360, 100, 100, 100);

  for (i= 1; i<= 5; i++){
    for (j= 1; j<= 5; j++){
      fill(100, 100, 100, 1);
      rect(i* 125- 100, j* 125- 100, 100, 100);
    }
  }*/
  
  int value= 0;
   
   if(mousePressed){
     value= 255;
   }
   fill(value);
   rect(25, 25, 50, 50);
   
   print(value);
 }

/*void mousePressed() {
 int value= 0;
 if (value == 0) {
  value = 255;
 } else {
   value = 0;
 }
}*/