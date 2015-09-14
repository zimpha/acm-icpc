#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2000 + 10;
vector<int> col[MAXN];
PII ret[MAXN];

int main() {
  int n, k; scanf("%d%d", &k, &n);
  int m = k / n;
  for (int i = 0; i < k; ++ i) {
    int c; scanf("%d", &c);
    if (c == -1) c = 0;
    else -- c;
    col[c].push_back(i);
    ret[i] = PII(-1, -1);
  }
  vector<int> over, need;
  for (int i = 0; i < n; ++ i) {
    if (col[i].size() >= m) over.push_back(i);
    else need.push_back(i);
  }
  while (!need.empty()) {
    int x = need.back(), y = over.back();
    need.pop_back();
    int extra = m - col[x].size();
    for (auto &i: col[x]) ret[i] = PII(x, y);
    while (extra --) {
      ret[col[y].back()] = PII(x, y);
      col[y].pop_back();
    }
    if (col[y].size() < m) {
      over.pop_back();
      need.push_back(y);
    }
  }
  while (!over.empty()) {
    int x = over.back(); over.pop_back();
    for (auto &i: col[x]) ret[i] = PII(x, x);
  }
  puts("Yes");
  for (int i = 0; i < k; ++ i) {
    printf("%d %d\n", ret[i].first + 1, ret[i].second + 1);
  }
  return 0;
}
