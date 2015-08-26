#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1000 + 10, inf = 1e9;

PII mx[MAXN];
int K, N;

int main() {
  scanf("%d%d", &K, &N);
  fill(mx, mx + N, PII(inf, inf));
  for (int i = 0; i < K; ++ i) {
    for (int j = 0; j < N; ++ j) {
      int x; scanf("%d", &x);
      mx[j].second = min(mx[j].second, x);
      if (mx[j].second < mx[j].first) {
        swap(mx[j].first, mx[j].second);
      }
    }
  }
  int sum = 0, ret = 0;
  for (int i = 0; i < N; ++ i) sum += mx[i].first;
  for (int i = 0; i < N; ++ i) {
    if (mx[i].first * 2 < mx[i].second) {
      ret = max(ret, sum + mx[i].first);
    }
    else {
      ret = max(ret, sum + mx[i].second - mx[i].first);
    }
  }
  printf("%d\n", ret);
  return 0;
}