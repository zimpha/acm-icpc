#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  vector<int> s;
  for (int i = 1; i * i <= 1e9; ++ i) s.push_back(i * i);
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%d", &n);
    printf("%d\n", int(upper_bound(s.begin(), s.end(), n) - s.begin()));
  }
  return 0;
}

