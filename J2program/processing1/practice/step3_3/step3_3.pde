// 自機がウィンドウの端で止まる
// しかし，自機を操作できない

PImage shipImg;
int shipX;
int shipY;

void setup() {
  size(400, 600);
  imageMode(CENTER);
  shipImg = loadImage("ship.png");

  shipX = 200;
  shipY = 450;
}

void draw() {
  background(0);
  
  // もし，自機のx座標が400未満なら
  if (shipX<400) {
    shipX = shipX + 3;
  }
  image(shipImg, shipX, shipY);
}
