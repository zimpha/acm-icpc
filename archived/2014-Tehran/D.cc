#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int mp[200][200], n, s, t;

int main() {
  while (scanf("%d%d%d", &n, &s, &t) == 3 && n) {
    for (int i = 0; i <= 150; ++ i) {
      for (int j = 0; j <= 150; ++ j) {
        mp[i][j] = 1e9;
      }
      mp[i][i] = 0;
    }
    for (int i = 0; i < n; ++ i) {
      int m; scanf("%d", &m);
      vector<int> a(m);
      for (int j = 0; j < m; ++ j) scanf("%d", &a[j]);
      sort(a.begin(), a.end());
      for (int j = 1; j < m; ++ j) {
        mp[a[j - 1]][a[j]] = a[j] - a[j - 1];
        mp[a[j]][a[j - 1]] = a[j] - a[j - 1];
      }
    }
    for (int k = 0; k <= 150; ++ k) {
      for (int i = 0; i <= 150; ++ i) {
        for (int j = 0; j <= 150; ++ j) {
          mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
        }
      }
    }
    printf("%d\n", mp[s][t]);
  }
  return 0;
}

