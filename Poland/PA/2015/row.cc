#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
  LL k, a, b, ret(0); cin >> k >> a >> b;
  for (LL f = 1; f <= min(b / k + 1, 1458ll); ++ f) {
    LL n = k * f, s(0);
    for (LL m = n; m; m /= 10) s += (m % 10) * (m % 10);
    if (s == f && a <= n && n <= b) ++ ret;
  }
  cout << ret << endl;
  return 0;
}
