#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 4000 + 10;
struct Line {// y = m * x + b
  LL m, b;
};// wiLL maintain lower huLL for maximum
struct HuLLDynamic {
  int h, t;
  Line q[MAXN];
  HuLLDynamic(): h(0), t(-1) {}
  bool empty() const {return h > t;}
  void ins(LL m, LL b) {
    if (h <= t && q[t].m == m) {
      if (b >= q[t].b) -- t;
      else return;
    }
    while (h < t && (q[t].b - b) * (m - q[t - 1].m) <= (m - q[t].m) * (q[t - 1].b - b)) -- t;
    q[++ t] = (Line){m, b};
  }
  LL eval(LL x) {
    while (h < t && q[h].m * x + q[h].b <= q[h + 1].m * x + q[h + 1].b) ++ h;
    return q[h].m * x + q[h].b;
  }
} dp[MAXN];

struct Song {
  int t, p, f;
  bool operator < (const Song &rhs) const {
    return f < rhs.f;
  }
} s[MAXN];

inline LL sqr(LL x) {return x * x;}
int N, T;

int main() {
  scanf("%d%d", &N, &T);
  for (int i = 0; i < N; ++ i) {
    scanf("%d%d%d", &s[i].t, &s[i].p, &s[i].f);
  }
  sort(s, s + N);
  LL ans(0);
  for (int i = 0; i < N; ++ i) {
    for (int t = T; t >= s[i].t; -- t) {
      LL ret(s[i].p);
      if (!dp[t - s[i].t].empty()) {
        ret = max(ret, dp[t - s[i].t].eval(s[i].f) + s[i].p - sqr(s[i].f));
      }
      dp[t].ins(2 * s[i].f, ret - sqr(s[i].f));
      ans = max(ans, ret);
    }
  }
  cout << ans << endl;
  return 0;
}

