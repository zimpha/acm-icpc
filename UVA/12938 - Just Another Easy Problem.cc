#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

bool is[10000];

int main() {
  for (int i = 0; i < 100; ++ i) is[i * i] = 1;
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    int n, ret(0); scanf("%d", &n);
    int d = n / 1000;
    for (int i = 1, m = n; i < d; ++ i) {
      m -= 1000; ret += is[m];
    }
    for (int i = 0, m = n; i < 9 - d; ++ i) {
      m += 1000; ret += is[m];
    }
    d = n / 100 % 10;
    for (int i = 0, m = n; i < d; ++ i) {
      m -= 100; ret += is[m];
    }
    for (int i = 0, m = n; i < 9 - d; ++ i) {
      m += 100; ret += is[m];
    }
    d = n / 10 % 10;
    for (int i = 0, m = n; i < d; ++ i) {
      m -= 10; ret += is[m];
    }
    for (int i = 0, m = n; i < 9 - d; ++ i) {
      m += 10; ret += is[m];
    }
    d = n % 10;
    for (int i = 0, m = n; i < d; ++ i) {
      m -= 1; ret += is[m];
    }
    for (int i = 0, m = n; i < 9 - d; ++ i) {
      m += 1; ret += is[m];
    }
    printf("Case %d: %d\n", cas, ret);
  }
  return 0;
}

