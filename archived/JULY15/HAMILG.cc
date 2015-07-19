#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const static int MAXN=2000+10, MAXE = 2000000 + 10; // 最大结点个数

struct Edge {
  int v, nx;
  Edge() {}
  Edge(int a, int b): v(a), nx(b) {}
} E[MAXE];

int G[MAXN], sz;

void addedge(int u, int v) {
  E[sz] = Edge(v, G[u]); G[u] = sz ++;
  E[sz] = Edge(u, G[v]); G[v] = sz ++;
}

class Blossom {
public:
  int mate[MAXN],n,ret;
  int solve(int n, const int G[]) {
    this->n=n;memset(mate,-1,sizeof(mate));
    for (int i=0;i<n;++i) if (mate[i]==-1) aug(i, G);
    for (int i=ret=0;i<n;++i) ret+=(mate[i]>i);
    return ret;
  }
  int next[MAXN],dsu[MAXN],mark[MAXN],vis[MAXN];
  int Q[MAXN], qh, qt;
  int get(int x) {return (x==dsu[x])?x:(dsu[x]=get(dsu[x]));}
  void merge(int a,int b) {dsu[get(a)]=get(b);}
  int lca(int x,int y) {
    static int t=0; ++t;
    for (;;swap(x, y)) if (x != -1) {
      if (vis[x=get(x)]==t) return x; vis[x]=t;
      x=(mate[x]!=-1)?next[mate[x]]:-1;
    }
  }
  void group(int a,int p) {
    for (int b,c;a!=p;merge(a,b),merge(b,c),a=c) {
      b=mate[a],c=next[b];
      if (get(c)!=p) next[c]=b;
      if (mark[b]==2) mark[b]=1, Q[qt ++] = b;
      if (mark[c]==2) mark[c]=1, Q[qt ++] = c;
    }
  }
  void aug(int s, const int G[], int* cc = NULL, int rv = -1) {
    for (int i=0;i<n;++i) {
      next[i]=vis[i]=-1,dsu[i]=i,mark[i]=0;
    }
    Q[0] = s; qh = 0; qt = 1; mark[s]=1;
    while (mate[s]==-1&& qh < qt) {
      int x=Q[qh ++]; if (cc != NULL) cc[x] = 1;
      for (int it = G[x],y; ~it; it = E[it].nx) if (E[it].v != rv) {
        if ((y=E[it].v)!=mate[x]&&get(x)!=get(y)&&mark[y]!=2) {
          if (mark[y]==1) {
            int p=lca(x,y);
            if (get(x)!=p) next[x]=y;
            if (get(y)!=p) next[y]=x;
            group(x,p); group(y,p);
          }
          else if (mate[y]==-1) {
            next[y]=x;
            for (int j=y,k,l;j!=-1;j=l) {
              k=next[j]; l=mate[k];
              mate[j]=k; mate[k]=j;
            }
            break;
          }
          else {
            next[y]=x; Q[qt ++] = mate[y];
            mark[mate[y]]=1; mark[y]=2;
          }
        }
      }
    }
  }
} AC;

struct FastIO {
  static const int S = 1100000;
  int wpos; char wbuf[S];
  FastIO() : wpos(0) {}
  inline int xchar() {
    static char buf[S];
    static int len = 0, pos = 0;
    if (pos == len)
      pos = 0, len = fread(buf, 1, S, stdin);
    if (pos == len) return -1;
    return buf[pos ++];
  }
  inline int xint() {
    int c = xchar(), x = 0;
    while (c <= 32) c = xchar();
    for (;'0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
    return x;
  }
  ~FastIO() {
    if (wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
  }
} io;

int mark[MAXN];

void dfs(int u) {
  mark[u] = true;
  for (int it = G[u]; ~it; it = E[it].nx) {
    int v = AC.mate[E[it].v];
    if (v != -1 && !mark[v]) dfs(v);
  }
}

int main() {
  int T = io.xint();
  for (int _ = 0; _ < T; ++ _) {
    int n = io.xint(), m = io.xint();
    for (int i = 0; i < n; ++ i) G[i] = -1;
    sz = 0;
    for (int i = 0; i < m; ++ i) {
      int u = io.xint(), v = io.xint();
      addedge(u - 1, v - 1);
    }
    int mx = AC.solve(n, G) * 2;
    for (int i = 0; i < n; ++ i) mark[i] = 0;
    for (int i = 0; i < n; ++ i) if (AC.mate[i] == -1) {
      //dfs(i);
      AC.aug(i, G, mark);
    }
    int ret(0);
    for (int i = 0; i < n; ++ i) ret += mark[i];
    printf("%d\n", ret);
    /*static int tmp[MAXN];
    memcpy(tmp, AC.mate, sizeof(AC.mate[0]) * n);
    for (int u = 0; u < n; ++ u) if (tmp[u] != -1) {
      int v = AC.mate[u], now(0);
      AC.mate[v] = AC.mate[u] = -1;
      AC.aug(v, G, u);
      for (int i = 0; i < n; ++ i) {
        now += AC.mate[i] != -1;
      }
      ret -= now != mx;
      memcpy(AC.mate, tmp, sizeof(AC.mate[0]) * n);
    }
    printf("%d\n", ret);*/
  }
  return 0;
}