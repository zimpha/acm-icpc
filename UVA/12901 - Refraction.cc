#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int W, H, x, xe, ye;
double mu, sb, cb;

double sqr(double x) {return x * x;}
bool check(double h) {
  double L = W - 1.0 * (H - h) * (xe - W) / (ye - H);
  double d = h * sb / cb;
  return L - d < x;
}

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    scanf("%d%d%d%d%d%lf", &W, &H, &x, &xe, &ye, &mu);
    sb = (xe - W) / sqrt(sqr(xe - W) + sqr(ye - H)) / mu;
    cb = sqrt(1.0 - sb * sb);
    if (W - H * sb / cb < x) {
      puts("Impossible");
      continue;
    }
    double left = 0, right = H;
    for (int _ = 0; _ < 100; ++ _) {
      double mid = (left + right) / 2;
      if (check(mid)) left = mid;
      else right = mid;
    }
    printf("%.4f\n", left);
  }
  return 0;
}