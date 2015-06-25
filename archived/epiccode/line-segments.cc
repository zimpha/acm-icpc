#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10, inf = 2e9;

int g[MAXN], dp[MAXN], n;
vector<int> Xs;

void add(int x, int v) {
  for (; x <= n; x += ~x & x + 1) {
    g[x] = max(g[x], v);
  }
}
int get(int x) {
  int r(0);
  for (; x >= 0; x -= ~x & x + 1) {
    r = max(r, g[x]);
  }
  return r;
}

int main() {
  map<int, vector<int> > mp;
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    int a, b; scanf("%d%d", &a, &b);
    Xs.push_back(b);
    mp[a].push_back(b);
  }
  sort(Xs.begin(), Xs.end());
  Xs.erase(unique(Xs.begin(), Xs.end()), Xs.end());
  for (auto &x: mp) {
    map<int, int> upd;
    for (auto &u: x.second) {
      int a = lower_bound(Xs.begin(), Xs.end(), u) - Xs.begin();
      int b = get(a - 1) + 1;
      upd[a] = max(upd[a], b);
    }
    for (auto &x: upd) add(x.first, x.second);
  }
  printf("%d\n", get(n));
  return 0;
}