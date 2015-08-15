#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;

vector<int> G[MAXN];
int d1[MAXN], d2[MAXN];

void dfs(int u, int d[], int f = -1) {
  for (auto &v: G[u]) if (v != f) {
    d[v] = d[u] + 1;
    dfs(v, d, u);
  }
}

int main() {
  int n; scanf("%d", &n);
  for (int i = 1; i < n; ++ i) {
    int u, v; scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(0, d1);
  int mx(0), A(-1), B(-1);
  for (int i = 0; i < n; ++ i) {
    if (d1[i] > mx) mx = d1[i], A = i;
  }
  mx = d1[A] = 0; dfs(A, d1);
  for (int i = 0; i < n; ++ i) {
    if (d1[i] > mx) mx = d1[i], B = i;
  }
  dfs(B, d2);
  int ca(0), cb(0), cnt(0);
  for (int i = 0; i < n; ++ i) {
    if (d1[i] == mx && d2[i] == mx) ++ cnt;
    else if (d1[i] == mx) ++ ca;
    else if (d2[i] == mx) ++ cb;
  }
  for (int i = 0; i < n; ++ i) {
    int ret(0);
    if (d1[i] == d2[i]) {
      if (d1[i] == mx) ret = ca + cb + cnt - 1;
      else ret = ca + cb + cnt;
    }
    else if (d1[i] > d2[i]) ret = cb + cnt;
    else ret = ca + cnt;
    printf("%d%c", ret, " \n"[i == n - 1]);
  }
  return 0;
}