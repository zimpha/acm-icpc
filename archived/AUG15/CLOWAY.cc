#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
const int MAXN = 55, MAXK = 20240 + 10, MAXQ = 200000 + 10;
const int MOD = 1e9 + 7;

LL fac[MAXK], inv[MAXK], ans[MAXQ], H[MAXK][MAXN];
vector<int> ql[MAXN][MAXN];
int G[MAXN][MAXN][MAXN], mk[MAXN][MAXN];
int L[MAXQ], R[MAXQ], K[MAXQ];
int N[MAXN], T, Q;

void mul(LL A[MAXN][MAXN], int B[MAXN][MAXN], int n) {
  static int C[MAXN][MAXN];
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      C[i][j] = A[j][i] % MOD; A[j][i] = 0;
    }
  }
  for (int k = 0; k < n; ++ k) {
    for (int i = 0; i < n; ++ i) {
      for (int j = 0; j < n; ++ j) {
        A[i][j] += C[k][i] * B[k][j];
      }
    }
  }
}

LL pm(LL a, LL n) {
  LL r(1);
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % MOD;
    a = a * a % MOD;
  }
  return r;
}

inline int Binom(int n, int m) {
  return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int buffer[1 << 21];

void karatsuba(int *a, int *b, LL *ret, int d) {
    int m = d / 2;
    int *ar = a, *al = a + m, *br = b, *bl = b + m;
    LL *x1 = ret, *x2 = ret + d, *x3 = ret + d * 2;
    int *asum = buffer + d * 5;
    int *bsum = buffer + d * 5 + m;
    if (d <= 16) {
        memset(ret, 0, sizeof(ret[0]) * (d * 2));
        for (int i = 0; i < d; ++ i) {
          for (int j = 0; j < d; ++ j) {
            ret[i + j] += (LL)a[i] * b[j];
          }
        }
        for (int i = 0; i < d + d - 1; ++ i) ret[i] %= MOD;
        return;
    }

    for (int i = 0; i < m; ++ i) {
        asum[i] = al[i] + ar[i];
        bsum[i] = bl[i] + br[i];
        if (asum[i] >= MOD) asum[i] -= MOD;
        if (bsum[i] >= MOD) bsum[i] -= MOD;
    }

    karatsuba(ar, br, x1, m);
    karatsuba(al, bl, x2, m);
    karatsuba(asum, bsum, x3, m);

    for (int i = 0; i < d; ++ i) {
      int sub = MOD - (x1[i] + x2[i]) % MOD;
      x3[i] += sub;
    }
    for (int i = 0; i < d; ++ i) ret[i + m] += x3[i];
}

bool gauss(LL a[][MAXN], LL b[MAXN], int n) {
  for(int k=0,i,j,s;k<n;++k){
    for(s=k,i=k+1;i<n;++i) if (a[i][k]) s=i;
    if (a[s][k] == 0) continue;
    if(s!=k){
      swap(b[s],b[k]);
      for(i=k;i<n;++i)swap(a[s][i],a[k][i]);
    }
    for(j=k+1;j<n;++j){
      LL t = MOD - a[j][k] * pm(a[k][k], MOD - 2) % MOD;
      b[j] += b[k] * t % MOD;
      if (b[j] >= MOD) b[j] -= MOD;
      for(i=k+1;i<n;++i) {
        a[j][i]+=t*a[k][i] % MOD;
        if (a[j][i] >= MOD) a[j][i] -= MOD;
      }
    }
  }
  for(int i=n-1;i>=0;--i) if (a[i][i]) {
    b[i] = b[i] * pm(a[i][i], MOD - 2) % MOD;
    for(int j=0;j<i;++j) {
      int sub = a[j][i] * b[i] % MOD;
      while (b[j] < sub) b[j] += MOD;
      b[j] -= sub;
    }
  }
  return true;
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < MAXK; ++ i) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = pm(fac[i], MOD - 2);
  }
  scanf("%d", &T);
  for (int i = 1, m; i <= T; ++ i) {
    scanf("%d%d", N + i, &m);
    for (int j = 0; j < m; ++ j) {
      int u, v; scanf("%d%d", &u, &v);
      -- u; -- v;
      G[i][u][v] = G[i][v][u] = 1;
    }
  }
  scanf("%d", &Q);
  int ms = 0;
  for (int i = 0; i < Q; ++ i) {
    scanf("%d%d%d", L + i, R + i, K + i);
    ql[L[i]][R[i]].push_back(i);
    mk[L[i]][R[i]] = max(mk[L[i]][R[i]], K[i]);
    ms = max(ms, K[i]);
  }

  static LL f[MAXK], h[MAXK << 6];
  static LL b[MAXN], mt[MAXN][MAXN];

  for (int i = 1; i <= T; ++ i) {
    int n = N[i]; memset(mt, 0, sizeof(mt));
    for (int j = 0; j < n; ++ j) mt[j][j] = 1;
    for (int k = 0; k <= n * 2; ++ k) {
      f[k] = 0; h[k] = 0;
      for (int j = 0; j < n; ++ j) f[k] += mt[j][j];
      for (int j = 0; j <= k; ++ j) {
        h[k] += Binom(k, j) * f[j] % MOD;
      }
      f[k] %= MOD; h[k] %= MOD; mul(mt, G[i], n);
    }
    memset(mt, 0, sizeof(mt));
    for (int j = 0; j < n; ++ j) {
      for (int k = 0; k < n; ++ k) mt[j][k] = h[n + j - k];
      b[j] = h[n + j + 1];
    }
    gauss(mt, b, n);
    for (int k = 0; k <= ms; ++ k) {
      if (k > n * 2) {
        h[k] = 0;
        for (int j = 0; j < n; ++ j) {
          h[k] += b[j] * h[k - j - 1] % MOD;
        }
        h[k] %= MOD;
      }
      H[k][i] = h[k];
    }
  }
  static int x[MAXK], y[MAXK];
  for (int l = 1; l <= T; ++ l) {
    for (int n = 0; n <= ms; ++ n) {
      x[n] = y[n] = inv[n];
      if (n & 1) y[n] = MOD - y[n];
    }
    for (int r = l; r <= T; ++ r) {
      int mx = mk[l][r], size(mx + 1), cut(128);
      for (int n = 0; n <= ms; ++ n) x[n] = (LL)x[n] * H[n][r] % MOD;
      if (mx == 0) continue;
      for (; cut * 8 < size; cut <<= 1);
      for (; size % cut; ++ size);

      karatsuba(x, y, h, size); h[0] = 0;
      for (int i = 1; i <= mx; ++ i) {
        h[i] = h[i] % MOD * fac[i] % MOD;
        h[i] += h[i - 1];
      }
      for (auto &i: ql[l][r]) ans[i] += h[K[i]];
    }
  }
  for (int i = 0; i < Q; ++ i) printf("%lld\n", ans[i] % MOD);
  return 0;
}