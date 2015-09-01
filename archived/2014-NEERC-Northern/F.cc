#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 100000 + 10;

vector<int> g[MAXN];
int a[MAXN], sz[MAXN], cnt[MAXN];
bool mg[MAXN], vis[MAXN];
map<int, int> mp;
int n, m;

bool dfs(int u, int f = -1) {
  if (g[u].empty()) return false;
  for (auto &p: g[u]) if (p != f) {
    if (!vis[p + 1] || cnt[u + 1] == 1) {
      mg[p + 1] = vis[p] = vis[p + 1] = 1;
      if (f != -1) mg[f + 1] = 0;
      return true;
    }
  }
  for (auto &p: g[u]) if (p != f) {
    if (dfs(u + 1, p + 1)) {
      mg[p + 1] = vis[p] = vis[p + 1] = 1;
      if (f != -1) mg[f + 1] = 0;
      return true;
    }
  }
  return false;
}

int main() {
  freopen("fragmentation.in", "r", stdin);
  freopen("fragmentation.out", "w", stdout);
  scanf("%d", &n); m = 0;
  for (int i = 0, p(-1); i < n; ++ i) {
    int x; scanf("%d", &x); mp[x] = 1;
    if (x == p) sz[m - 1] ++;
    else {
      p = x; a[m] = x;
      sz[m ++] = 1;
    }
  }
  n = m; m = 0;
  for (auto &x: mp) x.second = m ++;
  for (int i = 0; i < n; ++ i) {
    a[i] = mp[a[i]]; cnt[a[i]] ++;
  }
  for (int i = 0; i + 1 < n; ++ i) {
    if (a[i] + 1 == a[i + 1]) g[a[i]].push_back(i);
  }
  int ret = n;
  for (int i = m - 1; i >= 0; -- i) {
    if (dfs(i)) -- ret;
  }
  printf("%d\n", ret);
  int sum(0); mg[0] = 1;
  for (int i = 0; i < n; ++ i) {
    if (mg[i]) sum += sz[i];
    else {
      printf("%d ", sum);
      sum = sz[i];
    }
  }
  printf("%d\n", sum);
  return 0;
}