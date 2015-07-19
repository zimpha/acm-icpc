#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 60;

int G[MAXN][MAXN], tk[MAXN][MAXN];
int deg[MAXN], n;
int strategy(0);

PII get_max(int u) {
  PII ret(0, 0);
  for (int i = 1; i <= n; ++ i) if (!tk[u][i]) {
    if (PII(G[u][i], i) > ret) ret = PII(G[u][i], i);
  }
  return ret;
}

PII get_min(int u) {
  PII ret(1e9, 0);
  for (int i = 1; i <= n; ++ i) if (!tk[u][i]) {
    if (PII(G[u][i], i) < ret) ret = PII(G[u][i], i);
  }
  return ret;
}

PII get_mid(int u) {
  PII ret(0, 0); int c(0), s(0);
  for (int i = 1; i <= n; ++ i) if (!tk[u][i]) {
    s += G[u][i]; ++ c;
  }
  if (c) {
    s /= c; ret.first = 1e9;
    for (int i = 1; i <= n; ++ i) if (!tk[u][i]) {
      if (abs(G[u][i] - s) < ret.first) ret = PII(G[u][i], i);
    }
  }
  return ret;
}

void get_cost(int d, int u, int sum, int &ret) {
  ret = max(sum, ret);
  if (d == 0) return;
  PII tmp = get_max(u);
  if (tmp.second == 0) return;
  tk[u][tmp.second] = 1;
  sum -= tmp.first;
  for (int i = 1; i <= n; ++ i) if (!tk[tmp.second][i]) {
    tk[tmp.second][i] = 1;
    get_cost(d - 1, i, sum + G[tmp.second][i], ret);
    tk[tmp.second][i] = 0;
  }
  tk[u][tmp.second] = 0;
}

vector<PII> solve0(int u) {
  vector<PII> pt;
  for (int i = 1; i <= n; ++ i) if (!tk[u][i]) {
    pt.push_back(PII(G[u][i], i));
  }
  sort(pt.begin(), pt.end(), greater<PII>());
  if (pt.empty()) pt.push_back(PII(0, 0));
  return pt;
}

vector<PII> solve1(int u) {
  vector<PII> pt;
  for (int i = 1; i <= n; ++ i) if (!tk[u][i]) {
    pt.push_back(PII(G[u][i] - get_max(i).first, i));
  }
  sort(pt.begin(), pt.end(), greater<PII>());
  if (pt.empty()) pt.push_back(PII(0, 0));
  return pt;
}

vector<PII> solve2(int u) {
  vector<PII> pt;
  for (int i = 1; i <= n; ++ i) if (!tk[u][i]) {
    tk[u][i] = 1;
    vector<PII> tmp = solve1(i);
    pt.push_back(PII(G[u][i] - tmp[0].first, i));
    tk[u][i] = 0;
  }
  sort(pt.begin(), pt.end(), greater<PII>());
  if (pt.empty()) pt.push_back(PII(0, 0));
  return pt;
}

vector<PII> solve3(int u) {
  vector<PII> pt;
  for (int i = 1; i <= n; ++ i) if (!tk[u][i]) {
    tk[u][i] = 1;
    PII t = strategy ? get_max(i) : get_min(i);
    pt.push_back(PII(G[u][i] - t.first + solve1(t.second)[0].first, i));
    tk[u][i] = 0;
  }
  sort(pt.begin(), pt.end(), greater<PII>());
  if (pt.empty()) pt.push_back(PII(0, 0));
  return pt;
}

vector<PII> solve4(int u) {
  vector<PII> pt;
  for (int i = 1; i <= n; ++ i) if (!tk[u][i]) {
    tk[u][i] = 1;
    PII t = strategy ? get_max(i) : get_min(i);
    pt.push_back(PII(G[u][i] - t.first + (strategy ? get_max(t.second) : get_mid(t.second)).first, i));
    tk[u][i] = 0;
  }
  sort(pt.begin(), pt.end(), greater<PII>());
  if (pt.empty()) pt.push_back(PII(0, 0));
  return pt;
}

int main() {
  scanf("%d", &n);
  int mx, my, mv(n*(n-1));
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= n; ++ j) {
      scanf("%d", &G[i][j]);
      if (G[i][j] == mv) mv = G[i][j], mx = i, my = j;
    }
    deg[i] = n - 1; tk[i][i] = 1;
  }
  for (int i = 0; i <= n; ++ i) tk[0][i] = tk[i][0] = 1;
  printf("%d %d\n", mx, my); fflush(stdout);
  tk[mx][my] = 1; deg[mx] --;
  const int w1[] = {5, 47, 49, 50, 0};
  const int w2[] = {16, 33, 34, 50, 0};
  for (int px, py; scanf("%d%d", &px, &py) == 2; ) {
    if (get_max(px).second == py) strategy = 1;
    tk[px][py] = 1; deg[px] --;
    if (deg[py] <= 0) return 0;
    vector<PII> v0 = solve0(py);
    vector<PII> v1 = solve1(py);
    vector<PII> v2 = solve2(py);
    vector<PII> v3 = solve3(py);
    //vector<PII> v4 = solve4(py);
    int rk[MAXN] = {0};
    const int *w;
    if (strategy) w = w1;
    else w = w2;
    for (size_t i = 0; i < v1.size(); ++ i) {
      rk[v0[i].second] += w[0] * (i + 1);
      rk[v1[i].second] += w[1] * (i + 1);
      rk[v2[i].second] += w[2] * (i + 1);
      rk[v3[i].second] += w[3] * (i + 1);
      //rk[v4[i].second] += w[4] * (i + 1);
    }
    vector<PII> ret;
    for (int i = 1; i <= n; ++ i) if (rk[i]) {
      ret.push_back(PII(rk[i], i));
    }
    sort(ret.begin(), ret.end());
    printf("%d %d\n", py, ret[0].second); fflush(stdout);
    tk[py][ret[0].second] = 1; deg[py] --;
    if (deg[ret[0].second] <= 0) return 0;
  }
  return 0;
}