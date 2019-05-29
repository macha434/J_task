#define KEYBUFSIZE 10  /* キーバッファの大きさ */
#define KEYROWNUM 4    /* キー配列の列数(縦に並んでいる個数) */
#define KEYCOLNUM 3    /* キー配列の行数(横に並んでいる個数) */
#define KEYMINNUM  1   /* キー番号の最小値 */
#define KEYMAXNUM 12   /* キー番号の最大値 */
#define KEYNONE   -1   /* 指定したキーがない */
#define KEYOFF     0   /* 指定したキーはずっと離されている状態 */
#define KEYON      1   /* 指定したキーはずっと押されている状態 */
#define KEYRELEASE 2   /* 指定したキーは今離された状態 */
#define KEYPUSH    3   /* 指定したキーは今押された状態 */

/* タイマ割り込み処理のため, バッファ関連は大域変数として確保 */
int keybufdp;
unsigned char keybuf[KEYBUFSIZE][KEYROWNUM];

extern void key_init(void);
extern void key_sense(void);
extern int key_check(int keynum);
