//----------------------------------------------
// 簡単シューティングゲーム完成版（コメント付き）
//----------------------------------------------

// 自機
PImage shipImg; // 自機の画像を格納する変数を宣言
int shipX;      // 自機のx座標の変数を宣言
int shipY;      // 自機のy座標の変数を宣言

// 弾
PImage laserImg;
int laserX;
int laserY;
int laserAlive; // 弾が画面内に存在するかどうかのフラグ

// 敵
PImage enemyImg;
int enemyX;
int enemyY;
int enemyAlive;
int moveY;      // 敵のy軸方向の移動速度


//-------------------------------
// ゲーム起動時に１度だけ実行する
//-------------------------------
void setup() {
  size(400, 600); // 画面サイズを400 x 600の長方形にする
  imageMode(CENTER); // 画像座標の指定方法を中心に設定
  
  // 画像を読み込む
  shipImg = loadImage("ship.png");
  laserImg = loadImage("laser.png");
  enemyImg = loadImage("enemy.png");
  
  // ウィンドウ内に存在する場合1，存在しない場合0にする
  laserAlive = 0;
  enemyAlive = 0;
}

//-------------------------------------------
// ゲーム実行時に１秒間に60回画面が更新される
//-------------------------------------------
void draw() {
  background(0); // 画面クリアー（画面を黒を塗りつぶす）
  
  println(enemyX, enemyY); // 敵の座標をコンソールに出力

  //---------
  // 敵の処理
  //---------
  // もし，敵が画面内にいないなら，出現させる．
  if (enemyAlive == 0) {
    enemyX = (int)random(400);
    enemyY = -100; // 画面の外から現れるようにするため
    enemyAlive = 1;
    moveY = (int)random(10) + 1; // 1から10の乱数を生成．1を足さないと，乱数値が0のとき移動しなくなる
  }

  // もし，敵が画面内にいるなら，表示させる
  if (enemyAlive == 1) {
    image(enemyImg, enemyX, enemyY);
    enemyY = enemyY + moveY; // moveYに応じて移動させる
  }  

  // もし，敵が画面下の外側に出たら，敵の存在フラグを0にして消す
  if (enemyY > 800) {
    enemyAlive = 0;
  }
  
  // 弾と敵の当たり判定
  // もし，弾が存在するなら，
  if (laserAlive == 1) {
    // もし，敵と弾の中心座標間の距離が30未満なら
    if (dist(enemyX, enemyY, laserX, laserY) < 30) {
      enemyAlive = 0; // 敵を消す
      laserAlive = 0; // 弾を消す
    }
  }
  
  //-----------
  // 自機の処理
  //-----------
  shipX = mouseX;
  shipY = mouseY;
  image(shipImg, shipX, shipY);
  
  //---------
  // 弾の処理
  //---------
  if (mousePressed == true) { // マウスが押されたら，
    if (laserAlive == 0) { // 画面内に弾が存在しないなら弾発射
      laserX = shipX; // 弾の座標は，自機の座標からコピーする．
      laserY = shipY;
      laserAlive = 1; // 今，弾を打ったので，フラグを立てる．
    }
  }
  
  // 弾が画面内にいるなら，表示させる
  if (laserAlive == 1) {
    image(laserImg, laserX, laserY);
    laserY = laserY - 5; // 上に移動
  }
  
  // 弾が画面上の外側に出たら，弾の存在フラグを0にして消す
  if (laserY<0) {
    laserAlive = 0;
  }
}
