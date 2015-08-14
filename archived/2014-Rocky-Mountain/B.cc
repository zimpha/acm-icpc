#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T); 
  for (int _ = 0; _ < T; ++ _) {
    char name[1000]; scanf("%s", name);
    printf("%s ", name);
    int y1, y2, c;
    scanf("%d/%*d/%*d %d/%*d/%*d %d", &y1, &y2, &c);
    if (y1 >= 2010) puts("eligible");
    else if (y2 >= 1991) puts("eligible");
    else if (c >= 41) puts("ineligible");
    else puts("coach petitions");
  }
  return 0;
}

