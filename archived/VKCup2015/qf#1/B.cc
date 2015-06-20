#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 200000 + 10;

int w[MAXN], h[MAXN];
int mp[MAXN], ms[MAXN];
int n, m, sum;

int main() {
  scanf("%d", &n); sum = 0;
  for (int i = 0; i < n; ++ i) {
    scanf("%d%d", w + i, h + i);
    sum += w[i];
  }
  mp[0] = h[0]; ms[n - 1] = h[n - 1];
  for (int i = 1; i < n; ++ i) {
    mp[i] = max(mp[i - 1], h[i]);
  }
  for (int i = n - 2; i >= 0; -- i) {
    ms[i] = max(ms[i + 1], h[i]);
  }
  for (int i = 0; i < n; ++ i) {
    LL W = sum - w[i];
    LL H = 0;
    if (i > 0) H = max(H, (LL)mp[i - 1]);
    if (i + 1 < n) H = max(H, (LL)ms[i + 1]);
    printf("%lld ", W * H);
  }
  puts("");
  return 0;
}