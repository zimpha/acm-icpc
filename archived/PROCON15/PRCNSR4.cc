#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; ++ i) {
      scanf("%d", &v[i]);
      printf("%d ", -v[i]);
    }
    puts("");
  }
  return 0;
}