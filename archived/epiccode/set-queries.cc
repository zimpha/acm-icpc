#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10, MOD = 1e9 + 9;
const int SIZE = 320, LIM = 500;

template<int M> struct Mint {
  int x;
  Mint(): x(0) { }
  Mint(int y) {x=y%M; if (x<0) x+=M;}
  Mint(long long y) {x=y%M; if (x<0) x+=M;}
  int get() const {return x;}
  bool operator==(const Mint &r) const {return x==r.x;}
  Mint &operator+=(const Mint &r) {if((x+=r.x)>=M) x-=M; return *this;}
  Mint &operator-=(const Mint &r) {if((x+=M-r.x)>=M) x-=M; return *this;}
  Mint &operator*=(const Mint &r) {x=(long long)x*r.x% M; return *this;}
  Mint operator+(const Mint &r) const {return Mint(*this)+=r; }
  Mint operator-(const Mint &r) const {return Mint(*this)-=r; }
  Mint operator*(const Mint &r) const {return Mint(*this)*=r; }
};

struct Node {
  int l, r, t;
  Node() {}
  Node(int l, int r, int t): l(l), r(r), t(t) {}
};

typedef Mint<MOD> mint;
vector<int> S[MAXN], big, bel[MAXN];
int is[SIZE][MAXN], hv[MAXN];
mint sum[MAXN], add[MAXN], a[MAXN];
int n, m, q;

struct BIT {
  mint u[MAXN];
  int n;
  void init(int n) {
    this->n = n;
    for (int i = 0; i <= n; ++ i) u[i] = 0;
  }
  void add(int x, mint v) {
    for (; x <= n; x += ~x & x + 1) u[x] += v;
  }
  mint get(int x) {
    mint r(0);
    for (; x >= 0; x -= ~x & x + 1) r += u[x];
    return r;
  }
} AC;

inline int inter(int a, int b, int c, int d) {
  if (a > c || (a == c && b > d)) swap(a, c), swap(b, d);
  if (a == c) return b - a + 1;
  if (d <= b) return d - c + 1;
  return max(0, b - c + 1);
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0, k, x; i < m; ++ i) {
    scanf("%d", &k); hv[i] = -1;
    for (int _ = 0; _ < k; ++ _) {
      scanf("%d", &x); -- x;
      S[i].push_back(x);
      bel[x].push_back(i);
    }
    sort(S[i].begin(), S[i].end());
    if (k > LIM) {
      hv[i] = big.size();
      big.push_back(i);
    }
  }
  for (size_t i = 0; i < big.size(); ++ i) {
    for (auto &y: S[big[i]]) for (auto &z: bel[y]) {
      is[i][z] ++;
    }
  }
  AC.init(n);
  vector<Node> buff;
  for (int _ = 0; _ < q; ++ _) {
    if (buff.size() == SIZE) {
      for (int i = 0; i < m; ++ i) if (hv[i] == -1) {
        for (auto &x: S[i]) sum[i] += a[x];
      }
      for (int i = 0; i <= n; ++ i) a[i] = 0;
      for (auto &x: buff) a[x.l] += x.t, a[x.r + 1] -= x.t;
      for (int i = 0; i < n; ++ i) a[i + 1] += a[i];
      for (int i = 0; i < m; ++ i) if (hv[i] == -1) {
        for (auto &x: S[i]) sum[i] += a[x];
      }
      for (int i = 0; i < n; ++ i) {
        AC.add(i, a[i]); a[i] = 0;
      }
      buff.clear();
    }
    int op, l, r, x, t; scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d", &x, &t); -- x;
      if (hv[x] == -1) {
        for (auto &v: S[x]) {
          a[v] += t; AC.add(v, t);
        }
        for (size_t i = 0; i < big.size(); ++ i) {
          sum[big[i]] += (LL)t * is[i][x];
        }
      }
      else add[x] += t;
    }
    else if (op == 2) {
      int x; scanf("%d", &x); -- x;
      mint ret = sum[x];
      for (size_t i = 0; i < big.size(); ++ i) {
        ret += add[big[i]] * is[i][x];
      }
      if (hv[x] == -1) {
        for (auto &v: S[x]) ret += a[v];
        for (auto &v: buff) {
          int l = lower_bound(S[x].begin(), S[x].end(), v.l) - S[x].begin();
          int r = upper_bound(S[x].begin(), S[x].end(), v.r) - S[x].begin();
          ret += (LL)v.t * (r - l);
        }
      }
      printf("%d\n", ret.get());
    }
    else if (op == 3) {
      scanf("%d%d%d", &l, &r, &t); -- l; -- r;
      for (auto &v: big) {
        int x = lower_bound(S[v].begin(), S[v].end(), l) - S[v].begin();
        int y = upper_bound(S[v].begin(), S[v].end(), r) - S[v].begin();
        sum[v] += (LL)t * (y - x);
      }
      buff.push_back(Node(l, r, t));
    }
    else if (op == 4) {
      int l, r; scanf("%d%d", &l, &r); -- l, -- r;
      mint ret = AC.get(r) - AC.get(l - 1);
      for (auto &v: buff) {
        ret += (LL)v.t * inter(l, r, v.l, v.r);
      }
      for (auto &v: big) {
        int x = lower_bound(S[v].begin(), S[v].end(), l) - S[v].begin();
        int y = upper_bound(S[v].begin(), S[v].end(), r) - S[v].begin();
        ret += add[v] * (y - x);
      }
      printf("%d\n", ret.get());
    }
  }
  return 0;
}