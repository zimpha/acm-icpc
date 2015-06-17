#include <bits/stdc++.h>
#define _1 first
#define _2 second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
vector<int> G[MAXN];
int deg[MAXN], N, M;

class Articulation {
public:
  int cnt, cut_edge, cut_vertex;
  int gao(int n, const vector<int> e[]){
    memset(tag,use=0,sizeof(tag));
    memset(low,cnt=0,sizeof(low));
    cut_edge = cut_vertex = 0;
    for(int i=0;i<n;i++) if(!tag[i]) dfs(i,1,e);
    return cnt;
  }
private:
  int tag[MAXN],low[MAXN],dot[MAXN],use;
  void dfs(int x, int dep, const vector<int> e[]){
    int src=0,out=1<dep;
    dot[use++]=x;
    tag[x]=low[x]=dep;
    for(size_t i=0;i<e[x].size();i++){
      int y=e[x][i];
      if(!tag[y]){
        dfs(y,dep+1,e);
        low[x]=min(low[x],low[y]);
        if(low[y]> tag[x]) cut_edge ++;
        if(low[y]>=tag[x]){
          if(++out==2) cut_vertex ++;
          while(dot[--use]!=y); cnt ++;
        }
      }else if(tag[y]!=tag[x]-1 || src++){
        low[x]=min(low[x],tag[y]);
      }
    }
  }
} AC;

struct Urn {
  int u[MAXN], pt[MAXN], sz;
  void init(int n) {
    for (int i = 0; i < n; ++ i) pt[i] = -1;
    sz = 0;
  }
  int get() {
    pt[u[-- sz]] = -1;
    return u[sz];
  }
  void add(int x) {
    if (pt[x] != -1) return;
    u[sz] = x; pt[x] = sz ++;
  }
  void erase(int x) {
    if (pt[x] == -1) return;
    u[pt[x]] = u[-- sz]; 
    pt[u[sz]] = pt[x]; pt[x] = -1;
  }
  bool has(int x) {return pt[x] != -1;}
  bool empty() {return sz == 0;}
} Reduce;

struct Incident {
  typedef list<int>::iterator Iter;
  list<int> inc;
  map<int, Iter> pt;
  void clear() {
    inc.clear(); pt.clear();
  }
  int pred(int x) {
    if (!pt.count(x)) return -1;
    Iter it = pt[x];
    if (it == inc.begin()) it = inc.end();
    -- it; return *it;
  }
  int succ(int x) {
    if (!pt.count(x)) return -1;
    Iter it = pt[x]; ++ it;
    if (it == inc.end()) it = inc.begin();
    return *it;
  }
  void push_back(int x) {
    inc.push_back(x);
    pt[x] = -- inc.end();
  }
  void add_after(int x, int y) {
    Iter it = pt[x]; ++ it;
    pt[y] = inc.insert(it, y);
  }
  void erase(int x) {
    if (pt.count(x)) {
      inc.erase(pt[x]); pt.erase(x);
    }
  }
  set<int> toSet() {
    set<int> s;
    for (int x: inc) s.insert(x);
    return s;
  }
  bool has(int x) {return pt.count(x);}
} E[MAXN];

bool add(int u, int v) {
  if (E[u].has(v) || E[v].has(u)) return false;
  E[u].push_back(v); E[v].push_back(u); return true;
}

bool phase_I(int n, vector<int> G[], vector<PII> &S) {
  Reduce.init(n);
  for (int u = 0; u < n; ++ u) {
    E[u].clear(); deg[u] = G[u].size();
    for (auto &v: G[u]) E[u].push_back(v);
  }
  for (int i = 0; i < n; ++ i) {
    if (deg[i] <= 5) Reduce.add(i);
  }
  for (int _ = 0; _ + 4 < n; ++ _) {
    if (Reduce.empty()) return false;
    int v = Reduce.get(), k = deg[v], w(-1);
    vector<int> pt(E[v].inc.begin(), E[v].inc.end());
    for (int u: pt) {
      E[v].erase(u), E[u].erase(v);
      S.push_back(PII(v, u));
      deg[v] --; deg[u] --;
    }
    if (k >= 4) {
      for (size_t i = 0; i < pt.size(); ++ i) {
        int c(0);
        for (size_t j = 0; j < pt.size(); ++ j) {
          if (E[pt[i]].has(pt[j])) ++ c;
        }
        if (c == 2) {w = pt[i]; break;}
      }
      if (w == -1) return false;
      for (size_t i = 0; i < pt.size(); ++ i) if (w != pt[i]) {
        if (!E[w].has(pt[i])) {
          deg[w] ++; deg[pt[i]] ++;
          S.push_back(PII(w, pt[i]));
          if (!add(w, pt[i])) return false;
        }
      }
    }
    for (int u: pt) {
      if (deg[u] <= 5) Reduce.add(u);
      else Reduce.erase(u);
    }
    S.push_back(PII(k, v));
  }
  return true;
}

set<int> compact[MAXN];

void remove(int u, int v) {
  if (compact[u].count(v)) compact[u].erase(v);
  if (compact[v].count(u)) compact[v].erase(u);
  E[u].erase(v); E[v].erase(u);
}

bool same_face(int x, int y, int z) {
  return E[x].succ(y) == z || E[x].succ(z) == y;
}

bool phase_III(int n, vector<PII> &S) {
  vector<int> pt;
  for (int i = 0; i < n; ++ i) {
    E[i].clear(); compact[i].clear();
    if (deg[i]) pt.push_back(i);
  }
  E[pt[0]].push_back(pt[1]); E[pt[0]].push_back(pt[2]); E[pt[0]].push_back(pt[3]);
  E[pt[1]].push_back(pt[2]); E[pt[1]].push_back(pt[0]); E[pt[1]].push_back(pt[3]);
  E[pt[2]].push_back(pt[3]); E[pt[2]].push_back(pt[0]); E[pt[2]].push_back(pt[1]);
  E[pt[3]].push_back(pt[1]); E[pt[3]].push_back(pt[0]); E[pt[3]].push_back(pt[2]);
  for (int i = 0; i < 4; ++ i) {
    for (int j = 0; j < i; ++ j) {
      compact[pt[i]].insert(pt[j]);
    }
  }
  while (!S.empty()) {
    int k = S.back()._1, u = S.back()._2, x[5]; S.pop_back();
    if (k == 3) {
      for (int i = 0; i < 3; ++ i) {
        x[i] = S.back()._2; S.pop_back();
      }
      if (E[x[0]].succ(x[1]) == x[2]) swap(x[1], x[2]);
      if (!same_face(x[0], x[1], x[2])) return false;
    }
    else if (k == 4) {
      x[0] = S.back()._1, x[2] = S.back()._2; S.pop_back();
      x[1] = E[x[0]].succ(x[2]); x[3] = E[x[0]].pred(x[2]);
      set<int> sc(x, x + 4);
      for (int i = 0; i < 4; ++ i) {
        int t = S.back()._2; S.pop_back();
        if (!sc.count(t)) return false;
      }
      remove(x[0], x[2]);
    }
    else if (k == 5) {
      x[0] = S.back()._1; x[2] = S.back()._2; S.pop_back();
      x[3] = S.back()._2; S.pop_back();
      if (E[x[0]].succ(x[2]) == x[3]) swap(x[2], x[3]);
      if (!same_face(x[0], x[2], x[3])) return false;
      x[1] = E[x[0]].succ(x[2]); x[4] = E[x[0]].pred(x[3]);
      set<int> sc(x, x + 5);
      for (int i = 0; i < 5; ++ i) {
        int t = S.back()._2; S.pop_back();
        if (!sc.count(t)) return false;
      }
      remove(x[0], x[2]); remove(x[0], x[3]);
    }
    else assert(false);
    for (int i = k - 1; i >= 0; -- i) {
      E[x[i]].add_after(x[(i - 1 + k) % k], u);
      E[u].push_back(x[i]);
    }
    compact[u] = E[u].toSet();
  }
  return true;
}

bool is_maximal(int n, vector<int> G[]) {
  vector<PII> S;
  if (!phase_I(n, G, S)) return false;
  if (!phase_III(n, S)) return false;
  return true;
}

int main() {
  int T; scanf("%d", &T);
  int cnt[10]={0};
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d%d", &N, &M);
    if (N <= 5) cnt[N] ++;
    for (int i = 0; i < N; ++ i) G[i].clear(), deg[i] = 0;
    for (int i = 0; i < M; ++ i) {
      int u, v; scanf("%d%d", &u, &v); -- u, -- v;
      G[u].push_back(v); G[v].push_back(u);
      deg[u] ++; deg[v] ++;
    }
    sort(deg, deg + N);
    if (N == 1) puts("1");
    else if (N == 2) printf("%d\n", M == 1);
    else if (N == 3) printf("%d\n", M == 3);
    else if (N == 4) printf("%d\n", M == 6);
    else if (N == 5) printf("%d\n", M == 9);
    else {
      if (deg[0] >= 3 && M == N * 3 - 6 && AC.gao(N, G) <= 1) {
        if (is_maximal(N, G)) puts("1");
        else puts("0");
      }
      else puts("0");
    }
  }
  return 0;
}