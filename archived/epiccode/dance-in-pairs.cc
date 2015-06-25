#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
int a[MAXN], b[MAXN], n, k;

int mx[MAXN << 2];

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++ i) scanf("%d", a + i);
  for (int i = 0; i < n; ++ i) scanf("%d", b + i);
  sort(a, a + n); sort(b, b + n);
  int ret(0);
  set<int> S;
  for (int i = 0; i < n; ++ i) S.insert(i);
  for (int i = 0; i < n; ++ i) {
    int l = a[i] - k, r = a[i] + k;
    l = lower_bound(b, b + n, l) - b;
    r = upper_bound(b, b + n, r) - b - 1;
    if (l > r) continue;
    auto it = S.lower_bound(l);
    if (it == S.end() || *it > r) continue;
    ret ++; S.erase(it);
  }
  cout << ret << endl;
  return 0;
}