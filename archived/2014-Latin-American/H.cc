#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 10;
int A[MAXN], n;

int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; ++ i) scanf("%d", A + i);
    sort(A, A + n); A[n] = A[0];
    int r1 = 0, r2 = 0;
    for (int i = 0; i < n; ++ i) {
      int diff = abs(A[i] - A[i + 1]);
      if (i & 1) r1 += min(diff, 24 - diff);
      else r2 += min(diff, 24 - diff);
    }
    printf("%d\n", min(r1, r2));
  }
  return 0;
}
