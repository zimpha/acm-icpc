#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 150000 + 10;

struct Node {
  string name;
  int val, id;
  bool operator < (const Node &rhs) const {
    if (val == rhs.val) return id > rhs.id;
    return val < rhs.val;
  }
} P[MAXN];

PII rule[MAXN];
int ret[MAXN];
int n, m, q;

int main() {
  int T; scanf("%d", &T);
  for (int _= 0 ; _ < T; ++ _) {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0, v; i < n; ++ i) {
      char s[300]; scanf("%s%d", s, &v);
      P[i].name = s; P[i].val = v;
      P[i].id = i;
    }
    for (int i = 0; i < m; ++ i) {
      scanf("%d%d", &rule[i].first, &rule[i].second);
      rule[i].first --;
    }
    sort(rule, rule + m);
    priority_queue<Node> Q;
    int sz(0);
    for (int i = 0, j(0); i < n; ++ i) {
      while (j < m && rule[j].first < i) ++ j;
      Q.push(P[i]);
      if (i == rule[j].first) {
        int t = rule[j].second;
        while (!Q.empty() && t) {
          Node a = Q.top(); Q.pop(); -- t;
          ret[sz ++] = a.id;
        }
      }
    }
    while (!Q.empty()) {
      Node a = Q.top(); Q.pop();
      ret[sz ++] = a.id;
    }
    for (int i = 0; i < q; ++ i) {
      int x; scanf("%d", &x);
      if (i) putchar(' ');
      printf("%s", P[ret[-- x]].name.c_str());
    }
    puts("");
  }
  return 0;
}

