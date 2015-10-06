#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 300 + 10, inf = 1e9;
PII s[MAXN], t[MAXN];
int n;

struct KM {
  typedef double VAL;
  VAL lx[MAXN],ly[MAXN],sl[MAXN];
  int px[MAXN],py[MAXN],sy[MAXN],fa[MAXN],n;
  void aug(int v) {
    sy[v]=py[v]; if (px[sy[v]]!=-2) aug(px[sy[v]]);
  }
  bool find(int v, const VAL w[][MAXN]) {
    for (int i=0;i<n;++i) if (!~py[i]) {
      if (sl[i]>lx[v]+ly[i]-w[v][i]) {
        sl[i]=lx[v]+ly[i]-w[v][i]; fa[i] = v;
      }
      if (lx[v]+ly[i]==w[v][i]) {
        py[i]=v; if (!~sy[i]) {aug(i); return 1;}
        if (~px[sy[i]]) continue;
        px[sy[i]]=i; if (find(sy[i],w)) return 1;
      }
    }
    return 0;
  }
  VAL gao(int _n, const VAL w[][MAXN], VAL m=inf) {
    n=_n; fill(sy,sy+n,-1); fill(ly,ly+n,0);
    for (int i=0;i<n;++i) lx[i]=*max_element(w[i],w[i]+n);
    for (int i(0),flag;i<n;++i) {
      for (int j=0;j<n;++j)px[j]=py[j]=-1,sl[j]=inf;
      px[i]=-2; if (find(i,w)) continue;
      for (flag=0,m=inf; !flag; m=inf) {
        for (int j=0;j<n;++j) if (!~py[j]) m=min(m,sl[j]);
        for (int j=0;j<n;++j) {
          if (~px[j]) lx[j]-=m;
          if (~py[j]) ly[j]+=m;
          else sl[j]-=m;
        }
        for (int j=0;j<n;++j) if (!~py[j]&&!sl[j]) {
          py[j]=fa[j]; if (!~sy[j]) {aug(j);flag=1;break;}
          px[sy[j]]=j; if (find(sy[j],w)) {flag=1;break;}
        }
      }
    }
    VAL ret(0);
    for (int i=0;i<n;++i) ret+=w[sy[i]][i];
    return ret;
  }
} km;

double w[MAXN][MAXN], ret;

double dis(PII &a, PII &b) {
  return hypot(a.first - b.first, a.second - b.second);
}

int main() {
  scanf("%d%*d%*d", &n); ret = 0;
  for (int i = 0; i < n; ++ i) {
    scanf("%d%d%d%d", &s[i].first, &s[i].second, &t[i].first, &t[i].second);
    ret += dis(s[i], t[i]);
  }
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      w[i][j] = -dis(s[i], t[j]);
    }
  }
  ret -= km.gao(n, w);
  printf("%.10f\n", ret);
  return 0;
}
