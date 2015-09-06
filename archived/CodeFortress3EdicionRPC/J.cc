#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, d; scanf("%d%d", &n, &d);
    char s[1000]; scanf("%s", s);
    int q; scanf("%d", &q);
    while (q --) {
      int cnt[10]; memset(cnt, 0, sizeof(cnt));
      vector<PII> pt;
      int x; scanf("%d", &x);
      for (int i = 0; s[i]; ++ i) {
        int p = s[i] - '1';
        if (i >= x * p && cnt[p] < d) {
          cnt[p] ++;
          if (cnt[p] == d) pt.push_back(PII(i - p * x + 1, p + 1));
        }
      }
      if (pt.size() != n) puts("INVALID SIMULATION");
      else {
        sort(pt.begin(), pt.end());
        flt median, avg(0), sigma(0);
        if (n & 1) median = pt[n / 2].first;
        else median = (pt[n / 2].first + pt[n / 2 - 1].first) * 0.5;
        for (auto &x: pt) avg += x.first;
        avg /= n;
        for (auto &x: pt) sigma += (x.first - avg) * (x.first - avg);
        sigma /= n - 1;
        flt as = abs(3 * (avg - median) / sigma);
        if (as <= 0.2) {
          printf("ORDER OF RACING:");
          for (auto &x: pt) printf(" %d", x.second);
          puts("");
        }
        else puts("INVALID SIMULATION");
      }
    }
  }
  return 0;
}
