#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

map<VI, string> mp;
int V[25][10], w[10];
int lim, n, m;
string ret;

void dfs(int d, int a[], char s[]) {
  if (d == lim) {
    VI v(a, a + n); s[d] = 0;
    if (!mp.count(v)) mp[v] = s;
    return;
  }
  for (int i = 0; i < n; ++ i) a[i] += V[d][i];
  s[d] = 'a'; dfs(d + 1, a, s);
  for (int i = 0; i < n; ++ i) a[i] -= V[d][i];

  for (int i = 0; i < n; ++ i) if (i & 1) a[i] += V[d][i];
  s[d] = 'b'; dfs(d + 1, a, s);
  for (int i = 0; i < n; ++ i) if (i & 1) a[i] -= V[d][i];

  for (int i = 0; i < n; ++ i) if (!(i & 1)) a[i] += V[d][i];
  s[d] = 'c'; dfs(d + 1, a, s);
  for (int i = 0; i < n; ++ i) if (!(i & 1)) a[i] -= V[d][i];
}

void dfs2(int d, int a[], char s[]) {
  if (d == m - lim) {
    VI v(a, a + n); s[d] = 0;
    for (int i = 0; i < n; ++ i) v[i] = w[i] - v[i];
    if (mp.count(v)) {
      string tmp = mp[v];
      tmp += s;
      if (ret == "" || tmp < ret) ret = tmp;
    }
    return;
  }
  for (int i = 0; i < n; ++ i) a[i] += V[d + lim][i];
  s[d] = 'a'; dfs2(d + 1, a, s);
  for (int i = 0; i < n; ++ i) a[i] -= V[d + lim][i];

  for (int i = 0; i < n; ++ i) if (i & 1) a[i] += V[d + lim][i];
  s[d] = 'b'; dfs2(d + 1, a, s);
  for (int i = 0; i < n; ++ i) if (i & 1) a[i] -= V[d + lim][i];

  for (int i = 0; i < n; ++ i) if (!(i & 1)) a[i] += V[d + lim][i];
  s[d] = 'c'; dfs2(d + 1, a, s);
  for (int i = 0; i < n; ++ i) if (!(i & 1)) a[i] -= V[d + lim][i];
}

int main() {
  scanf("%d%d", &m, &n);
  for (int i = 0; i < m; ++ i) {
    for (int j = 0; j < n; ++ j) {
      scanf("%d", &V[i][j]);
    }
  }
  for (int i = 0; i < n; ++ i) scanf("%d", w + i);
  int a[10]; memset(a, 0, sizeof(a));
  char s[25];
  lim = m / 2;
  dfs(0, a, s);
  ret = "";
  dfs2(0, a, s);
  if (ret == "") puts("-1");
  else puts(ret.c_str());
  return 0;
}

