#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

bool is_prime(int n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (int i = 2; i * i <= n; ++ i) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  int P; scanf("%d", &P);
  for (int _ = 0; _ < P; ++ _) {
    int K, m; scanf("%d%d", &K, &m);
    printf("%d %d ", K, m);
    if (!is_prime(m)) puts("NO");
    else {
      set<int> S;
      int n = m;
      while (1) {
        int s(0);
        for (; n; n /= 10) s += n % 10 * (n % 10);
        if (S.count(s)) break;
        S.insert(s);
        n = s;
      }
      if (S.count(1)) puts("YES");
      else puts("NO");
    }
  }
  return 0;
}

