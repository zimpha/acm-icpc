#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 200000 + 10;
LL T[MAXN << 2];
LL A[MAXN], K;
int N;

#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

LL mul(LL a, LL b, LL n) {
  if (a == 0 || b == 0) return 0;
  if (n <= 2e9) return a * b % n;
  if (n <= 1e12) {
    LL M = sqrt(n);
    LL x = b / M, y = n % M;
    return (a * x % n * M + a * y) % n;
  }
  LL r(0);
  if (a < b) swap(a, b);
  for (; b; b >>= 1) {
    if (b & 1) r = r + a;
    a = a + a;
    if (a >= n) a -= n;
    if (r >= n) r -= n;
  }
  return r;
  double EPS = 1e-12;
  return a * b-(LL)((long double)a/n*b+EPS)*n;
}

void build(int rt, int l, int r) {
  if (l + 1 == r) {
    scanf("%lld", &A[l]);
    A[l] %= K;
    T[rt] = A[l];
    return;
  }
  build(lson, l, mid);
  build(rson, mid, r);
  T[rt] = mul(T[lson], T[rson], K);
}

LL ask(int rt, int l, int r, int L, int R) {
  if (L >= R) return 1;
  if (L <= l && R >= r) return T[rt];
  LL ret(1);
  if (L < mid) ret = mul(ret, ask(lson, l, mid, L, R), K);
  if (R > mid) ret = mul(ret, ask(rson, mid, r, L, R), K);
  return ret;
}

int main() {
  scanf("%lld%d", &K, &N);
  build(1, 0, N);
  LL s(A[0]);
  int mx(1e9);
  for (int i = 0, j = 0; i < N; ++ i) {
    j = max(j, i);
    while (j + 1 < N && s != 0) s = mul(s, A[j + 1], K), ++ j;
    if (s == 0) mx = min(mx, j - i + 1);
    s = ask(1, 0, N, i + 1, j + 1);
  }
  if (mx > N) puts("NONE");
  else {
    printf("Minimum interval length: %d\n", mx);
    puts("Found intervals:");
    for (int i = 0; i + mx <= N; ++ i) {
      LL s = ask(1, 0, N, i, i + mx);
      if (s == 0) printf("[%d, %d]\n", i + 1, i + mx);
    }
  }
  return 0;
}