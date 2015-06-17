#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 5000 + 10, MOD = 1e9 + 7;
char s[MAXN];
int C[MAXN][MAXN], cnt[MAXN], ret[MAXN];
int sa[MAXN], rk[MAXN], ht[MAXN];

struct SA {
  static const int MAXN = 100000 + 10;
  int cnt[MAXN], tr[2][MAXN], ts[MAXN];
  void construct(char *s, int *sa, int *rk, int n, int m=256) {
    int i,k,*x=tr[0],*y=tr[1];
    memset(cnt,0,sizeof(cnt[0])*m);
    for (i=0;i<n;++i) cnt[(int)s[i]]++;
    partial_sum(cnt,cnt+m,cnt);
    for (i=0;i<n;++i) rk[i]=cnt[(int)s[i]]-1;
    for (k=1;k<=n;k<<=1) {
      for (i=0;i<n;++i) x[i]=rk[i],y[i]=i+k<n?rk[i+k]+1:0;
      fill(cnt,cnt+n+1,0); 
      for (i=0;i<n;++i) cnt[y[i]]++;
      partial_sum(cnt,cnt+n+1,cnt);
      for (i=n-1;i>=0;--i) ts[--cnt[y[i]]]=i;
      fill(cnt,cnt+n+1,0);
      for (i=0;i<n;++i) cnt[x[i]]++;
      partial_sum(cnt,cnt+n+1,cnt);
      for (i=n-1;i>=0;--i) sa[--cnt[x[ts[i]]]]=ts[i];
      for (i=rk[sa[0]]=0;i+1<n;++i) {
        rk[sa[i+1]]=rk[sa[i]]+(x[sa[i]]!=x[sa[i+1]]||y[sa[i]]!=y[sa[i+1]]);
      }
    }
  }
  void get_ht(char *s, int *sa, int *rk, int *h, int n) {
    for (int i=0,l=0,j;i<n;++i) {
      if (!rk[i]) continue;
      for (j=sa[rk[i]-1];i+l<n&&j+l<n&&s[i+l]==s[j+l];) l++;
      h[rk[i]]=l; if (l) l--;
    }
  }
} AC;

int main() {
  for (int i = 0; i < MAXN; ++ i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++ j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
  }
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int N, Q; scanf("%d%d", &N, &Q);
    scanf("%s", s);
    AC.construct(s, sa, rk, N);
    AC.get_ht(s, sa, rk, ht, N);
    for (int i = 0; i <= N; ++ i) cnt[i] = 0;
    for (int l = 1; l <= N; ++ l) {
      for (int i = 1, j; i < N; i = j + 1) {
        for (j = i; j < N && ht[j] >= l; ++ j);
        if (i == j && ht[i] < l) {
          if (N - sa[i - 1] >= l) cnt[1] ++;
        }
        else cnt[j - i + 1] ++;
      }
      if (ht[N - 1] < l && N - sa[N - 1] >= l) cnt[1] ++;
    }
    for (int k = 1; k <= N; ++ k) {
      ret[k] = 0;
      for (int i = k; i <= N; ++ i) if (cnt[i]) {
        ret[k] = (ret[k] + (LL)C[i][k] * cnt[i] % MOD) % MOD;
      }
    }
    while (Q --) {
      int k; scanf("%d", &k);
      assert(k > 0);
      if (k <= N) printf("%d\n", ret[k]);
      else puts("0");
    }
  }
  return 0;
}
