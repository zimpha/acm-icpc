#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int sum(int n) {
  int r(0);
  for (; n; n /= 10) r += n % 10;
  return r;
}
const int MAXN = 5000 + 10;

LL cnt[MAXN], ret[MAXN], tot[MAXN];

int main() {
  for (int i = 1; i <= 1000000; ++ i) {
    int s = sum(i);
    //cout << s << endl;
    cnt[s] ++; tot[s] += i;
    if (cnt[s] >= MAXN) continue;
    if (ret[cnt[s]] == 0 || ret[cnt[s]] > tot[s]) {
      ret[cnt[s]] = tot[s];
    }
  }
  freopen("digits.in", "r", stdin);
  freopen("digits.out", "w", stdout);
  int n; scanf("%d", &n); printf("%lld\n", ret[n]);
  return 0;
}