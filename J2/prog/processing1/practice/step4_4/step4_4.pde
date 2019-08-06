// 敵を移動させる
// しかし，弾と敵の当たり判定がない．．．

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
int enemyAlive; // 敵のフラグ．敵がウィンドウ内にあるとき1，ないとき0にする

void setup() {
  size(400, 600);
  imageMode(CENTER);
  shipImg = loadImage("ship.png");
  laserImg = loadImage("laser.png");
  enemyImg = loadImage("enemy.png");
  
  laserAlive = 0;
  enemyAlive = 0;// 敵はまだ出現してないのでenemyAliveを0に設定する．
}

void draw() {
  background(0);
  
  // もし，敵がいないなら，敵を表示
  if (enemyAlive == 0) { 
    enemyX = 200;
    enemyY = -100;
    enemyAlive = 1; // 敵を出現させたので1にする
  }
  // もし，敵がいるなら，敵を移動
  if (enemyAlive == 1) {
    image(enemyImg, enemyX, enemyY);
    enemyY = enemyY + 1; // 下向きに移動
  }  
  // もし，敵が画面の外に出たら
  if (enemyY > 800) {
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
