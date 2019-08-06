PImage shipImg;
int shipX; // 自機のx座標の宣言
int shipY; // 自機のy座標の宣言

size(400, 600);
imageMode(CENTER);
shipImg = loadImage("ship.png"); 

shipX = 200; // 自機のx座標を入力
shipY = 450; // 自機のy座標を入力
image(shipImg, shipX, shipY); // 変数を使って画像を表示
