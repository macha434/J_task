// 敵の移動速度をランダムにする
// これで簡単シューティングゲームが完成！

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
int moveY; // 敵のy軸方向の移動速度

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
  
  println(enemyX, enemyY); // 確認用．敵の座標をコンソールに出力
  
  if (enemyAlive == 0) {
    enemyX = (int)random(400); 
    enemyY = -100;
    enemyAlive = 1;
    moveY = (int)random(10) + 1; // 1から10のランダムな値を生成
  }

  if (enemyAlive == 1) {
    image(enemyImg, enemyX, enemyY);
    enemyY = enemyY + moveY; // moveYに応じて敵を移動させる
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
