#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;

int A[MAXN];

int main() {
  int n, q; scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++ i) {
    int x; scanf("%d", &x);
    x = abs(x) & 1;
    A[i] = A[i - 1] ^ x;
  }
  for (int i = 0; i < q; ++ i) {
    int l, r; scanf("%d%d", &l, &r);
    if (A[r] ^ A[l - 1]) puts("Odd");
    else puts("Even");
  }
  return 0;
}

