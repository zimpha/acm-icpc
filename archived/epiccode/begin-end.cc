#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main() {
  static int cnt[26], n;
  static char s[2000000];
  scanf("%d%s", &n, s);
  for (int i = 0; s[i]; ++ i) cnt[s[i] - 'a'] ++;
  LL ret(0);
  for (int i = 0; i < 26; ++ i) {
    ret += cnt[i] + (LL)cnt[i] * (cnt[i] - 1) / 2;
  }
  printf("%lld\n", ret);
  return 0;
}
