#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int n, a[100]; scanf("%d", &n);
  for (int i = 0; i <= n; ++ i) scanf("%d", a + i);
  printf("%d %d\n", -a[n - 1] / a[n], a[0] / a[n] * (n % 2 == 0 ? 1 : -1));
  return 0;
}

