#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 100000 + 10;
char s[MAXN];
int t[MAXN], r[MAXN];
int a[MAXN], b[MAXN], n, m;

int main() {
  int T; scanf("%d", &T);
  while (T --) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++ i) {
      scanf("%d", a + i);
      s[i - 1] = 'N', b[i] = 0;
    }
    for (int i = 1; i < n; ++ i) scanf("%d%d", t + i, r + i);
    int unsure = 0, first = false, used = 1e9;
    for (int _ = 1; _ < n; ++ _) {
      //cout << t[_] << " " << r[_] << endl;
      if (r[_] == 1) {
        if (!first) {
          vector<int> ok;
          for (int i = 1; i <= m; ++ i) {
            if (a[i] <= unsure) ok.push_back(i);
          }
          for (int i = _; i < n; ++ i) b[t[i]] = true;
          for (auto &v : ok) if (!b[v]) {
            used = min(used, a[v]);
            s[v - 1] = 'Y';
          }
          first = true;
        }
        if (t[_] == 0) unsure ++;
        else a[t[_]] --;
      }
      else {
        if (t[_] == 0) unsure ++;
        else a[t[_]] --;
      }
    }
    if (used == 1e9) used = 0;
    //cout << unsure << " " << used << endl;
    for (int i = 1; i <= m; ++ i) {
      if (s[i - 1] != 'Y') {
        s[i - 1] = "NY"[a[i] <= unsure - used];
      }
    }
    s[m] = 0;
    puts(s);
  }
  return 0;
}