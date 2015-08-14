#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const double PI = acos(-1.0);

int main() {
  int P; scanf("%d", &P);
  for (int _ = 0; _ < P; ++ _) {
    int K, N, M; scanf("%d%d%d", &K, &N, &M);
    printf("%d ", K);
    double si = sin(PI / N), cs = cos(PI / N);
    double r1 = si / (1.0 - si), R1 = 1.0 + r1;
    for (int i = 1; i < M; ++ i) {
      double R2 = R1 * cs + r1 * si + sqrt(r1 * r1 + 2 * r1 * R1 * cs * si);
      R2 = R2 / (cs * cs);
      double r2 = R2 * si;
      R1 = R2; r1 = r2;
    }
    double len = 2.0 * r1 * (PI + N);
    printf("%.3f %.3f\n", r1, len);
  }
  return 0;
}

