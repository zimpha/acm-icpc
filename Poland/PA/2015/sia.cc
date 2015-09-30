#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 500000 + 10;

struct FastIO {
  static const int S = 1310720;
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
  inline LL xll() {
    LL c = xchar(), x = 0;
    while (c <= 32) c = xchar();
    for (;'0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
    return x;
  }
  inline int xint() {
    int c = xchar(), x = 0;
    while (c <= 32) c = xchar();
    for (;'0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
    return x;
  }
  ~FastIO() {
    if (wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
  }
} io;

LL s[MAXN], pre;
int a[MAXN], n, m;
struct P {
  bool x;LL y, z;
  P():x(1), y(0), z(0) {}
  P(bool a, LL b, LL c): x(a), y(b), z(c) {}
  P &operator += (const P &rhs) {
    x &= rhs.x;
    y = rhs.y + rhs.x * y;
    z = rhs.z + rhs.x * z;
    return *this;
  }
  void clr(){x=1,y=z=0;}
};

struct W {
  LL vl, vr, vs;
  P tag;
} T[MAXN << 2];

void mark(int o, int l, int r, const P &p) {
  T[o].tag += p;
  T[o].vl = p.x * T[o].vl + p.y + p.z * a[l];
  T[o].vr = p.x * T[o].vr + p.y + p.z * a[r - 1];
  T[o].vs = p.x * T[o].vs + p.y * (r - l) + (s[l] - s[r]) * p.z;
}
#define ls (o<<1)
#define rs (o<<1|1)
#define mid ((l+r)>>1)
void psd(int o, int l, int r) {
  mark(ls, l, mid, T[o].tag);
  mark(rs, mid, r, T[o].tag);
  T[o].tag.clr();
}
LL ask(int o, int l, int r, LL v) {
  if (T[o].vr <= v) return 0;
  if (T[o].vl > v) {
    LL ret = T[o].vs - v * (r - l);
    mark(o, l, r, P(0, v, 0));
    return ret;
  }
  psd(o, l, r);
  LL ret=ask(ls, l, mid, v)+ask(rs, mid, r, v);
  T[o].vl = T[ls].vl; T[o].vr = T[rs].vr;
  T[o].vs = T[ls].vs + T[rs].vs; return ret;
}

int main() {
  n = io.xint(); m = io.xint();
  for (int i = 0; i < n; ++ i) a[i] = io.xint();
  sort(a, a + n); s[n] = 0;
  for (int i = n - 1; i >= 0; -- i) s[i] = s[i + 1] + a[i];
  for (int i = 0; i < m; ++ i) {
    LL t = io.xll(), v = io.xll();
    mark(1, 0, n, P(1, 0, t - pre));
    printf("%lld\n", ask(1, 0, n, v));
    pre = t;
  }
  return 0;
}