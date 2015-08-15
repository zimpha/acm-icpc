#include <bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
const int MAXN = 100000 + 10;

int a[MAXN][2];

struct BIT {
  int u[MAXN], n;
  void init(int n) {
    memset(u, 0, sizeof(u));
    this->n = n;
  }
  void add(int x, int v) {
    for (; x <= n; x += ~x & x + 1) u[x] += v;
  }
  int get(int x) {
    int r = 0;
    for (; x >= 0; x -= ~x & x + 1) r += u[x];
    return r;
  }
};

struct ST {
  BIT A, B;
  void init(int n) {
    A.init(n); B.init(n);
  }
  void add(int r, int v) {
    A.add(r, r * v); B.add(r, -v);
  }
  void add(int l, int r, int v) {// (l, r]
    add(r, v); add(l, -v);
  }
  int get(int r) {
    return A.get(r) + B.get(r) * r;
  }
  int get(int l, int r) {// (l, r]
    return get(r) - get(l);
  }
} five, two;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, q, v[2]; scanf("%d%d", &n, &q);
    five.init(n); two.init(n);
    for (int i = 0; i < n; ++ i) {
      int x; scanf("%d", &x); v[0] = v[1] = 0;
      while (x % 2 == 0 && x > 0) x /= 2, v[0] ++;
      while (x % 5 == 0 && x > 0) x /= 5, v[1] ++;
      two.add(i, i + 1, v[0]);
      five.add(i, i + 1, v[1]);
    }
    while (q --) {
      int op, l, r, x; scanf("%d%d%d", &op, &l, &r); -- l;
      if (op == 1) {
        v[0] = two.get(l, r); v[1] = five.get(l, r);
        printf("%d\n", min(v[0], v[1]));
      }
      else {
        int x; scanf("%d", &x); v[0] = v[1] = 0;
        while (x % 2 == 0 && x > 0) x /= 2, v[0] ++;
        while (x % 5 == 0 && x > 0) x /= 5, v[1] ++;
        two.add(l, r, v[0]);
        five.add(l, r, v[1]);
      }
    }
  }
  return 0;
}