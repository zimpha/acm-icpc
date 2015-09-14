#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300000 + 10;
typedef map<string, int>::iterator Iter;
map<string, int> KEY;
map<string, string> pr[MAXN];
vector<int> G[MAXN];
int n, m, q;

const int SIZE = MAXN << 7;
int ls[SIZE], rs[SIZE], sz;
string val[SIZE];
void init() {
  sz = 1; ls[0] = rs[0] = 0; val[0] = "";
}
void ins(int &now, int pre, int l, int r, int p, string &v) {
  now = sz ++; val[now] = val[pre];
  ls[now] = ls[pre]; rs[now] = rs[pre];
  if (l + 1 == r) {val[now] = v; return;}
  int mid = (l + r) >> 1;
  if (p < mid) ins(ls[now], ls[pre], l, mid, p, v);
  else ins(rs[now], rs[pre], mid, r, p, v);
}
string ask(int rt, int l, int r, int k) {
  if (l + 1 == r) return val[rt];
  int mid = (l + r) >> 1;
  if (k < mid) return ask(ls[rt], l, mid, k);
  else return ask(rs[rt], mid, r, k);
}

int rt[MAXN];

char buf[1000];

void dfs(int u, int f) {
  rt[u] = rt[f];
  for (auto &x : pr[u]) {
    int id = KEY[x.first];
    ins(rt[u], rt[u], 0, m, id, x.second);
  }
  for (int i = 0; i < (int)G[u].size(); ++ i) {
    dfs(G[u][i], u);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n; ++ i) G[i].clear();
  for (int i = 1; i <= n; ++ i) {
    int p, k; scanf("%d%d", &p, &k);
    G[p].push_back(i); pr[i].clear();
    while (k --) {
      scanf("%s", buf);
      string key = "", val = "";
      char *p = buf;
      for (; *p != '='; ++ p) key += *p;
      for (++ p; *p; ++ p) val += *p;
      pr[i][key] = val;
      KEY[key] = 1;
    }
  }
  m = 0;
  for (Iter it = KEY.begin(); it != KEY.end(); ++ it) {
    it->second = m ++;
  }
  init(); rt[0] = 0;
  queue<int> Q; Q.push(0);
  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    for (int i = 0; i < (int)G[u].size(); ++ i) {
      int v = G[u][i];
      rt[v] = rt[u];
      for (auto &x : pr[v]) {
        int id = KEY[x.first];
        ins(rt[v], rt[v], 0, m, id, x.second);
      }
      Q.push(v);
    }
  }
  scanf("%d", &q);
  while (q --) {
    int u, id; scanf("%d%s", &u, buf);
    string key = buf;
    if (KEY.count(key)) id = KEY[key];
    else id = -1;
    string now = "";
    if (id != -1) now = ask(rt[u], 0, m, id);
    if (now == "") now = "N/A";
    printf("%s\n", now.c_str());
    fflush(stdout);
  }
  return 0;
}