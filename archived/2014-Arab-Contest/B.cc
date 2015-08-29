#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const char *s[] = {"Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh"};

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    int a, b; scanf("%d%d", &a, &b);
    printf("Case %d: ", cas);
    if (a < b) swap(a, b);
    if (a == 6 && b == 5) puts("Sheesh Beesh");
    else if (a == b) {
      if (a == 1) puts("Habb Yakk");
      else if (a == 2) puts("Dobara");
      else if (a == 3) puts("Dousa");
      else if (a == 4) puts("Dorgy");
      else if (a == 5) puts("Dabash");
      else puts("Dosh");
    }
    else {
      printf("%s %s\n", s[a - 1], s[b - 1]);
    }
  }
  return 0;
}

