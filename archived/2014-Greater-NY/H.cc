#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 10000 + 10;
int phi[MAXN];

int main() {
  for (int i = 1; i < MAXN; ++ i) phi[i] = i;
  phi[1] = 2;
  for (int i = 2; i < MAXN; ++ i) {
    if (phi[i] == i) {
      for (int j = i; j < MAXN; j += i) phi[j] = phi[j] / i * (i - 1);
    }
    phi[i] += phi[i - 1];
  }
  int P; scanf("%d", &P);
  for (int _ = 0; _ < P; ++ _) {
    int K, N; scanf("%d%d", &K, &N);
    printf("%d ", K);
    N = phi[N] * 3 - 4;
    if (N & 1) printf("%d/%d\n", N, 2);
    else printf("%d\n", N >> 1);
  }
  return 0;
}
