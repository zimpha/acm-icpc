#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  int s = 0;
  for (int i = n; i >= 1; -- i) {
    m -= i;
    if (m <= 0) {
      printf("%d\n", n - i + 1);
      return 0;
    }
  }
  puts("-1");
  return 0;
}