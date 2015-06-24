#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

class Articulation {
public:
  typedef pair<int,int> PII;
  static const int SIZE = 100005; // 最大结点个数
  set<PII> keyE;               // keyE为割边集，keyV为割点集
  vector<int> keyV,cc[SIZE];      // cc[p]表示结点p在哪些双连通分量中
  int cnt;  // 对于旧版编译器，将上面cc[SIZE]改成vector的形式
  // 传入结点个数n及各结点的出边e[]，返回双连通分量的个数cnt
  int gao(int n, const vector<int> e[]){
    memset(tag,use=0,sizeof(tag));
    memset(low,cnt=0,sizeof(low));
    keyE.clear();
    fill_n(cc,SIZE,keyV=vector<int>());
    for(int i=0;i<n;i++) if(!tag[i]) dfs(i,1,e);
    return cnt;
  }
  bool is_cut(int u, int v) {
    return keyE.count(PII(u, v));
  }
private:
  int tag[SIZE],low[SIZE],dot[SIZE],use;
  void dfs(int x, int dep, const vector<int> e[]){
    int src=0,out=1<dep;
    dot[use++]=x;
    tag[x]=low[x]=dep;
    for(size_t i=0;i<e[x].size();i++){
      int y=e[x][i];
      if(!tag[y]){
        dfs(y,dep+1,e);
        low[x]=min(low[x],low[y]);
        if(low[y]> tag[x]) {
          keyE.insert(PII(x,y));
          keyE.insert(PII(y,x));
        }
        if(low[y]>=tag[x]){
          if(++out==2) keyV.push_back(x);
          while(dot[--use]!=y) cc[dot[use]].push_back(cnt);
          cc[x].push_back(cnt); cc[y].push_back(cnt++);
        }
      }else if(tag[y]!=tag[x]-1 || src++){
        low[x]=min(low[x],tag[y]);
      }
    }
  }
} AC;

const int MAXN = 100000 + 10, POW = 19;
vector<int> G[MAXN];
int fa[MAXN][20], dep[MAXN];
int sz, id[MAXN], st[MAXN], ed[MAXN];

namespace LCA {
  void build(int n) {
    for (int i=1;(1<<i)<=n;++i) {
      for (int j=0;j<n;++j) if (fa[j][i-1] != -1) {
        fa[j][i]=fa[fa[j][i-1]][i-1];
      }
    }
  }
  int up(int u, int d) {
    for (int i=0;d;++i,d>>=1) if (d&1) u=fa[u][i];
    return u;
  }
  int ask(int u, int v) {
    if (dep[u]<dep[v]) swap(u,v);
    u=up(u,dep[u]-dep[v]);
    for (int i=POW;i>=0;--i) {
      if (fa[u][i]==fa[v][i]) continue;
      u=fa[u][i]; v=fa[v][i];
    }
    if (u!=v) u=fa[u][0]; return u;
  }
}

void dfs1(int u, int c) {
  id[u] = c;
  for (auto &v: G[u]) if (!AC.is_cut(u, v)) {
    if (id[v] == -1) dfs1(v, c);
  }
}

void dfs2(int u, int f = -1) {
  st[u] = sz ++;
  for (auto &v: G[u]) if (v != f) {
    dep[v] = dep[u] + 1;
    fa[v][0] = u;
    dfs2(v, u);
  }
  ed[u] = sz ++;
}

bool is_fa(int u, int v) {
  return st[u] <= st[v] && ed[u] >= ed[v];
}

int gao(int a, int b, int c, int d) {
  if (dep[b] < dep[d]) swap(a, c), swap(b, d);
  if (is_fa(c, b)) return 0;
  if (is_fa(d, b)) {
    if (is_fa(b, c)) return dep[LCA::ask(a, c)] - dep[b];
    else return 0;
  }
  else return 0;
}

int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < m; ++ i) {
    int u, v; scanf("%d%d", &u, &v);
    -- u; -- v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  AC.gao(n, G); sz = 0;
  memset(fa, -1, sizeof(fa));
  memset(id, -1, sizeof(id));
  for (int i = 0; i < n; ++ i) {
    if (id[i] == -1) dfs1(i, sz ++);
  }
  n = sz;
  for (int i = 0; i < n; ++ i) G[i].clear();
  for (auto &x: AC.keyE) {
    G[id[x.first]].push_back(id[x.second]);
  }
  sz = 0; dfs2(0);
  LCA::build(n);
  for (int _ = 0; _ < q; ++ _) {
    int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
    a = id[a - 1], b = id[b - 1], c = id[c - 1], d = id[d - 1];
    int fab = LCA::ask(a, b), fcd = LCA::ask(c, d);
    int ret = dep[c] + dep[d] - dep[fcd] * 2;
    ret -= gao(a, fab, c, fcd) + gao(a, fab, d, fcd);
    ret -= gao(b, fab, c, fcd) + gao(b, fab, d, fcd);
    printf("%d\n", ret);
  }
  return 0;
}

