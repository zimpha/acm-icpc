#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int, int> PII;
const int MAXN = 10000 + 10;
VI G[MAXN];
int dis[MAXN], pre[MAXN];
int n;

void bfs(int u) {
  for (int i = 0; i < n; ++ i) dis[i] = -1;
  queue<int> Q; Q.push(u); dis[u] = 0;
  while (!Q.empty()) {
    u = Q.front(); Q.pop();
    for (auto &v: G[u]) if (dis[v] == -1) {
      dis[v] = dis[u] + 1; 
      Q.push(v); pre[v] = u;
    }
  }
}

VI get_path(int s, int t) {
  vector<int> ret;
  for (; t != s; t = pre[t]) {
    ret.push_back(t);
  }
  ret.push_back(s); return ret;
}

PII dfs(int u, int f = -1) {
  int h(0), cnt(1);
  for (auto &v: G[u]) if (v != f) {
    PII x = dfs(v, u); x.first ++;
    if (x.first > h) h = x.first, cnt = 0;
    if (h == x.first) ++ cnt;
  }
  return PII(h, cnt);
}

bool solve() {
  if (n <= 2) return 0;
  int A(0), B(0);
  bfs(0);
  for (int i = 0; i < n; ++ i) {
    if (dis[i] > dis[A]) A = i;
  }
  bfs(A);
  for (int i = 0; i < n; ++ i) {
    if (dis[i] > dis[B]) B = i;
  }
  VI pt = get_path(A, B);
  int D = dis[B], R = D / 2;
  if (D & 1) {
    int x = pt[R], y = pt[R + 1];
    PII a = dfs(x, y), b = dfs(y, x);
    return a.second <= 1 || b.second <= 1;
  }
  else {
    int x = pt[R];
    PII a = dfs(x);
    return a.second <= 2;
  }
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) G[i].clear();
    for (int i = 1; i < n; ++ i) {
      int u, v; scanf("%d%d", &u, &v);
      G[u - 1].push_back(v - 1);
      G[v - 1].push_back(u - 1);
    }
    if (solve()) puts("YES");
    else puts("NO");
  }
  return 0;
}
