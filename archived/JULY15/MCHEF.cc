#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10, MAXK = 500 + 10;

#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

vector<PII> V;
int mx[MAXN << 2], A[MAXN], N, K, M;
LL dp[MAXK];

void build(int rt, int l, int r) {
  mx[rt] = 501;
  if (l + 1 == r) return;
  build(lson, l, mid); build(rson, mid, r);
}
void modify(int rt, int l, int r, int L, int R, int v) {
  if (L <= l && R >= r) {mx[rt] = min(mx[rt], v); return;}
  if (L < mid) modify(lson, l, mid, L, R, v);
  if (R > mid) modify(rson, mid, r, L, R, v);
}
void push(int rt, int l, int r) {
  if (l + 1 == r) {V.push_back(PII(A[l], mx[rt])); return;}
  mx[lson] = min(mx[lson], mx[rt]);
  mx[rson] = min(mx[rson], mx[rt]);
  push(lson, l, mid); push(rson, mid, r);
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    V.clear();
    scanf("%d%d%d", &N, &K, &M);
    LL sum(0);
    for (int i = 0; i < N; ++ i) {
      scanf("%d", A + i);
      sum += A[i];
    }
    build(1, 0, N);
    for (int i = 0; i < M; ++ i) {
      int l, r, v; scanf("%d%d%d", &l, &r, &v);
      modify(1, 0, N, l - 1, r, v);
    }
    push(1, 0, N);
    sort(V.begin(), V.end());
    for (int i = 0; i <= K; ++ i) dp[i] = 0;
    for (int i = 0; i < N; ++ i) {
      if (V[i].first >= 0) break;
      int w = -V[i].first, v = V[i].second;
      for (int j = K; j >= v; -- j) {
        dp[j] = max(dp[j], dp[j - v] + w);
      }
    }
    printf("%lld\n", sum + dp[K]);
  }
  return 0;
}

