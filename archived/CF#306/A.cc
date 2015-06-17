#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
char s[MAXN];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int lab(n), rab(-1), lba(n), rba(-1);
  for (int i = 0; i + 1 < n; ++ i) {
    if (s[i] == 'A' && s[i + 1] == 'B') {
      lab = min(lab, i + 1);
      rab = max(rab, i);
    }
    if (s[i] == 'B' && s[i + 1] == 'A') {
      lba = min(lba, i + 1);
      rba = max(rab, i);
    }
  }
  if (lab < rba || lba < rab) puts("YES");
  else puts("NO");
  return 0;
}
