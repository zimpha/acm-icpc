#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int n, k; scanf("%d%d", &n, &k);
  vector<int> v; 
  for (int i = 0; i < k; ++ i) {
    int x; scanf("%d", &x);
    v.push_back(x);
  }
  v.push_back(-1); v.push_back(n + 2);
  sort(v.begin(), v.end());
  int ret(0);
  for (int i = 1; i <= k + 1; ++ i) {
    int a = v[i - 1] + 1, b = v[i] - 1;
    int l = b - a - 1;
    if (l >= 0) {
      ret += l / 2 + (l & 1);
    }
  }
  printf("%d\n", ret + k);
  return 0;
}

