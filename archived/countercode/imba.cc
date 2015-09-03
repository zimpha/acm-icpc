#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%d", &n);
    vector<int> ret;
    for (int i = 0; i < n / 2; ++ i) {
      ret.push_back(n - i);
      ret.push_back(i + 1);
    }
    reverse(ret.begin(), ret.end());
    if (n & 1) printf("%d ", n / 2 + 1);
    for (size_t i = 0; i < ret.size(); ++ i) {
      printf("%d ", ret[i]);
    }
    puts("");
  }
  return 0;
}