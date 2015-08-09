#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;
typedef long long LL;
bool is_b[MAXN][MAXN];

class Articulation {
public:
  int cnt, n;
  int gao(int n, int g[][MAXN]){
    memset(tag,use=0,sizeof(tag));
    memset(low,cnt=0,sizeof(low));
    this->n = n;
    for(int i=0;i<n;i++) if(!tag[i]) dfs(i,1,g);
    return cnt;
  }
private:
  int tag[MAXN],low[MAXN],dot[MAXN],use;
  void dfs(int x, int dep, int g[][MAXN]){
    int src=0,out=1<dep;
    dot[use++]=x;
    tag[x]=low[x]=dep;
    for (int y = 0; y < n; ++ y) if (g[x][y] != -1) {
      if(!tag[y]){
        dfs(y,dep+1,g);
        low[x]=min(low[x],low[y]);
        if(low[y]> tag[x]) {
          is_b[x][y] = is_b[y][x] = 1;
        }
        if(low[y]>=tag[x]){
          ++ out;
          while(dot[--use]!=y);
          ++ cnt;
        }
      }else if(tag[y]!=tag[x]-1 || src++){
        low[x]=min(low[x],tag[y]);
      }
    }
  }
} AC;

vector<int> G[MAXN];
int f[MAXN][MAXN], g[MAXN][MAXN];
int h[MAXN][MAXN], vis[MAXN];
int N, M, MOD;

int get_f(int x, int y) {
  if (f[x][y] != -1) return f[x][y];
  if (x == y) return f[x][y] = 0;
  if (x == 1 || y == 1) return f[x][y] = 1 % MOD;
  f[x][y] = get_f(x - 1, y) + get_f(x, y - 1);
  f[x][y] %= MOD;
  f[x][y] += get_f(x - 1, y - 1);
  return f[x][y] %= MOD;
}

void get_tree(int u, int f = -1) {
  for (int v = 0; v < N; ++ v) {
    if (g[u][v] != -1 && !vis[v]) {
      G[u].push_back(v); vis[v] = 1;
      G[v].push_back(u);
      get_tree(v, u);
    }
  }
}

void get_min(int u, int mx, int f, int h[]) {
  h[u] = mx;
  for (auto &v: G[u]) if (v != f) {
    int nx = mx; 
    if (is_b[u][v]) nx = min(nx, g[u][v]);
    get_min(v, nx, u, h);
  }
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d%d%d", &N, &M, &MOD);
    memset(f, -1, sizeof(f));
    memset(g, -1, sizeof(g));
    memset(is_b, 0, sizeof(is_b));
    for (int i = 0; i < M; ++ i) {
      int u, v; scanf("%d%d", &u, &v);
      g[u - 1][v - 1] = g[v - 1][u - 1] = get_f(u, v);
    }
    AC.gao(N, g);
    for (int i = 0; i < N; ++ i) G[i].clear(), vis[i] = 0;
    vis[0] = 1;
    get_tree(0);
    for (int i = 0; i < N; ++ i) {
      for (int j = 0; j < N; ++ j) h[i][j] = MOD * 2;
      get_min(i, MOD * 2, -1, h[i]);
    }
    LL ret = 0;
    for (int x = 0; x < N; ++ x) {
      for (int y = 0; y < x; ++ y) {
        LL tmp = (LL)get_f(x + 1, y + 1) - h[x][y];
        ret = max(ret, tmp);
      }
    }
    cout << ret << endl;
  }
}