#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PII;

  static const int MAXN = 100000 + 10;
  int cnt[MAXN], tr[2][MAXN], ts[MAXN];
  int sa[MAXN], rk[MAXN], ht[MAXN];
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

char s[MAXN];
int a[MAXN], rt[MAXN];

namespace ST {
  const int SIZE = MAXN << 6;
  LL cnt[SIZE], sum[SIZE];
  int ls[SIZE], rs[SIZE], sz;
  void init() {
    cnt[0] = sum[0] = 0;
    ls[0] = rs[0] = 0;
    sz = 1;
  }
  void ins(int &o, int p, int l, int r, int v) {
    o = sz ++; ls[o] = ls[p]; rs[o] = rs[p];
    cnt[o] = cnt[p] + 1; sum[o] = sum[p] + v;
    if (l == r) return;
    int m = (l + r) >> 1;
    if (v <= m) ins(ls[o], ls[p], l, m, v);
    else ins(rs[o], rs[p], m + 1, r, v);
  }
  PII operator + (const PII &a, const PII &b) {
    return PII(a.first + b.first, a.second + b.second);
  }
  PII ask(int o, int p, int l, int r, int v) {
    if (r <= v) return PII(cnt[o] - cnt[p], sum[o] - sum[p]);
    int m = (l + r) >> 1;
    if (v <= m) return ask(ls[o], ls[p], l, m, v);
    else return ask(ls[o], ls[p], l, m, v) + ask(rs[o], rs[p], m + 1, r, v);
  }
};

int main() {
  scanf("%s", s);
  int n = strlen(s);
  construct(s, sa, rk, n);
  get_ht(s, sa, rk, ht, n);
  for (int i = 0; i < n; ++ i) {
    int l = 0;
    if (i) l = max(l, ht[i]);
    if (i + 1 < n) l = max(l, ht[i + 1]);
    if (l != n - sa[i]) a[sa[i]] = sa[i] + l;
    else a[sa[i]] = n;
  }
  rt[n] = 0; ST::init();
  for (int i = n - 1; i >= 0; -- i) {
    ST::ins(rt[i], rt[i + 1], 0, n, a[i]);
  }
  int q; scanf("%d", &q);
  for (int _ = 0; _ < q; ++ _) {
    int l, r; scanf("%d%d", &l, &r); -- l;
    PII ret = ST::ask(rt[l], rt[r], 0, n, r);
    printf("%lld\n", r * ret.first - ret.second);
  }
  return 0;
}

