// 敵を出現させる
// しかし，敵は動かない

PImage shipImg;
int shipX;
int shipY;

PImage laserImg;
int laserX;
int laserY;
int laserAlive;

PImage enemyImg; // 敵の画像の変数を宣言
int enemyX; // 敵のx座標
int enemyY; // 敵のy座標

void setup() {
  size(400, 600);
  imageMode(CENTER);
  shipImg = loadImage("ship.png");
  laserImg = loadImage("laser.png");
  enemyImg = loadImage("enemy.png"); // 敵の画像を読み込む
  
  laserAlive = 0;
}

void draw() {
  background(0);
  
  // 敵の座標を設定して，敵画像を表示
  enemyX = 200;
  enemyY = 80;
  image(enemyImg, enemyX, enemyY);
  
  shipX = mouseX;
  shipY = mouseY;
  image(shipImg, shipX, shipY);
  
  if (mousePressed == true) {
    if (laserAlive == 0) {
      laserX = shipX;
      laserY = shipY;
      laserAlive = 1;
    }
  }
  image(laserImg, laserX, laserY);
  laserY = laserY - 5;
  if (laserY<0) {
    laserAlive = 0;
  }
}
