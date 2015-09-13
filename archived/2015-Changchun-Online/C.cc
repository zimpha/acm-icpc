#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 1000000, MOD = 1e9 + 7;
int a[MAXN], m;
LL ret[MAXN];

struct Node {
  int n, id;
  bool operator < (const Node &rhs) const {
    return n < rhs.n;
  }
} ql[MAXN];


LL calc(LL s, LL l) {
  return (s + s + l - 1) * l / 2 % MOD;
}

void gao() {
  LL sum(0), tot(0);
  for (int i = 1, j(0); i < MAXN; ++ i) {
    sum += a[i]; 
    LL len;
    while (j < m && ql[j].n <= sum) {
      if (ql[j].n == sum) len = a[i];
      else len = ql[j].n + a[i] - sum;
      ret[ql[j].id] = (tot + calc(sum - a[i] + 1, len) * i) % MOD;
      ++ j;
    }
    tot += calc(sum - a[i] + 1, a[i]) * i % MOD;
  }
}

int main() {
  a[1] = 1; a[2] = 2; m = 2;
  for (int i = 2; i < MAXN && m < MAXN; ++ i) {
    for (int _ = 0; _ < a[i] && m < MAXN; ++ _) a[m ++] = i;
  }
  int T; scanf("%d", &T);
  for (int i = 0; i < T; ++ i) {
    scanf("%d", &ql[i].n);
    ql[i].id = i;
  }
  m = T;
  sort(ql, ql + T);
  gao();
  for (int i = 0; i < T; ++ i) printf("%lld\n", ret[i]);
  return 0;
}