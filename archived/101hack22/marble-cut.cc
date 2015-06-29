#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int l, b; scanf("%d%d", &l, &b);
    if (l > b) swap(l, b);
    if (l != 2) l = l % 3 * b % 3;
    else l = b % 3 * l;
    if (l == 0) puts("YES");
    else printf("NO %d\n", l);
  }
  return 0;
}