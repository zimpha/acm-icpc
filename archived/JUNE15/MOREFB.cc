#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1 << 18, p = 99991;
const LL P1 = 786433, P2 = 1811939329, M = P1 * P2;

LL pm(LL a, LL n, LL m) {
  LL r=1;
  for (;n;n>>=1,a=a*a%m) if (n&1) r=r*a%m;
  return r;
}

LL pw[MAXN];
int a[MAXN], n, m;

template<LL P, LL g>
struct NTT {
  void trans(LL a[], int n, bool inv=false) {
    LL w=1,d=pm(g,(P-1)/n,P),t; int i,j,c,s;
    if (inv) {
      for (i=1,j=n-1;i<j;swap(a[i++],a[j--]));
      for (t=pm(n,P-2,P),i=0;i<n;++i) a[i]=a[i]*t%P;
    }
    for (s=n>>1;s;s>>=w=1,d=d*d%P) {
      for (c=0;c<s;++c,w=w*d%P) {
        for (i=c;i<n;i+=s<<1) {
          a[i|s]=(a[i]+P-(t=a[i|s]))*w%P;
          a[i]=(a[i]+t)%P;
        }
      }
    }
    for (i=1;i<n;++i) {
      for (j=0,s=i,c=n>>1;c;c>>=1,s>>=1) j=j<<1|s&1;
      if (i<j) swap(a[i],a[j]);
    }
  }
};
NTT<P1, 10> ntt1;
NTT<P2, 13> ntt2;

void exgcd(LL a,LL b,LL &g,LL &x,LL &y) {
  if (!b) x=1,y=0,g=a;
  else {exgcd(b,a%b,g,y,x);y-=x*(a/b);}
}
inline LL mul_mod(LL a, LL b, LL m) {
  LL r = 0;
  for (a %= m; b; b >>= 1) {
    if (b & 1) r += a;
    a <<= 1; if (a >= m) a -= m;
  }
  return r % m;
}
LL crt(LL a, LL b) {
  LL xa, ya, xb, yb, g;
  exgcd(P2, P1, g, xa, ya);
  exgcd(P1, P2, g, xb, yb);
  if (xa < 0) xa += M;
  if (xb < 0) xb += M;
  return (mul_mod(a * P2, xa, M) + mul_mod(P1 * b, xb, M)) % M;
}

typedef vector<LL> Poly;
Poly convolution(const Poly &a, const Poly &b) {
  int n = a.size(), m = b.size();
  int s = 1 << (32 - __builtin_clz(n + m - 2));
  static LL u1[MAXN], v1[MAXN];
  static LL u2[MAXN], v2[MAXN];
  for (int i = 0; i < s; ++ i) u1[i] = u2[i] = (i < n) ? a[i] : 0;
  for (int i = 0; i < s; ++ i) v1[i] = v2[i] = (i < m) ? b[i] : 0;
  ntt1.trans(u1, s, 0); ntt1.trans(v1, s, 0);
  ntt2.trans(u2, s, 0); ntt2.trans(v2, s, 0);
  for (int i = 0; i < s; ++ i) {
    u1[i] = u1[i] * v1[i] % P1;
    u2[i] = u2[i] * v2[i] % P2;
  }
  ntt1.trans(u1, s, 1); ntt2.trans(u2, s, 1);
  Poly w(n + m - 1);
  for (int i = 0; i < n + m - 1; ++ i) {
    w[i] = crt(u1[i], u2[i]) % p;
  }
  return w;
}

Poly solve(int l, int r) {
  if (l + 1 == r) return {1, pw[l]};
  int m = (l + r) >> 1;
  Poly f = solve(l, m);
  Poly g = solve(m, r);
  return convolution(f, g);
}

int main() {
  LL s = 10104, u = (s + 1 + p) >> 1, v = 1 - u + p;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++ i) scanf("%d", a + i);
  for (int i = 0; i < n; ++ i) pw[i] = pm(u, a[i], p);
  LL ret = solve(0, n)[m];
  for (int i = 0; i < n; ++ i) pw[i] = pm(v, a[i], p);
  ret += p - solve(0, n)[m];
  ret = ret * pm(s, p - 2, p) % p;
  cout << ret << endl;
  return 0;
}