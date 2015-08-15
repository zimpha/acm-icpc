#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
int cnt[MAXN], n;
int r1, r2, ret;

void solve(int v1, int v2) {
  if (v1 == -1 || v2 == -1) return;
  cnt[v1] ++; cnt[v2] ++;
  int mx(cnt[1]), mi(cnt[1]);
  for (int i = 2; i <= n; ++ i) {
    mx = max(mx, cnt[i]);
    mi = min(mi, cnt[i]);
  }
  int tmp(0);
  if (cnt[n - 1] != mx && cnt[n - 1] != mi) ++ tmp;
  if (cnt[n] != mx && cnt[n] != mi) ++ tmp;
  if (tmp > ret) ret = tmp, r1 = v1, r2 = v2;
  cnt[v1] --; cnt[v2] --;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) cnt[i] = 0;
    for (int i = 1; i <= n - 2; ++ i) {
      int x, y; scanf("%d%d", &x, &y);
      cnt[x] ++; cnt[y] ++;
    }
    int m1(-1), m2(-1);
    for (int i = 1; i <= n - 2; ++ i) {
      if (m1 == -1 || cnt[i] > cnt[m1]) m1 = i;
    }
    for (int i = 1; i <= n - 2; ++ i) if (i != m1) {
      if (m2 == -1 || cnt[i] > cnt[m2]) m2 = i;
    }
    cnt[m1] += 2; ret = -1;
    solve(n, n - 1);
    solve(n, m2);
    solve(m2, n - 1);
    solve(m2, m2);
    if (ret == 2) puts("both");
    else if (ret == 1) puts("one");
    else puts("none");
    printf("%d %d\n", m1, r1);
    printf("%d %d\n", m1, r2);
  }
  return 0;
}
