#define BASETIME 8

unsigned char sound_pat[BASETIME]; /* 波形パターンが入る */
unsigned char loud; /* 再生音量 (0-255) */
unsigned char mute; /* 休符:0, その他:1 */

extern unsigned int sound(unsigned int s_tempo, int s_long, 
			  char *s_tone, int tone_ch);
     /* 1音を出すための関数                                           */
     /*  s_tempo: 演奏テンポ(60で全音1秒)                             */
     /*  s_long : 長さ指定(1:全音符 - 32:32分音符, 符点は中間値)      */
     /*  s_tone : 高さ指定                                            */
     /*             CDEFGABと #/b(半音上げ/下げ), +/-(オクターブ上下) */
     /*           休符は CDEFGAB 以外の文字を最初に入れる             */
     /*  tone_ch: 音程用タイマのチャネル指定                          */
     /* 戻り値: 音の長さ(ms)                                          */
     /* 注意: 呼び出す前に sound_pat に波形パターンを入れておくこと   */

/* 新規にプログラムを作成する場合は以下の関数を使用すること */
extern unsigned int sound_tone(char *s_tone);
     /* 音程用の割り込み期間を求める関数                              */
     /*  s_tone : 高さ指定                                            */
     /*             CDEFGABと #/b(半音上げ/下げ), +/-(オクターブ上下) */
     /*             休符は CDEFGAB 以外の文字を最初に入れる           */
     /* 戻り値: 音程用割り込み期間 (us)                               */
extern unsigned long sound_period(unsigned int tempo, char *period);
     /* 音の長さを計算する関数                                      */
     /*   s_tempo: 演奏テンポ (4分音符数/分)                        */
     /*   s_long : 長さのデータが入った文字配列                     */
     /*     [0][1]: 音符の符数(1,2,4,8,16,32) [2]: 符点と3連符(.,t) */
