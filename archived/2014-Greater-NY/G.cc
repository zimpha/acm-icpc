#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int P; scanf("%d", &P);
  for (int _ = 0; _ < P; ++ _) {
    int K, x, y; scanf("%d%d%d", &K, &x, &y);
    if (y > x) printf("%d 2 %d %d\n", K, x, y);
    else if (y >= 4) printf("%d 6 1 2 3 %d %d %d\n", K, x + 5 - y, x + 2, x + 3);
    else printf("%d NO PATH\n", K);
  }
  return 0;
}

