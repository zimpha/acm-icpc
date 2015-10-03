#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int m; double p;
    scanf("%d%lf", &m, &p);
    if (p == 0) puts("1000000000.0 0.0");
    else {
      if (m & 1) {
        double a = (1 + pow(p, m)) / (1 + p);
        double b = 1 - a;
        printf("%.10f %.10f\n", a * 1e9, b * 1e9);
      }
      else {
        double a = (1 - pow(p, m)) / (1 + p);
        double b = 1 - a;
        printf("%.10f %.10f\n", a * 1e9, b * 1e9);
      }
    }
  }
  return 0;
}