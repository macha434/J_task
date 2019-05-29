// 自機が移動する
// しかし，表示がおかしい．．．

PImage shipImg;
int shipX; // 自機のx座標
int shipY; // 自機のy座標

// 最初に1度だけ行う
void setup() {
  size(400, 600);
  imageMode(CENTER);
  shipImg = loadImage("ship.png");

  shipX = 200; // 自機のx座標を200に設定
  shipY = 450; // 自機のy座標を450に設定
}

// 1秒間に60回画面を更新する
void draw() {
  shipX = shipX + 3; // 右（つまりx軸の+方向）に移動．移動速度は3．
  image(shipImg, shipX, shipY);
}
