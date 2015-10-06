#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL pm(LL a, LL n, LL m) {
  LL r=1;
  for (;n;n>>=1,a=a*a%m) if (n&1) r=r*a%m;
  return r;
}
LL phi(LL n) {//O(sqrt{N})
  LL ret=n;
  for (LL i=2;i*i<=n;++i) if (n%i==0) {
    ret=ret/i*(i-1);
    while (n%i==0) n/=i;
  }
  if (n>1) ret=ret/n*(n-1);
  return ret;
}

int solve(int a, int m) {
  int n = phi(m); a %= m;
  if (__gcd(a, m) != 1) return -1;
  vector<int> fac;
  for (int i = 1; i * i <= n; ++ i) {
    if (n % i == 0) {
      fac.push_back(i);
      fac.push_back(n / i);
    }
  }
  sort(fac.begin(), fac.end());
  for (auto &x: fac) {
    if (pm(a, x, m) == 1) return x;
  }
  return -1;
}

int is_squarefree(int n) {
  int r(1);
  for (int i = 2; i * i <= n; ++ i) {
    if (n % i == 0) {
      r = r * (i - 1) / __gcd(r, i - 1);
      int c(0);
      while (n % i == 0) n /= i, ++ c;
      if (c > 1) return -1;
    }
  }
  if (n > 1) r = r * (n - 1) / __gcd(r, n - 1);
  return r;
}

int main() {
  int n; scanf("%d", &n);
  int m = is_squarefree(n);
  if (m == -1) puts("-1");
  else if (n == 2) puts("1");
  else printf("%d\n", solve(n, m));
  return 0;
}