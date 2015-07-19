#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;
const int MAXN = 10000;

flt R[10];

flt sqr(flt x) {return x * x;}
int main() {
  int T, N, P, M, B; scanf("%d", &T);
  scanf("%d%d%d%d", &N, &P, &M, &B);
  for (int i = 1; i <= 4; ++ i) scanf("%lf", R + i);
  flt X = 1.0 / R[3];
  flt Y = 1.0 / R[4];
  flt Z = 4.0 * R[3] / R[1] / R[2] + R[3] * sqr(Y + 1.0 / R[1] - 1.0 / R[2]);
  flt a = (Z + X) / 2 - Y;
  flt b = Y - X - a * 7;
  flt c = X - 9 * a - b * 3;

  flt ret(0);
  for (int _ = 0; _ < T; ++ _) {
    N = (LL)N * P % M + B;
    //cout << N << endl;
    ret += 1.0 / (a * N * N + b * N + c);
  }
  printf("%.6f\n", ret);
  return 0;
}