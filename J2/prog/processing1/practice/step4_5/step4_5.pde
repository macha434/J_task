// 弾と敵の当たり判定を行う
// しかし，敵を倒した後の弾が消えない．．．

PImage shipImg;
int shipX;
int shipY;

PImage laserImg;
int laserX;
int laserY;
int laserAlive;

PImage enemyImg;
int enemyX;
int enemyY;
int enemyAlive;

void setup() {
  size(400, 600);
  imageMode(CENTER);
  shipImg = loadImage("ship.png");
  laserImg = loadImage("laser.png");
  enemyImg = loadImage("enemy.png");
  
  laserAlive = 0;
  enemyAlive = 0;
}

void draw() {
  background(0);
  
  if (enemyAlive == 0) {
    enemyX = 200;
    enemyY = -100;
    enemyAlive = 1;
  }

  if (enemyAlive == 1) {
    image(enemyImg, enemyX, enemyY);
    enemyY = enemyY + 1;
  }  

  if (enemyY > 800) {
    enemyAlive = 0;
  }
  
  // 弾と敵の当たり判定
  // もし，敵と弾の中心座標間の距離が30未満なら
  if (dist(enemyX, enemyY, laserX, laserY) < 30) {
    enemyAlive = 0; // 敵を消す
  }
  
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
