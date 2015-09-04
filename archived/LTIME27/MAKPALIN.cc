#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
typedef pair<int, int> PII;

const int MAXN = 100000 + 10, seed = 65537;

LL pw[MAXN], hs[MAXN], hp[MAXN];
char s[MAXN];

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    hp[0] = 0; hs[n] = 0; pw[0] = 1;
    for (int i = 1; i <= n + 1; ++ i) {
      pw[i] = pw[i - 1] * seed;
    }
    for (int i = 1; i <= n; ++ i) {
      hp[i] = hp[i - 1] * seed + s[i];
    }
    for (int i = n; i >= 1; -- i) {
      hs[i] = hs[i + 1] * seed + s[i];
    }
    int ret(0);
    for (int i = 0; i <= n; ++ i) {
      int l(i), r = n - i;
      LL hlp = hp[i] - hp[i - l] * pw[l];
      LL hls = hs[1] - hs[1 + l] * pw[l];
      LL hrp = hp[n] - hp[n - r] * pw[r];
      LL hrs = hs[i + 1] - hs[i + 1 + r] * pw[r];
      bool flag(0);
      for (char c = 'a'; c <= 'z'; ++ c) {
        LL a = hrs * pw[l + 1] + c * pw[l] + hls;
        LL b = hlp * pw[r + 1] + c * pw[r] + hrp;
        flag |= a == b;
      }
      ret += flag;
    }
    printf("%d\n", ret);
  }
  return 0;
}
