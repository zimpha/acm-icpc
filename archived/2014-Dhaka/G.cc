#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2001, MOD = 1e9 + 7;

template<int M> struct Mint {
  int x;
  Mint(): x(0) {}
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

typedef Mint<MOD> mint;

mint f[MAXN][MAXN][16], g[MAXN][MAXN][16];
mint C[MAXN][MAXN], fac[MAXN], ret[MAXN];

void init(int n) {
  fac[0] = 1;
  for (int i = 1; i < n; ++ i) fac[i] = fac[i - 1] * i;
  for (int i = 0; i < n; ++ i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++ j) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
  f[0][0][0] = 1;
  for (int i = 0; i < n - 1; ++ i) {
    for (int j = 0; j <= i; ++ j) {
      for (int msk = 0; msk < 16; ++ msk) if (f[i][j][msk].get()) {
        int sp = msk >> 3, sc = msk >> 2 & 1;
        int sf = msk >> 1 & 1, sl = msk & 1;
        mint &add = f[i][j][msk];
        if (sp == 0) {// put i in prev
          if (i == 0) f[i + 1][j + 1][sc << 3 | 1] += add;
          else if (i == 1) f[i + 1][j + 1][(sc << 3) | 2 | sl] += add;
          else f[i + 1][j + 1][(sc << 3) | (sf << 1) | sl] += add;
        }
        if (sc == 0) {// put i in curr
          if (i == 0) f[i + 1][j + 1][8 | 2] += add;
          else f[i + 1][j + 1][8 | (sf << 1) | sl] += add;
        }
        // put i in next
        f[i + 1][j + 1][(sc << 3) | 4 | (sf << 1) | sl] += add;
        // don't put
        f[i + 1][j][(sc << 3) | (sf << 1) | sl] += add;
      }
    }
  }
}

void solve(int n) {
  for (int i = n - 2; i <= n; ++ i) {
    for (int j = 0; j <= i; ++ j) {
      for (int msk = 0; msk < 16; ++ msk) {
        if (i == n - 2) g[i][j][msk] = f[i][j][msk];
        else g[i][j][msk] = 0;
      }
    }
  }
  for (int i = n - 2; i < n; ++ i) {
    for (int j = 0; j <= i; ++ j) {
      for (int msk = 0; msk < 16; ++ msk) if (g[i][j][msk].get()) {
        int sp = msk >> 3, sc = msk >> 2 & 1;
        int sf = msk >> 1 & 1, sl = msk & 1;
        mint &add = g[i][j][msk];
        if (sp == 0) {// put i in prev
          if (i == n - 2) g[i + 1][j + 1][(sc << 3) | (sl << 2) | (sf << 1) | sl] += add;
          else g[i + 1][j + 1][(sc << 3) | (sf << 1) | sl] += add;
        }
        if (sc == 0) {// put i in curr
          if (i == n - 2) g[i + 1][j + 1][8 | (sl << 2) | (sf << 1) | sl] += add;
          else g[i + 1][j + 1][8 | (sf << 1) | sl] += add;
        }
        // put i in next
        if (i == n - 1 && !sf) g[i + 1][j + 1][15] += add;
        else if (i == n - 2 && !sl) g[i + 1][j + 1][(sc << 3) | 4 | (sf << 1) | 1] += add;
        // dont put
        if (i == n - 2) g[i + 1][j][(sc << 3) | (sl << 2) | (sf << 1) | sl] += add;
        else g[i + 1][j][(sc << 3) | (sf << 1) | sl] += add;
      }
    }
  }
}

int main() {
  init(MAXN);
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    int n, k; scanf("%d%d", &n, &k);
    printf("Case %d: ", cas);
    if (n == 3) {puts("6"); continue;};
    solve(n);
    for (int i = 0; i <= n; ++ i) {
      ret[i] = 0;
      for (int msk = 0; msk < 16; ++ msk) {
        ret[i] += g[n][i][msk];
      }
      ret[i] *= fac[n - i];
    }
    mint ans(0);
    for (int i = n; i >= k; -- i) {
      ans += ret[i];
      for (int j = i + 1; j <= n; ++ j) {
        if ((j - i) & 1) ans -= C[j][j - i] * ret[j];
        else ans += C[j][j - i] * ret[j];
      }
    }
    printf("%d\n", ans.get());
  }
  return 0;
}