#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;
typedef vector<int> VI;

const int MAXN= 30, SIZE = 700;
void gauss(int n, flt A[][MAXN], flt sol[]) {
  for (int i = 0, r; i < n; ++ i) {
    for (int j = (r = i) + 1; j < n; ++ j) {
      if (fabs(A[j][i]) > fabs(A[r][i])) r = j;
    }
    for (int j = 0; j < n; ++ j) swap(A[r][j], A[i][j]);
    flt now = A[i][i]; swap(sol[r], sol[i]);
    for (int j = 0; j < n; ++ j) A[i][j] /= now; sol[i] /= now;
    for (int j = 0; j < n; ++ j) if (i != j) {
      flt t = A[j][i] / A[i][i];
      for (int k = 0; k < n; ++ k) A[j][k] -= A[i][k] * t;
      sol[j] -= sol[i] * t;
    }
  }
}

map<VI, int> mp;
flt dp[SIZE][MAXN], p[MAXN];
VI S[MAXN];
int n, m;

VI get(const VI &s, int x, int y) {
  VI t(s.begin(), s.begin() + x);
  for (int i = x + 1; i < y; ++ i) t.push_back(s[i]);
  for (int i = y + 1; i < (int)s.size(); ++ i) t.push_back(s[i]);
  t.push_back(s[x] + s[y]);
  sort(t.begin(), t.end());
  return t;
}

void solve(VI s) {
  if (mp.count(s)) return;
  int i = mp.size(); mp[s] = i;
  if (s[0] == n) return;
  int tot = n * (n - 1) / 2;
  for (int u = 0; u < n; ++ u) {
    for (size_t x = 0; x < s.size(); ++ x) {
      for (size_t y = x + 1; y < s.size(); ++ y) {
        VI t = get(s, x, y); solve(t);
        int j = mp[t];
        for (auto &v: S[u]) {
          dp[i][u] += dp[j][v] * p[u] * s[x] * s[y] / tot;
        }
      }
    }
    dp[i][u] /= S[u].size();
  }
  flt a[MAXN][MAXN], b[MAXN];
  memset(a, 0, sizeof(a));
  for (int u = 0; u < n; ++ u) a[u][u] = 1, b[u] = dp[i][u] + 1;
  int cnt(0); for (auto &x: s) cnt += x * (x - 1) / 2;
  for (int u = 0; u < n; ++ u) {
    for (auto &v: S[u]) {
      a[u][v] -= (1 - p[u] + p[u] * cnt / tot) / S[u].size();
    }
  }
  gauss(n, a, b);
  for (int u = 0; u < n; ++ u) dp[i][u] = b[u];
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) scanf("%lf", p + i);
  for (int i = 0; i < n; ++ i) {
    scanf("%d", &m);
    for (int j = 0; j < m; ++ j) {
      int x; scanf("%d", &x);
      S[i].push_back(x - 1);
    }
  }
  solve(VI(n, 1));
  printf("%.10f\n", dp[0][0]);
  return 0;
}