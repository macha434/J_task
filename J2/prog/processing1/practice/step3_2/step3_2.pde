// 背景を黒にして表示クリア
// しかし，自機がどっかに行ってしまう．．．

PImage shipImg;
int shipX;
int shipY;

// 最初に1度だけ行う
void setup() {
  size(400, 600);
  imageMode(CENTER);
  shipImg = loadImage("ship.png");

  shipX = 200;
  shipY = 450;
}

// 1秒間に60回画面を更新する
void draw() {
  background(0); // 背景を黒にする．0が黒，255が白で変化する．
  shipX = shipX + 3;
  image(shipImg, shipX, shipY);
}
