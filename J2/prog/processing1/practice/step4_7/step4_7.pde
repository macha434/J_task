// 敵をランダムな位置に出現させる
// しかし，敵の移動速度が一定で単調．．．

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
    enemyX = (int)random(400); // 0から399のランダムな値を生成
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
  
  if (dist(enemyX, enemyY, laserX, laserY) < 30) {
    if (laserAlive == 1) {
      enemyAlive = 0;
      laserAlive = 0;
    }
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
  if (laserAlive == 1) {
    image(laserImg, laserX, laserY);
    laserY = laserY - 5;
  }
  if (laserY<0) {
    laserAlive = 0;
  }
}
