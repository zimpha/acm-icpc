#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const double PI = acos(-1.0);

int main() {
  double r1, r2, l; 
  scanf("%lf%lf%lf", &r1, &r2, &l);
  if (r1 < r2) swap(r1, r2);
  double left = r1 + r2, right = l / 2;
  for (int _ = 0; _ < 100; ++ _) {
    double mid = (left + right) / 2;
    double dr = r1 - r2;
    double theta = acos(dr / mid);
    double h = mid * sin(theta) * 2;
    h += r1 * 2 * (PI - theta);
    h += r2 * 2 * theta;
    if (h > l) right = mid;
    else left = mid;
  }
  printf("%.4f\n", left);
  return 0;
}

