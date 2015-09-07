#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%d", &n);
    int a = INT_MAX, b = INT_MIN;
    for (int i = 0; i < n; ++ i) {
      int x; scanf("%d", &x);
      a = min(a, x); b = max(b, x);
    }
    if (a != b) puts("Happy Birthday Tutu!");
    else puts("Better luck next time!");
  }
  return 0;
}

