#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 5000 + 10;
LL f[MAXN], g[MAXN];
int a[MAXN], L[MAXN], val[MAXN];

struct Node {
  int r;
  LL v;
  Node() {}
  Node(int r, LL v): r(r), v(v) {}
};
vector<Node> trans[MAXN];

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++ i) {
      scanf("%d", a + i);
      trans[i].clear();
      L[i] = i; val[i] = a[i];
      for (int c = i; c >= 1; c = L[c] - 1) {
        val[c] = val[c] | a[i];
        while (L[c] - 1 >= 1 && (a[i] | val[L[c] - 1]) == (a[i] | val[c])) {
          L[c] = L[L[c] - 1];
        }
        trans[i].push_back(Node(c - 1, val[c]));
      }
    }
    for (int i = 0; i <= n; ++ i) f[i] = 0;
    for (int j = 1; j <= k; ++ j) {
      for (int i = 1; i <= n; ++ i) {
        g[i] = 0;
        for (auto &x: trans[i]) {
          if (x.r >= j - 1) g[i] = max(x.v + f[x.r], g[i]);
          else break;
        }
      }
      memcpy(f, g, sizeof(g[0]) * (n + 1));
    }
    printf("%lld\n", f[n]);
  }
  return 0;
}