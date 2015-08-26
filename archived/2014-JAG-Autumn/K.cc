#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

char s[200];

bool check(int msk) {
  static int bit[20];
  for (int i = 0; i < 19; ++ i) bit[i] = (msk >> i) & 1;
  int inner[7];
  inner[0] = s[bit[13] | (bit[14] << 1) | (bit[12] << 2) | (bit[0] << 3) | (bit[1] << 4) | (bit[2] << 5) | (bit[3] << 6)];
  inner[1] = s[bit[14] | (bit[15] << 1) | (bit[0] << 2) | (bit[1] << 3) | (bit[16] << 4) | (bit[3] << 5) | (bit[4] << 6)];
  inner[2] = s[bit[12] | (bit[0] << 1) | (bit[11] << 2) | (bit[2] << 3) | (bit[3] << 4) | (bit[10] << 5) | (bit[5] << 6)];
  inner[3] = s[bit[0] | (bit[1] << 1) | (bit[2] << 2) | (bit[3] << 3) | (bit[4] << 4) | (bit[5] << 5) | (bit[6] << 6)];
  inner[4] = s[bit[1] | (bit[16] << 1) | (bit[3] << 2) | (bit[4] << 3) | (bit[17] << 4) | (bit[6] << 5) | (bit[18] << 6)];
  inner[5] = s[bit[2] | (bit[3] << 1) | (bit[10] << 2) | (bit[5] << 3) | (bit[6] << 4) | (bit[9] << 5) | (bit[8] << 6)];
  inner[6] = s[bit[3] | (bit[4] << 1) | (bit[5] << 2) | (bit[6] << 3) | (bit[18] << 4) | (bit[8] << 5) | (bit[7] << 6)];
  for (int i = msk = 0; i < 7; ++ i) msk |= inner[i] << i;
  int once = inner[3], twice = s[msk];
  return once == twice;
}

int main() {
  while (scanf("%s", s) == 1 && s[0] != '#') {
    for (int i = 0; i < 128; ++ i) s[i] -= '0';
    bool flag = true;
    for (int msk = 0; msk < (1 << 19) && flag; ++ msk) {
      flag &= check(msk);
    }
    puts(flag ? "yes" : "no");
  }
  return 0;
}