#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 50000 + 10;
vector<int> G[MAXN];
int n, m;

struct Entry {
  int anc, dis, idx;
  Entry() {}
  Entry(int a, int b, int c): anc(a), dis(b), idx(c) {}
};

struct BIT {
  vector<int> u, s, c;
  int n;
  void add(int v) {s.push_back(v);}
  void build() {
    c = s; sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());
    n = c.size(); u.assign(n + 1, 0);
    for (size_t i = 0; i < s.size(); ++ i) ins(s[i]);
  }
  void ins(int x) {
    int i = lower_bound(c.begin(), c.end(), x) - c.begin();
    for (; i <= n; i += ~i & i + 1) u[i] ++;
  }
  int get(int x) {// <=x
    int r = 0, i = upper_bound(c.begin(), c.end(), x) - c.begin() - 1;
    for (; i >= 0; i -= ~i & i + 1) r += u[i];
    return r;
  }
};

struct Item {
  vector<BIT> lev;
  void add(int d, int v) {
    while ((int)lev.size() <= d) lev.push_back(BIT());
    lev[d].add(v);
  }
  void build() {
    for (auto &x : lev) x.build();
  }
  int get(int d, int v) {
    if (d >= (int)lev.size()) return 0;
    else return lev[d].get(v);
  }
} pool[MAXN << 4];

vector<Entry> entry[MAXN];

namespace TreeSplit {
  bool vis[MAXN];
  int rt, mx, total;
  int sz[MAXN], item_cnt;
  void getCenter(int u, int f = -1) {
    sz[u] = 1; int tmp = 0;
    for (auto &v : G[u]) if (v != f && !vis[v]) {
      getCenter(v, u); sz[u] += sz[v];
      tmp = max(tmp, sz[v]);
    }
    tmp = max(tmp, total - sz[u]);
    if (tmp < mx) mx = tmp, rt = u;
  }
  int anc;
  void calc(int u, int f = -1, int d = 0) {
    sz[u] = 1; pool[item_cnt].add(d, u);
    entry[u].push_back(Entry(anc, d, item_cnt));
    for (auto &v : G[u]) if (v != f && !vis[v]) {
      calc(v, u, d + 1); sz[u] += sz[v];
    }
  }
  void build(int u, int tot) {
    total = tot; rt = -1; mx = tot * 2;
    getCenter(u); u = rt; vis[u] = true;
    anc = rt;
    calc(u); pool[item_cnt ++].build();
    anc = -1;
    for (auto &v : G[u]) if (!vis[v]) {
      calc(v, u, 1); pool[item_cnt ++].build();
    }
    for (auto &v : G[u]) if (!vis[v]) {
      build(v, sz[v]);
    }
  }
}

int count(int x, int d, int lim) {
  int ret = 0;
  for (auto &e : entry[x]) {
    if (d >= e.dis) {
    int rest = d - e.dis;
    if (e.anc != -1) ret += pool[e.idx].get(rest, lim);
    else ret -= pool[e.idx].get(rest, lim);
  }
}
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++ i) {
    int u, v; scanf("%d%d", &u, &v); -- u, -- v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  TreeSplit::build(1, n);
  scanf("%d", &m);
  while (m --) {
    int c, d, k; scanf("%d%d%d", &c, &d, &k); -- c;
    int left = 0, right = n - 1;
    while (left < right) {
      int mid = (left + right - 1) >> 1;
      if (count(c, d, mid) >= k) right = mid;
      else left = mid + 1;
    }
    printf("%d\n", left + 1);
  }
  return 0;
}
