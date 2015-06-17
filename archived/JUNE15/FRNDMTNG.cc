#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double flt;
int X, Y, t1, t2;
LL sqr(LL x) {return x * x;}
LL solve(LL a) {
  if (a > 0) {
    if (a >= Y) return (LL)X * Y * 2;
    else if (X + a <= Y) return (a * 2 + X) * X;
    else return (LL)X * Y * 2 - sqr(Y - a);
  }
  else {
    if (-a >= X) return 0;
    else if (Y - a <= X) return (LL)X * Y * 2 - (Y - a * 2) * Y;
    else return sqr(X + a);
  }
}
int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d%d%d%d", &X, &Y, &t1, &t2);
    LL ret = solve(t1) - solve(-t2);
    printf("%.10f\n", 1.0 * ret / ((LL)X * Y * 2));
  }
  return 0;
}
