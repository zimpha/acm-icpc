#include <bits/stdc++.h>
using namespace std;

int main() {
  int ans[10][10];
  memset(ans, 0xff, sizeof(ans));
  ans[1][1]=0;
  ans[2][2]=1;
  ans[4][4]=2;
  ans[8][8]=3;
  ans[1][6]=4;
  ans[3][2]=5;
  ans[6][4]=6;
  ans[1][8]=7;
  ans[2][6]=8;
  ans[5][2]=9;
  ans[1][4]=10;
  ans[2][8]=11;
  ans[4][6]=12;
  ans[8][2]=13;
  ans[3][8]=15;
  ans[6][6]=16;
  ans[1][2]=17;
  ans[2][4]=18;
  ans[5][8]=19;
  ans[7][4]=46;
  ans[9][2]=53;
  ans[7][6]=56;
  ans[9][8]=63;
  ans[3][4]=78;
  ans[6][8]=79;
  ans[3][6]=88;
  ans[6][2]=89;
  ans[5][4]=102;
  ans[4][2]=105;
  ans[8][4]=106;
  ans[5][6]=112;
  ans[4][8]=115;
  ans[8][6]=116;
  ans[7][2]=149;
  ans[9][6]=156;
  ans[7][8]=159;
  ans[9][4]=166;
  int a, b, n;
  scanf("%d%d", &a, &b);
  printf("%d\n", ans[a][b]);
}
