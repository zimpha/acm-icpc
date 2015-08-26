#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
int pl[MAXN], mp[MAXN], n, m;
LL cnt[MAXN];

void sieve() {  
  for (int i = 2; i < MAXN; ++ i) {
    if (!mp[i]) pl[m ++] = i, mp[i] = i;
    for (int j = 0; j < m && pl[j] * i < MAXN; ++ j) {
      mp[pl[j] * i] = pl[j];
      if (i % pl[j] == 0) break;
    }
  }
  for (int i = 2; i < MAXN; ++ i) {
    cnt[i] = mp[i] * cnt[i / mp[i]] + i / mp[i];
  }
}

int main() {
  sieve();
  int T; scanf("%d", &T);
  while (T --) {
    scanf("%d", &n);
    LL ret = 0;
    int x = n;
    for (int i = 0; pl[i] * pl[i] <= n && n >= MAXN; ++ i) {
      while (n % pl[i] == 0) n /= pl[i], ret += x / pl[i];
    }
    if (n < MAXN) ret += x / n * cnt[n];
    else ret += x / n;
    printf("%lld\n", ret);
  }
  return 0;
}