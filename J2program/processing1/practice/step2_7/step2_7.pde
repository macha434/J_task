PImage shipImg;          // 自機の画像を格納する変数を宣言
size(400, 600);          // ウィンドウサイズを400x600にする
imageMode(CENTER);       // 画像の座標指定を中心にする
shipImg = loadImage("ship.png"); // 自機の画像を読み込む
image(shipImg, 80, 300); // 画像を(80,300)の位置に表示
