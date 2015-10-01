#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
typedef pair<int, int> PII;

LL mul_mod(LL a, LL n, LL M) {
  LL r(0);
  for (; n; n >>= 1) {
    if (n & 1) r += a;
    a += a;
    if (r >= M) r -= M;
    if (a >= M) a -= M;
  }
  return r;
}

void fib(LL n, LL &x, LL &y, LL M) {
  if (n == 0) {x=y=0; return;}
  if (n == 1) {x=y=1; return;}
  if (n & 1) {
    fib(n - 1, y, x, M);
    y += x; if (y >= M) y -= M;
  }
  else {
    LL a, b; fib(n >> 1, a, b, M);
    y = mul_mod(a, a, M) + mul_mod(b, b, M);
    x = mul_mod(a, b, M) + mul_mod(a, b + M - a, M);
    if (y >= M) y -= M;
    if (x >= M) x -= M;
  }
}

char s[20];
int n;
LL ret;

bool dfs(int d, LL k, LL M) {
  if (d == n) {
    ret = k;
    return true;
  }
  LL up = d ? 10 : 60;
  LL T = d ? M / 10 * 6 : 1;
  for (LL i = 0; i < up; ++ i) {
    LL n = k + T * i, x, y;
    fib(n, x, y, M);
    x /= M / 10;
    if (x == s[d] - '0') {
      if (dfs(d + 1, k + T * i, M * 10)) return true;
    }
  }
  return false;
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  reverse(s, s + n);
  bool flag = dfs(0, 0, 10);
  ret += (LL)6e18;
  if (flag) printf("%llu\n", ret);
  else puts("NIE");
  return 0;
}