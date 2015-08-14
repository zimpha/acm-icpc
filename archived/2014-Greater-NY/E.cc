#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2000 + 10;
vector<int> ret[MAXN];

int main() {
  ret[1].push_back(1);
  for (int i = 2; i < MAXN; ++ i) {
    int t = -1;
    for (size_t j = 0; j < ret[i - 1].size(); ++ j) {
      if (ret[i - 1][j] == 0) {
        t = j;
        break;
      }
    }
    if (t == -1) t = ret[i - 1].size();
    for (int j = 0; j < t; ++ j) {
      ret[i].push_back(ret[i - 1][j] - 1);
    }
    ret[i].push_back(t + 1);
    for (size_t j = t + 1; j < ret[i - 1].size(); ++ j) {
      ret[i].push_back(ret[i - 1][j]);
    }
  }
  int P; scanf("%d", &P);
  for (int _ = 0; _ < P; ++ _) {
    int K, N; scanf("%d%d", &K, &N);
    printf("%d %d\n", K, (int)ret[N].size());
    vector<int> &v = ret[N];
    for (size_t i = 0; i < v.size(); ++ i) {
      printf("%d", v[i]);
      if ((i + 1) % 10 == 0) puts("");
      else if (i + 1 != v.size()) putchar(' ');
    }
    if (v.size() % 10) puts("");
  }
  return 0;
}
