#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

struct FastIO {
  static const int S = 131072;
  int wpos; char wbuf[S];
  FastIO() : wpos(0) {}
  inline int xchar() {
    static char buf[S];
    static int len = 0, pos = 0;
    if (pos == len)
      pos = 0, len = fread(buf, 1, S, stdin);
    if (pos == len) return -1;
    return buf[pos ++];
  }
  inline int xuint() {
    int s; scanf("%d", &s); return s;
    int c = xchar(), x = 0;
    while (c <= 32) c = xchar();
    for (;'0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
    return x;
  }
  inline int xint() {
    int t; scanf("%d", &t); return t;
    int s = 1, c = xchar(), x = 0;
    while (c <= 32) c = xchar();
    if (c == '-') s = -1, c = xchar();
    for (; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
    return x * s;
  }
  ~FastIO() {
    if (wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
  }
} io;

const int MAXN = 400000 + 10;

struct ST {
  #define lson (rt<<1)
  #define rson (rt<<1|1)
  #define mid ((l+r)>>1)
  struct Node {
    LL sa, si, sum;
    int add, sz;
    void set(int v) {
      sa += (LL)v * sz;
      sum += si * v;
      add += v;
    }
    void clear() {
      sa = sum = 0;
    }
    Node &operator += (const Node &rhs) {
      sa += rhs.sa; sum += rhs.sum;
      return *this;
    }
  } T[MAXN << 2], ret;
  void upd(int rt) {
    T[rt].sa = T[lson].sa + T[rson].sa;
    T[rt].si = T[lson].si + T[rson].si;
    T[rt].sum = T[lson].sum + T[rson].sum;
    T[rt].sz = T[lson].sz + T[rson].sz;
  }
  void psd(int rt) {
    if (T[rt].add) {
      T[lson].set(T[rt].add);
      T[rson].set(T[rt].add);
      T[rt].add = 0;
    }
  }
  void build(int rt, int l, int r) {
    T[rt].add = 0;
    if (l + 1 == r) {
      T[rt].si = l; T[rt].sz = 1;
      T[rt].sum = 0; T[rt].sa = 0;
      return;
    }
    build(lson, l, mid); build(rson, mid, r);
    upd(rt);
  }
  void ins(int rt, int l, int r, int L, int R) {
    if (L <= l && R >= r) {
      T[rt].set(1);
      return;
    }
    psd(rt);
    if (L < mid) ins(lson, l, mid, L, R);
    if (R > mid) ins(rson, mid, r, L, R);
    upd(rt);
  }
  void ask(int rt, int l, int r, int L, int R) {
    if (L > R) return;
    if (L <= l && R >= r) {
      ret += T[rt];
      return;
    }
    psd(rt);
    if (L < mid) ask(lson, l, mid, L, R);
    if (R > mid) ask(rson, mid, r, L, R);
    upd(rt);
  }
} A, B;

int n, m, q;

LL solveA(int x1, int y1, int x2, int y2) {
  int a = x1 + y1, b = x2 + y2;
  int w = (x2 - x1 + 1), h = (y2 - y1 + 1);
  if (w > h) swap(w, h);

  LL ans(0);
  A.ret.clear();
  A.ask(1, 0, m, a, a + w - 1);
  ans = A.ret.sum - A.ret.sa * (a - 1);
  A.ret.clear();
  A.ask(1, 0, m, a + w - 1, b - w + 2);
  ans += A.ret.sa * w;
  A.ret.clear();
  A.ask(1, 0, m, b - w + 2, b + 1);
  ans += A.ret.sa * (b + 1) - A.ret.sum;
  return ans;
}

LL solveB(int x1, int y1, int x2, int y2) {
  int a = x1 - y2 + n - 1, b = x2 - y1 + n - 1;
  int w = (x2 - x1 + 1), h = (y2 - y1 + 1);
  if (w > h) swap(w, h);

  LL ans(0);
  B.ret.clear();
  B.ask(1, 0, m, a, a + w - 1);
  ans = B.ret.sum - B.ret.sa * (a - 1);
  B.ret.clear();
  B.ask(1, 0, m, a + w - 1, b - w + 2);
  ans += B.ret.sa * w;
  B.ret.clear();
  B.ask(1, 0, m, b - w + 2, b + 1);
  ans += B.ret.sa * (b + 1) - B.ret.sum;
  return ans;
}

int main() {
  int T; T = io.xuint();
  for (int cas = 1; cas <= T; ++ cas) {
    printf("Case #%d:\n", cas);
    n = io.xuint();
    q = io.xuint();
    m = 2 *n - 1;
    A.build(1, 0, m);
    B.build(1, 0, m);
    for (int i = 0; i < q; ++ i) {
      int op = io.xuint();
      if (op == 1) {
        int l = io.xuint() - 2;
        int r = io.xuint() - 1;
        A.ins(1, 0, m, l, r);
      }
      else if (op == 2) {
        int l = io.xint() + n - 1;
        int r = io.xint() + n;
        B.ins(1, 0, m, l, r);
      }
      else {
        int x1 = io.xuint() - 1;
        int x2 = io.xuint() - 1;
        int y1 = io.xuint() - 1;
        int y2 = io.xuint() - 1;
        printf("%lld\n", solveA(x1, y1, x2, y2) + solveB(x1, y1, x2, y2));
      }
    }
  }
  return 0;
}