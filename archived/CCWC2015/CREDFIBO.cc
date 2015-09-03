#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 100000 + 10;

int fib[MAXN], pw[MAXN];

int main() {
  fib[0] = 0; fib[1] = 1; pw[0] = 1; pw[1] = 3;
  for (int i = 2; i < MAXN; ++ i) {
    fib[i] = (fib[i - 1] + fib[i - 2]) % 4;
    pw[i] = pw[i - 1] * 3 % 4;
  }
  for (int i = 1; i < MAXN; ++ i) {
    if (fib[i] == 3) fib[i] = fib[i - 1] + 1;
    else fib[i] = fib[i - 1];
  }
  int q; scanf("%d", &q);
  for (int _ = 0; _ < q; ++ _ ) {
    int l, r; scanf("%d%d", &l, &r);
    int c = fib[r] - fib[l - 1];
    printf("%d\n", pw[c]);
  }
  return 0;
}

