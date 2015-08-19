#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

struct Polygon {
  vector<PII> pt;
  vector<int> Xs, Ys;
  int n, m;
  void init() {
    pt.clear();
    Xs.clear();
    Ys.clear();
  }
  void add(int x, int y) {
    pt.push_back(PII(x, y));
    Xs.push_back(x);
    Ys.push_back(y);
  }
  void build() {
    sort(Xs.begin(), Xs.end());
    sort(Ys.begin(), Ys.end());
    Xs.erase(unique(Xs.begin(), Xs.end()), Xs.end());
    Ys.erase(unique(Ys.begin(), Ys.end()), Ys.end());
    n = m = 0;
    for (auto &p: pt) {
      p.first = lower_bound(Xs.begin(), Xs.end(), p.first) - Xs.begin();
      p.second = lower_bound(Ys.begin(), Ys.end(), p.second) - Ys.begin();
      n = max(n, p.first);
      m = max(m, p.second);
    }
  }
  void rotate() {
    vector<PII> tp;
    for (auto &p: pt) tp.push_back(PII(m - p.second, p.first));
    pt = tp; swap(n, m);
  }
  bool same(const Polygon &r) {
    if (pt.size() != r.pt.size()) return false;
    if (n != r.n || m != r.m) return false;
    for (size_t s = 0; s < pt.size(); ++ s) {
      size_t cnt(0);
      for (size_t i = 0; i < pt.size(); ++ i) {
        if (pt[(s + i) % pt.size()] == r.pt[i]) ++ cnt;
      }
      if (cnt == pt.size()) return true;
    }
    return false;
  }
} A, B;

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    A.init(); B.init();
    for (int i = 0; i < n; ++ i) {
      int x, y; scanf("%d%d", &x, &y);
      A.add(x, y);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
      int x, y; scanf("%d%d", &x, &y);
      B.add(x, y);
    }
    A.build(); B.build();
    if (A.same(B)) puts("yes");
    else {
      A.rotate();
      if (A.same(B)) puts("yes");
      else {
        A.rotate();
        if (A.same(B)) puts("yes");
        else {
          A.rotate();
          if (A.same(B)) puts("yes");
          else puts("no");
        }
      }
    }
  }
  return 0;
}

