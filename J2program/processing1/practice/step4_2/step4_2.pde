// 弾が途中で消えないようにする
// しかし，敵がいない

PImage shipImg;
int shipX;
int shipY;

PImage laserImg;
int laserX;
int laserY;
int laserAlive; // 弾のフラグ．弾がウィンドウ内にあるとき1，ないとき0にする

void setup() {
  size(400, 600);
  imageMode(CENTER);
  shipImg = loadImage("ship.png");
  laserImg = loadImage("laser.png");
  
  laserAlive = 0; // 弾はまだ発射してないのでlaserAliveを0に設定する．
}

void draw() {
  background(0);
  shipX = mouseX;
  shipY = mouseY;
  image(shipImg, shipX, shipY);
  
  if (mousePressed == true) {
    // もし，画面内に弾が存在しないなら，発射できる
    if (laserAlive == 0) {
      laserX = shipX;
      laserY = shipY;
      laserAlive = 1; // 発射したので1にする
    }
  }
  image(laserImg, laserX, laserY);
  laserY = laserY - 5;
  // 弾が画面の外に出たら，弾を消す
  if (laserY<0) {
    laserAlive = 0;
  }
}
