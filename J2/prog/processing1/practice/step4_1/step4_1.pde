// 弾を撃てるようにする
// しかし，連続して発射させると，弾が途中で消える．．．

PImage shipImg;
int shipX;
int shipY;

PImage laserImg; // 弾の画像の変数を宣言
int laserX; // 弾のx座標
int laserY; // 弾のy座標

void setup() {
  size(400, 600);
  imageMode(CENTER);
  shipImg = loadImage("ship.png");
  laserImg = loadImage("laser.png"); // 弾の画像を読み込む
}

void draw() {
  background(0);
  shipX = mouseX;
  shipY = mouseY;
  image(shipImg, shipX, shipY);
  
  // もしマウスが押されたら，弾を発射する
  if (mousePressed == true) {
    laserX = shipX;
    laserY = shipY;
  }
  image(laserImg, laserX, laserY);
  laserY = laserY - 5; // 弾が上（つまりy軸の-方向）に移動．移動速度は5．
}
