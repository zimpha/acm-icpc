#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const static int MAXN=50, inf=1e9;
const double eps = 1e-8;
struct KM {
  typedef double VAL;
  VAL lx[MAXN],ly[MAXN],sl[MAXN];
  int px[MAXN],py[MAXN],sy[MAXN],fa[MAXN],n;
  void aug(int v) {
    sy[v] = py[v];
    if (px[sy[v]] != -2) aug(px[sy[v]]);
  }
  bool find(int v, const VAL w[][MAXN]) {
    for (int i=0;i<n;++i) if (!~py[i]) {
      if (sl[i]>lx[v]+ly[i]-w[v][i]+eps) {
        sl[i]=lx[v]+ly[i]-w[v][i]; fa[i] = v;
      }
      if (fabs(lx[v]+ly[i]-w[v][i])<=eps) {
        py[i] = v;
        if (!~sy[i]) {aug(i); return 1;}
        if (~px[sy[i]]) continue;
        px[sy[i]]=i;
        if (find(sy[i],w)) return 1;
      }
    }
    return 0;
  }
  VAL gao(int _n, const VAL w[][MAXN]) {
    n=_n; fill(sy,sy+n,-1); fill(ly,ly+n,0);
    for (int i=0;i<n;++i) lx[i]=*max_element(w[i],w[i]+n);
    for (int i(0),flag;i<n;++i) {
      for (int j=0;j<n;++j)px[j]=py[j]=-1,sl[j]=inf;
      px[i]=-2; if (find(i,w)) continue;
      for (flag=0; !flag; ) {
        VAL m=inf;
        for (int j=0;j<n;++j) if (!~py[j]) m=min(m,sl[j]);
        for (int j=0;j<n;++j) {
          if (~px[j]) lx[j]-=m;
          if (~py[j]) ly[j]+=m;
          else sl[j]-=m;
        }
        for (int j=0;j<n;++j) if (!~py[j]&&!sl[j]) {
          py[j]=fa[j];
          if (!~sy[j]) {aug(j);flag=1;break;}
          px[sy[j]]=j;
          if (find(sy[j],w)) {flag=1;break;}
        }
      }
    }
    VAL ret(0);
    for (int i=0;i<n;++i) ret+=w[sy[i]][i];
    return ret;
  }
} ac;

int a[MAXN][MAXN], b[MAXN][MAXN];
double w[MAXN][MAXN];
int n;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
      for (int j = 0; j < n; ++ j) {
        scanf("%d/%d", &a[i][j], &b[i][j]);
        a[i][j] = b[i][j] - a[i][j];
        if (a[i][j] == 0) w[i][j] = -inf;
        else w[i][j] = log(a[i][j]) - log(b[i][j]);
      }
    }
    ac.gao(n, w);
    LL x(1), y(1);
    for (int i = 0; i < n; ++ i) {
      x *= a[ac.sy[i]][i];
      y *= b[ac.sy[i]][i];
      LL g = __gcd(x, y);
      x /= g; y /= g;
    }
    printf("%lld/%lld\n", y - x, y);
  }
  return 0;
}
