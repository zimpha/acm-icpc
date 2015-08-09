#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
typedef long long LL;
typedef pair<int, int> PII;

int A[MAXN], P, N, Q, K;
LL ret[MAXN];

struct Query {
  int l, r, id;
  bool operator < (const Query &rhs) const {
    return PII(l / P, r) < PII(rhs.l / P, rhs.r);
  }
} B[MAXN];

namespace BIT {
  int u[MAXN];
  void clr() {
    memset(u, 0, sizeof(u));
  }
  void add(int x, int v) {
    for (; x < MAXN; x += ~x & x + 1) u[x] += v;
  }
  int sum(int x) {
    int r(0);
    for (; x >= 0; x -= ~x & x + 1) r += u[x];
    return r;
  }
  int sum(int l, int r) {
    l = max(l, 1); r = min(r, MAXN - 1);
    if (l > r) return 0;
    return sum(r) - sum(l - 1);
  }
}

int main() {
  scanf("%d%d%d", &N, &Q, &K);
  for (int i = 1; i <= N; ++ i) scanf("%d", A + i);
  for (int i = 0; i < Q; ++ i) {
    scanf("%d%d", &B[i].l, &B[i].r);
    B[i].id = i;
  }
  P = sqrt(N * 2);
  sort(B, B + Q);
  int l = 1, r = 0, pre(-1);
  LL ans(0);
  for (int i = 0; i < Q; ++ i) {
    if (B[i].l / P != pre) {
      ans = 0;
      l = r = B[i].l;
      BIT::clr();
      BIT::add(A[l], 1);
      pre = B[i].l / P;
    }
    while (l < B[i].l) {
      BIT::add(A[l], -1);
      ans -= BIT::sum(A[l] - K, A[l] + K);
      ++ l;
    }
    while (l > B[i].l) {
      -- l;
      ans += BIT::sum(A[l] - K, A[l] + K);
      BIT::add(A[l], 1);
    }
    while (r < B[i].r) {
      ++ r;
      ans += BIT::sum(A[r] - K, A[r] + K);
      BIT::add(A[r], 1);
    }
    ret[B[i].id] = ans;
  }
  for (int i = 0; i < Q; ++ i) printf("%lld\n", ret[i]);
  return 0;
}