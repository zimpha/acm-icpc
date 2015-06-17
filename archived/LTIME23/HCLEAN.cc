#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, d; scanf("%d%d", &n, &d);
    vector<vi> ret(1 << n, vi(n, 0));
    for (int i = 0; i < n; ++ i) {
      scanf("%d", &ret[0][i]);
    }
    if (d < 4) {puts("-2"); continue;}
    for (int i = 0; i < n; ++ i) {
      int l = 1 << i;
      reverse_copy(ret.begin(), ret.begin() + l, ret.begin() + l);
      for (int j = 0; j < l; ++ j) {
        ret[l + j][i] *= -1;
      }
    }
    for (auto &x: ret) {
      for (auto &y: x) printf("%d ", y);
      puts("");
    }
  }
  return 0;
}
