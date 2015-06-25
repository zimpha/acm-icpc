#include <bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef long long LL;
const int MAXN = 200000 + 10, MOD = 1e9 + 7;

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
typedef Mint<MOD> mint;

struct Node {
  mint s[3], p[3], val;
  void set(mint v[3]) {
    for (int i = 0; i < 3; ++ i) {
      val += s[i] * v[i];
      p[i] += v[i];
    }
  }
} T[MAXN << 2];

void upd(int rt) {
  T[rt].val = T[lson].val + T[rson].val;
  for (int i = 0; i < 3; ++ i) {
    T[rt].s[i] = T[lson].s[i] + T[rson].s[i];
  }
}
void psd(int rt) {
  T[lson].set(T[rt].p);
  T[rson].set(T[rt].p);
  T[rt].p[0] = T[rt].p[1] = T[rt].p[2] = 0;
}
void build(int rt, int l, int r) {
  for (int i = 0; i < 3; ++ i) T[rt].p[i] = 0;
  T[rt].val = 0;
  if (l + 1 == r) {
    T[rt].s[0] = 1;
    T[rt].s[1] = l;
    T[rt].s[2] = (LL)l * l % MOD;
    return;
  }
  build(lson, l, mid); build(rson, mid, r);
  upd(rt);
}

void add(int rt, int l, int r, int L, int R, mint v[3]) {
  if (L <= l && R >= r) {
    T[rt].set(v);
    return;
  }
  psd(rt);
  if (L < mid) add(lson, l, mid, L, R, v);
  if (R > mid) add(rson, mid, r, L, R, v);
  upd(rt);
}

mint ask(int rt, int l, int r, int L, int R) {
  if (L <= l && R >= r) return T[rt].val;
  psd(rt);
  mint ret(0);
  if (L < mid) ret += ask(lson, l, mid, L, R);
  if (R > mid) ret += ask(rson, mid, r, L, R);
  return ret;
}

int main() {
  int n, q; scanf("%d%d", &n, &q);
  build(1, 0, n);
  for (int i = 0; i < q; ++ i) {
    int op, x, y; scanf("%d%d%d", &op, &x, &y); -- x;
    if (op == 1) {
      mint v[3];
      v[0] = LL(x - 1) * (x - 2);
      v[1] = 3 - x * 2;
      v[2] = 1;
      add(1, 0, n, x, y, v);
    }
    else {
      printf("%d\n", ask(1, 0, n, x, y).get());
    }
  }
  return 0;
}