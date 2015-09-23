#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 200000 + 10, MAXK = 230;

struct Node {
  int a, c, s;
  bool operator < (const Node &rhs) const {
    if (c != rhs.c) return c < rhs.c;
    else if (a != rhs.a) return a < rhs.a;
    else return s < rhs.s;
  }
} r[MAXN];

int dp[MAXN][MAXK];
int n, m;

inline int get(int i, int j) {return i * m + j + i;}
inline void upd(int &x, int y) {x = (x == -1 || x > y) ? y : x;}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++ i) {
    scanf("%d%d%d", &r[i].a, &r[i].c, &r[i].s);
    if (r[i].a == 1) r[i].a = 4;
  }
  sort(r, r + n);
  memset(dp, -1, sizeof(dp)); dp[0][0] = 0;
  for (int i = 0; i < n; ++ i) {
    int a = r[i].a, s = r[i].s;
    for (int j = 0; j <= m; ++ j) {
      for (int k = 0; k <= j; ++ k) {
        int now = get(i, j), cost = dp[now][k];
        if (!~cost) continue;
        upd(dp[get(i + 1, j)][k], cost);
        if (a <= 3 && j < m) {
          upd(dp[get(i + 1, j + 1)][k + 1], cost + s);
        }
        if (a >= 3 && k) {
          upd(dp[get(i + 1, j)][k - 1], cost + s);
        }
      }
    }
  }
  printf("%d\n", dp[get(n, m)][0]);
  return 0;
}