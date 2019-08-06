void setup(){
  int i, j;
  
  size(650, 650);
  background(255);
  
  for (i= 1; i<= 5; i++){
    for (j= 1; j<= 5; j++){
      fill(255, 150, 150);
      rect(i* 125- 100, j* 125- 100, 100, 100);
    }
  }
}

int [][]col= {{0 ,0 ,0 ,0 ,0},
                 {0 ,0 ,0 ,0 ,0},
                 {0 ,0 ,0 ,0 ,0},
                 {0 ,0 ,0 ,0 ,0},
                 {0 ,0 ,0 ,0 ,0}};
                 
void draw(){
  int count;
  int x= 0, y= 0;
  
  if(mousePressed) { 
    x= mouseX;
    y= mouseY;
    
    Color(x, y, col);
  }
}

void Color(int x, int y, int [][] col){
  
  if((x< 25 || x< 125) && (y< 25 || y< 125)){
    col[0][0]++;
    
    if(col[0][0]== 2){
      col[0][0]= 0;
    }
    
    switch(col[0][0]){
      case 0:
        fill(255, 150, 150);
        rect(25, 25, 100, 100);
        break;
        
      case 1:
        fill(0, 255, 150);
        rect(25, 25, 100, 100);
        break;
    }
    delay(100);
  }
}