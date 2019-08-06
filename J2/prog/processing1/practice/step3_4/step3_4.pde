// 自機をマウス操作できる
// Step3が完成

PImage shipImg;
int shipX;
int shipY;

void setup() {
  size(1000, 700);
  imageMode(CENTER);
  shipImg = loadImage("ship.png");

  shipX = 200;
  shipY = 450;
}

void draw() {
  background(0);
  shipX = mouseX; // ウィンドウ内のマウスカーソルのx座標を取得
  shipY = mouseY; // ウィンドウ内のマウスカーソルのy座標を取得
  image(shipImg, shipX, shipY);
}