#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l, r, x; cin >> n >> l >> r >> x;
  int c[100], ret(0);
  for (int i = 0; i < n; ++ i) cin >> c[i];
  for (int msk = 0; msk < (1 << n); ++ msk) {
    int sum = 0, L(1e9), R(0);
    for (int i = 0; i < n; ++ i) if (msk >> i & 1) {
      sum += c[i];
      L = min(L, c[i]);
      R = max(R, c[i]);
    }
    if (sum >= l && sum <= r && R - L >= x) ++ ret;
  }
  cout << ret << endl;
  return 0;
}
