#include <bits/stdc++.h>
using namespace std;

int len(int n, int b) {
  int l = 0;
  for (; n; n /= b, ++ l);
  return l;
}

int main() {
  int T; cin >> T;
  for (int _ = 0; _ < T; ++ _) {
    int n, k; cin >> n >> k;
    int left = 2, right = n + 1;
    while (left < right) {
      int mid = (left + right + 1) >> 1;
      if (len(n, mid) >= k) left = mid;
      else right = mid - 1;
    }
    if (len(n, left) == k) puts("YES");
    else puts("NO");
  }
  return 0;
}

