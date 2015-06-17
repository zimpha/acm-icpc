#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 500000 + 10, inf = 1e9;
struct Node {
  int add;
  map<LL, set<int> > mp;
  void ins(int p, int x) {
    mp[x].insert(p);
  }
  void del(int p, int x) {
    auto &S = mp[x];
    S.erase(p);
    if (S.empty()) mp.erase(x);
  }
  PII get(int x) {
    x -= add;
    auto it = mp.find(x);
    if (it != mp.end() && it->second.size()) {
      return PII(*(it->second.begin()), *(it->second.rbegin()));
    }
    else return PII(inf, -inf);
  }
} T[1000];

int a[MAXN];
int n, q, m;

int main() {
  scanf("%d%d", &n, &q); m = sqrt(n);
  for (int i = 0; i < n; ++ i) {
    scanf("%d", a + i);
    T[i / m].ins(i, a[i]);
  }
  for (int _ = 0; _ < q; ++ _) {
    int op, l, r, x;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d%d", &l, &r, &x); -- l, -- r;
      if (x == 0) continue;
      int pl = l / m, pr = r / m;
      if (pl == pr) {
        for (int i = l; i <= r; ++ i) {
          T[pl].del(i, a[i]);
          a[i] += x; if (a[i] > inf) a[i] = inf + 1;
          T[pl].ins(i, a[i]);
        }
      }
      else {
        for (int i = pl + 1; i < pr; ++ i) {
          T[i].add += x;
          if (T[i].add > inf) T[i].add = inf + 1;
        }
        for (int i = pl * m + m - 1; i >= l; -- i) {
          T[pl].del(i, a[i]); 
          a[i] += x; if (a[i] > inf) a[i] = inf + 1;
          T[pl].ins(i, a[i]);
        }
        for (int i = pr * m; i <= r; ++ i) {
          T[pr].del(i, a[i]);
          a[i] += x; if (a[i] > inf) a[i] = inf + 1;
          T[pr].ins(i, a[i]);
        }
      }
    }
    else {
      scanf("%d", &x);
      int c = (n - 1) / m + 1;
      PII r(inf, -inf);
      for (int i = 0; i < c; ++ i) {
        PII tmp = T[i].get(x);
        r.first = min(r.first, tmp.first);
        r.second = max(r.second, tmp.second);
      }
      if (r.first == inf) puts("-1");
      else printf("%d\n", r.second - r.first);
    }
  }
  return 0;
}

