#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;

int main() {
  const flt s2 = sqrt(2.0), s6 = sqrt(6.0);
  LL i, k, s, a, b; cin >> i >> k >> s >> a >> b;
  if (i == k) printf("%.10f\n", (a + b) / pow(2, s));
  else if (i > k) {
    if (i % 2 == k % 2) {
      LL n = (i - k) / 2;
      s += 4 * n;
      printf("%.10f\n", (a + b) / pow(2, s));
    }
    else {
      -- i;
      flt aa = (s2 * (a + b) - s6 * (a - b)) / 16;
      flt bb = (s6 * (a + b) + s2 * (a - b)) / 16;
      LL n = (i - k) / 2;
      s += 4 * n;
      printf("%.10f\n", (aa + bb) / pow(2, s));
    }
  }
  else {
    if (i % 2 == k % 2) {
      LL n = (k - i) / 2;
      s -= n * 4;
      printf("%.10f\n", (a + b) / pow(2, s));
    }
    else {
      ++ i;
      flt aa = s2 * (a + b) - s6 * (a - b);
      flt bb = s2 * (a - b) + s6 * (a + b);
      LL n = (k - i) / 2;
      s -= n * 4;
      printf("%.10f\n", (aa + bb) / pow(2, s));
    }
  }
  return 0;
}
