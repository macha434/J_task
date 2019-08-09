#include <stdio.h>
/*
                                   -memo-
  n=階段数で考える
  n<=0の時は 0回で登れることは自明。
  n=1の時は 1回でのぼれる
  n=2の時は 1段*2 または 2段*1で登れることが分かる(2回)
  n=3の時は 1*3 2*1+1 1+2*2 3 で登れる(4回)
  n=4の時は 7回 これは(n=3)+(n=2)+(n=1)の和である
  n=5の時は...?
*/
double dfs(int n)
{
  if(n<=0) return 0;
  if(n==1) return 1;
  if(n==2) return 2;
  if(n==3) return 4;
  if(n==4) return 7;
  if(n==5) return 13;
  if(n==6) return 24;
  if(n==7) return 44;
  if(n==8) return 81;
  if(n==9) return 149;
  if(n==10) return 274;
  if(n==11) return 504;
  if(n==12) return 927;
  if(n==13) return 1705;
  if(n==14) return 3136;
  if(n==15) return 5768;
  if(n==16) return 10609;
  if(n==17) return 19513;
  if(n==18) return 35890;
  if(n==19) return 66012;
  if(n==20) return 121415;
  if(n==21) return 223317;
  if(n==22) return 410744;
  if(n==23) return 755476;
  if(n==24) return 1389537;
  if(n==25) return 2555757;
  if(n==26) return 4700770;
  if(n==27) return 8646064;
  if(n==28) return 15902591;
  if(n==29) return 29249425;
  if(n==30) return 53798080;
  if(n==31) return 98950096;
  if(n==32) return 181997601;
  if(n==33) return 334745777;
  if(n==34) return 615693474;
  if(n==35) return 1132436852;
  if(n==36) return 2082876103;
  if(n==37) return 3831006429;
  if(n==38) return 7046319384;
  if(n==39) return 12960201916;
  if(n==40) return 23837527729;
  if(n==41) return 43844049029;
  if(n==42) return 80641778674;
  if(n==43) return 148323355432;
  if(n==44) return 272809183135;
  if(n==45) return 501774317241;
  if(n==46) return 922906855808;
  if(n==47) return 1697490356184;
  if(n==48) return 3122171529233;
  if(n==49) return 5742568741225;
  if(n==50) return 10562230626642;
  if(n==51) return 19426970897100;
  if(n==52) return 35731170264967;
  if(n==53) return 65720971788709;
  if(n==54) return 120879712950776;
  if(n==55) return 222332455004452;
  if(n==56) return 408933139743937;
  if(n==57) return 752145307699165;
  if(n==58) return 1383410902447554;
  if(n==59) return 2544489349890656;
  if(n==60) return 4680045560037375;
  if(n==61) return 8607945812375585;
  if(n==62) return 15832480722303616;
  if(n==63) return 29120472094716576;
  if(n==64) return 53360898629395777;
  if(n==65) return 98513851446415969;
  if(n==66) return 181195222170528322;
  if(n==67) return 333069972246340096;
  if(n==68) return 612779045863284352;
  if(n==69) return 1127044240280152832;
  if(n==70) return 2072893258389777408;
  if(n==71) return 3812716544533214720;
  if(n==72) return 7012654043203145728;
  if(n==73) return 12898263846126137344;
  /*if(n==74) return 3136;
  if(n==75) return 5768;
  if(n==76) return 10609;
  if(n==77) return 19513;
  if(n==78) return 35890;
  if(n==79) return 66012;*/
  return dfs(n-3)+dfs(n-2)+dfs(n-1);
}
int main(void)
{
  unsigned long long  stairs;
  printf("Stairs>");
  scanf("%d",&stairs);
  //for(stairs=66;;stairs++)
    printf("%d permutation=%.0f\n",stairs,dfs(stairs));
  return 0;
}
