#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 1000000 + 10, D = 30, inf = 1e9;

struct Node {
  int x, y, id;
  Node() {}
  Node(int a, int b, int i): x(a), y(b), id(i) {}
  bool operator < (const Node &rhs) const {
    return x < rhs.x || (x == rhs.x && y < rhs.y);
  }
};

vector<Node> Q[MAXN], day[MAXN];
int skill[MAXN], dp[MAXN], pv[MAXN];
int n, s, dt, mx;

int main() {
  scanf("%d%d%d", &n, &s, &dt);
  for (int i = 1; i <= n; ++ i) {
    int d, l, h; scanf("%d%d%d", &d, &l, &h);
    day[d].push_back(Node(l, h, i));
    skill[i] = h; mx = max(mx, d);
  }
  Q[0].push_back(Node(s, 0, 0));
  dp[0] = 0, skill[0] = s;
  set<PII> S; S.insert(PII(s, 0));
  for (int d = 1; d <= mx; ++ d) {
    if (d >= D) {
      for (auto &cs: day[d - D]) if (dp[cs.id] != inf) {
        S.insert(PII(skill[cs.id] - dp[cs.id], cs.id));
      }
    }
    vector<Node> res;
    for (auto &cs: day[d]) {
      int i = cs.id; dp[i] = inf; pv[i] = -1;
      auto it = S.lower_bound(PII(cs.x, -1));
      if (it != S.end()) {
        res.push_back(Node(skill[i], 0, i));
        dp[i] = 0, pv[i] = it->second;
        continue;
      }
      for (int j = 1; j < D; ++ j) if (d > j) {
        vector<Node> &pt = Q[d - j];
        if (pt.empty()) continue;
        auto it = lower_bound(pt.begin(), pt.end(), Node(cs.x, -inf, 0));
        if (it == pt.end()) continue;
        int tire = (it->y + dt) >> (j - 1);
        if (tire < dp[i]) dp[i] = tire, pv[i] = it->id;
      }
      if (dp[i] != inf) {
        res.push_back(Node(skill[i] - dp[i], dp[i], i));
      }
    }
    sort(res.begin(), res.end());
    for (size_t i = 0; i < res.size(); ++ i) {
      Node &cs = res[i];
      if (i && cs.x == res[i - 1].x) continue;
      while (!Q[d].empty() && cs.y <= Q[d].back().y) Q[d].pop_back();
      Q[d].push_back(cs);
    }
  }
  int ret(s), id(0);
  for (int i = 1; i <= n; ++ i) if (dp[i] != inf) {
    if (skill[i] - dp[i] > ret) ret = skill[i] - dp[i], id = i;
  }
  vector<int> res;
  for (; id; id = pv[id]) res.push_back(id);
  reverse(res.begin(), res.end());
  printf("%d %d\n", ret, (int)res.size());
  for (auto &x: res) printf("%d ", x); puts("");
  return 0;
}
