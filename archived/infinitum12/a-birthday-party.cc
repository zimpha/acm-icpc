#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 200 + 10;

template<int M> struct Mint {
  int x;
  Mint(): x(0) { }
  Mint(int y) {x=y%M; if (x<0) x+=M;}
  Mint(long long y) {x=y%M; if (x<0) x+=M;}
  int get() const {return x;}
  bool operator==(const Mint &r) const {return x==r.x;}
  Mint &operator+=(const Mint &r) {if((x+=r.x)>=M) x-=M; return *this;}
  Mint &operator-=(const Mint &r) {if((x+=M-r.x)>=M) x-=M; return *this;}
  Mint &operator*=(const Mint &r) {x=(long long)x*r.x%M; return *this;}
  Mint &operator/=(const Mint &r) {x=(long long)x*r.inv().x%M; return *this;}
  Mint operator+(const Mint &r) const {return Mint(*this)+=r;}
  Mint operator-(const Mint &r) const {return Mint(*this)-=r;}
  Mint operator*(const Mint &r) const {return Mint(*this)*=r;}
  Mint operator/(const Mint &r) const {return Mint(*this)/=r;}
  Mint inv() const {
    int a = x, b = M, u = 1, v = 0;
    while(b) {
      int t = a / b;
      a -= t * b; std::swap(a, b);
      u -= t * v; std::swap(u, v);
    }
    if(u < 0) u += M;
    Mint res; res.x = (unsigned)u;
    return res;
  }
};

typedef Mint<99991> mint;

mint A[MAXN][MAXN];

LL pm(LL a, LL n, LL p) {
  LL r(1);
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % p;
    a = a * a % p;
  }
  return r;
}

int main() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) A[i][j] = 0;
    A[i][i] = 1;
    int m; scanf("%d", &m);
    for (int j = 0; j < m; ++ j) {
      int x; scanf("%d", &x); -- x;
      A[i][x] = -1;
    }
  }
  int rk = -1;
  for (int i = 0; i < n; ++ i) {
    int r(-1);
    for (int j = rk + 1; j < n; ++ j) {
      if (A[j][i].x != 0 && r == -1) r = j;
    }
    if (r == -1) continue; else ++ rk;
    mint dv = A[r][i];
    for (int j = 0; j < n; ++ j) swap(A[rk][j], A[r][j]/=dv);
    for (int j = 0; j < n; ++ j) if (j != rk) {
      dv = -A[j][i].x;
      for (int k = 0; k < n; ++ k) A[j][k] += A[rk][k] * dv;
    }
  }
  printf("%d\n", (int)pm(99991, n - rk - 1, 1e9 + 7));
  return 0;
}

