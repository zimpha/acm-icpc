#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    static char s[100010]; scanf("%s", s);
    int n = strlen(s);
    sort(s, s + n);
    n = unique(s, s + n) - s;
    if (n & 1) puts("Counter Terrorist");
    else puts("Terrorist");
  }
  return 0;
}

