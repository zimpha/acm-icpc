#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
const double eps = 1e-8;
int S[MAXN], N, M;
PII ret[MAXN];

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; ++ i) scanf("%d", S + i);
  LL lsum = 0, rsum = 0;
  for (int i = 0; i < M; ++ i) {
    int left = 0, right = N;
    while (left < right) {
      int mid = (left + right + 1) >> 1;
      LL sum = mid;
      for (int j = 0; j < M; ++ j) if (i != j) {
        sum += ((LL)mid * S[j] + S[i]) / (S[i] + 1);
      }
      if (sum <= N) left = mid;
      else right = mid - 1;
    }
    ret[i].second = left;
    left = 0, right = N * (S[i] != 0);
    while (left < right) {
      int mid = (left + right - 1) >> 1;
      LL sum = mid;
      for (int j = 0; j < M; ++ j) if (i != j) {
        sum += (LL)mid * (S[j] + 1) / S[i];
      }
      if (sum >= N) right = mid;
      else left = mid + 1;
    }
    ret[i].first = left;
    if (ret[i].first > ret[i].second) {
      puts("impossible");
      return 0;
    }
    lsum += ret[i].first, rsum += ret[i].second;
  }
  if (N < lsum || N > rsum) puts("impossible");
  else {
    for (int i = 0; i < M; ++ i) {
      printf("%d %d\n", ret[i].first, ret[i].second);
    }
  }
  return 0;
}