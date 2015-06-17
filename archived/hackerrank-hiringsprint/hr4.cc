#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int n, q; scanf("%d", &n);
  vector<int> s(n);
  for (int i = 0; i < n; ++ i) scanf("%d", &s[i]);
  sort(s.begin(), s.end());
  scanf("%d", &q);
  for (int _ = 0; _ < q; ++ _) {
    int x; scanf("%d", &x);
    printf("%d\n", int(lower_bound(s.begin(), s.end(), x) - s.begin()));
  }
  return 0;
}

