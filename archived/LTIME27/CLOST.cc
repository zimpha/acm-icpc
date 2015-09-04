#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, m; scanf("%d%d", &n, &m);
    char s[2010];
    for (int i = 0; i < n; ++ i) s[i] = '.';
    vector<PII> a(m);
    for (int i = 0; i < m; ++ i) {
      scanf("%d%d", &a[i].first, &a[i].second);
    }
    sort(a.begin(), a.end(), greater<PII>());
    for (auto &x: a) {
      int l = x.first, r = x.second, p(0);
      for (int i = l; i <= r; ++ i) {
        if (s[i] == '.') s[i] = p ? ')' : '(', p ^= 1;
      }
    }
    for (int i = 0; i < n; ++ i) {
      if (s[i] == '.') s[i] = '(';
    }
    s[n] = 0; puts(s);
  }
  return 0;
}
