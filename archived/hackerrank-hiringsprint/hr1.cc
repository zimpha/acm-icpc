#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

static const int MAXN = 400000 + 10;

template <int fun(int, int)> struct ST {
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

int max(int a, int b) {return a > b ? a : b;}
int min(int a, int b) {return a < b ? a : b;}

struct SA {
  int cnt[MAXN], tr[2][MAXN], ts[MAXN];
  int sa[MAXN], rk[MAXN], ht[MAXN], n;
  ST<&min> ht_rmq;
  ST<&max> sa_rmq;
  void construct(char *s, int n, int m=256) {
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
  void build(char *s, int n) {
    construct(s, n); get_height(s, sa, rk, ht, n);
    ht_rmq.build(ht, n); sa_rmq.build(sa, n);
    this->n = n;
  }
  int lcp(int a, int b) {
    a=rk[a],b=rk[b];
    if (a>b) swap(a,b);
    return ht_rmq.ask(a+1,b);
  }
  int get_left(int x, int m) {//sa[i] >= m, i <= x;
    int left = 0, right = x;
    while (left < right) {
      int mid = (left + right + 1) >> 1;
      if (sa_rmq.ask(mid, x) >= m) left = mid;
      else right = mid - 1;
    }
    if (sa_rmq.ask(left, x) < m) return -1;
    else return left;
  }
  int get_right(int x, int m) {//sa[i] >= m, i >= x;
    int left = x, right = n - 1;
    while (left < right) {
      int mid = (left + right - 1) >> 1;
      if (sa_rmq.ask(x, mid) >= m) right = mid;
      else left = mid + 1;
    }
    if (sa_rmq.ask(left, x) < m) return -1;
    else return left;
  }
  int solve(int n) {
    int ret(0);
    for (int i = 1; i < n; ++ i) {
      int x = rk[i], m = n * 2 - i;
      int l = get_left(x, m);
      int r = get_right(x, m);
      if (l != -1) ret = max(ret, min(lcp(i, sa[l]), n - i));
      if (r != -1) ret = max(ret, min(lcp(i, sa[r]), n - i));
    }
    return ret;
  }
} AC;

char s[MAXN];
int main() {
  scanf("%s", s); int n = strlen(s);
  for (int i = 0; i < n; ++ i) s[i + n] = s[n - i - 1];
  AC.build(s, n * 2);
  cout << AC.solve(n) << endl;
  return 0;
}