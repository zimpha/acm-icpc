#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

template <int fun(int, int)> struct ST {
  const static int MAXN = 100000;
  int mx[MAXN][20], lg[MAXN], n;
  void build(int a[], int n) {
    lg[0]=-1; this->n=n;
    for (int i=1;i<=n;++i) lg[i]=lg[i>>1]+1;
    for (int i=0;i<n;++i) mx[i][0]=a[i];
    for (int j=1;(1<<j)<=n;++j) {
      for (int i=0;i+(1<<j)<=n;++i) {
        mx[i][j]=fun(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
      }
    }
  }
  int ask(int a, int b) {
    if (a>b) swap(a,b); int k=lg[b-a+1];
    return fun(mx[a][k],mx[b-(1<<k)+1][k]);
  }
};

struct SA {
  static const int MAXN = 100000 + 10;
  int cnt[MAXN], tr[2][MAXN], ts[MAXN];
  int sa[MAXN], rk[MAXN], ht[MAXN], n;
  static int min(int a, int b) {return a < b ? a : b;}
  ST<min> st_sa, st_ht;
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
  void get_height(char *s, int *sa, int *rk, int *h, int n) {
    for (int i=0,l=0,j;i<n;++i) {
      if (!rk[i]) continue;
      for (j=sa[rk[i]-1];i+l<n&&j+l<n&&s[i+l]==s[j+l];) l++;
      h[rk[i]]=l; if (l) l--;
    }
  }
  inline int lcp(int a, int b) {
    a=rk[a],b=rk[b];
    if (a>b) swap(a,b);
    return st_ht.ask(a+1,b);
  }
  void build(int n, char s[]) {
    construct(s, sa, rk, n);
    get_height(s, sa, rk, ht, n);
    st_sa.build(sa, n);
    st_ht.build(ht, n);
    this->n = n;
  }
  int solve(int I, int len) {
    I = rk[I];
    if (I >= n - 1) return -1;
    int left = I, right = n;
    while (left + 1 < right) {
      int mid = (left + right) >> 1;
      if (st_ht.ask(I + 1, mid) < len) right = mid;
      else left = mid;
    }
    if (right == n) return -1;
    I = right;
    if (n - sa[I] < len) {
      left = I, right = n;
      while (left + 1 < right) {
        int mid = (left + right) >> 1;
        if (st_sa.ask(I, mid) <= n - len) right = mid;
        else left = mid;
      }
      if (right == n) return -1;
    }
    I = right; left = I, right = n;
    while (left + 1 < right) {
      int mid = (left + right) >> 1;
      if (st_ht.ask(I + 1, mid) < len) right = mid;
      else left = mid;
    }
    return st_sa.ask(I, left) + 1;
  }
} sa;

const int MAXN = 100000 + 10;
char s[MAXN];
int n;

int main() {
  scanf("%s", s); n = strlen(s);
  sa.build(n, s);
  int q; scanf("%d", &q);
  for (int _ = 0; _ < q; ++ _) {
    int idx, len; scanf("%d%d", &idx, &len);
    printf("%d\n", sa.solve(idx - 1, len));
  }
  return 0;
}

