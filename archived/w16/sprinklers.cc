#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 10000 + 10, inf = 2e9 + 10;

int dp[MAXN], p[MAXN];

struct ST {
  const static int MAXN = 200000;
  int mx[MAXN][20], lg[MAXN], n;
  void build(int a[], int n) {
    lg[0]=-1; this->n=n;
    for (int i=1;i<=n;++i) lg[i]=lg[i>>1]+1;
    for (int i=0;i<n;++i) mx[i][0]=a[i];
    for (int j=1;(1<<j)<=n;++j) {
      for (int i=0;i+(1<<j)<=n;++i) {
        mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
      }
    }
  }
  int ask(int a, int b) {
    if (a>b) swap(a,b); int k=lg[b-a+1];
    return max(mx[a][k],mx[b-(1<<k)+1][k]);
  }
} AC;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, m; scanf("%d%d", &n, &m);
    int s, q; scanf("%d%d", &s, &q);
    for (int i = 0; i <= n; ++ i) p[i] = 0;
    for (int i = 1; i <= m; ++ i) {
      int x; scanf("%d", &x);
      p[x] = x;
    }
    AC.build(p, n + 1);
    int ret(inf), E;
    vector<int> ans;
    for (int d = 0, i; d <= n; ++ d) {
      vector<int> pt;
      for (i = 1; i <= n; ) {
        int l = max(1, i - d), r = min(i + d, n);
        r = AC.ask(l, r);
        if (r == 0) break;
        i = r + d + 1;
        pt.push_back(r);
      }
      if (i > n) {
        int tmp = s * pt.size() + q * d;
        if (tmp < ret) {
          ret = tmp;
          E = d;
          ans = pt;
        }
      }
    }
    printf("%d %d\n", (int)ans.size(), E);
    for (size_t i = 0; i < ans.size(); ++ i) {
      printf("%d ", ans[i]);
    }
    puts("");
  }
  return 0;
}