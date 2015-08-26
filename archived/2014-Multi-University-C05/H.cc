#pragma comment (linker,"/STACK:102400000,102400000") 
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10, inf = 1e9;

struct Edge {
    int v, nxt;
    Edge() {}
    Edge(int a, int b) : v(a), nxt(b) {}
} E[MAXN << 1];

bool vis[MAXN];
int G[MAXN], dep[MAXN], size[MAXN], w[MAXN];
int N, Q, total, mins, root, cnt, sz;

struct Entry {
    int anc, i1, i2, dep;
    Entry() {}
    Entry(int a, int b, int c, int d) : anc(a), i1(b), i2(c), dep(d) {}
};

vector<Entry> entries[MAXN];

struct BIT {
    vector<int> C;
    int n;
    void init(int _n) {
        this->n = _n + 1; C.resize(n);
        for (int i = 0; i < n; ++ i) C[i] = 0;
    }
    void add(int i, int v) {
        for (; i < n; i += ~i & i + 1) C[i] += v;
    }
    int sum(int i) {
        int ret = 0; i = min(i, n - 1);
        for (; i >= 0; i -= ~i & i + 1) ret += C[i];
        return ret;
    }
} bit[MAXN << 4];

void getRoot(int u, int f) {
    size[u] = 1; int mx = 0;
    for (int now = G[u]; ~now; now = E[now].nxt) {
        int v = E[now].v; if (v == f || vis[v]) continue;
        getRoot(v, u); size[u] += size[v]; mx = max(mx, size[v]);
    }
    mx = max(mx, total - size[u]);
    if (mx < mins) mins = mx, root = u;
}

void getDep(int u, int f) {
    size[u] = 1; dep[u] = 0;
    for (int now = G[u]; ~now; now = E[now].nxt) {
        int v = E[now].v; if (v == f || vis[v]) continue;
        getDep(v, u);
        dep[u] = max(dep[u], dep[v] + 1);
        size[u] += size[v];
    }
}

int i1, i2;

void dfs(int u, int f, int d) {
    bit[i1].add(d, w[u]);
    bit[i2].add(d, w[u]);
    entries[u].push_back(Entry(root, i1, i2, d));
    for (int now = G[u]; ~now; now = E[now].nxt) {
        int v = E[now].v; if (v == f || vis[v]) continue;
        dfs(v, u, d + 1);
    }
}

void build(int u) {
    total = size[u]; mins = inf;
    getRoot(u, -1);
    u = root; vis[u] = true;
    getDep(u, -1);
    bit[sz ++].init(dep[u]);
    i1 = sz - 1; 
    bit[i1].add(0, w[u]);
    entries[u].push_back(Entry(u, i1, -1, 0));
    for (int now = G[u]; ~now; now=  E[now].nxt) {
        int v = E[now].v; if (vis[v]) continue;
        i2 = sz;
        bit[sz ++].init(dep[v] + 1);
        dfs(v, u, 1);
    }
    for (int now = G[u]; ~now; now = E[now].nxt) {
        int v = E[now].v; if (vis[v]) continue;
        build(v);
    }
}

int main() {
    while (scanf("%d%d", &N, &Q) == 2) {
        for (int i = 0; i < N; ++ i) {
            scanf("%d", &w[i]);
            G[i] = -1; entries[i].clear();
        }
        sz = 0;
        for (int i = 1; i < N; ++ i) {
            int u, v; scanf("%d%d", &u, &v); -- u, -- v;
            E[sz] = Edge(v, G[u]); G[u] = sz ++;
            E[sz] = Edge(u, G[v]); G[v] = sz ++;
        }
        for (int i = 0; i < N; ++ i) vis[i] = false;
        size[0] = N; sz = 0;
        build(0);
        while (Q --) {
            char st[10]; 
            int v, x;
            scanf("%s%d%d", st, &v, &x); -- v;
            if (st[0] == '!') {
                x -= w[v];
                for (int i = 0; i < (int)entries[v].size(); ++ i) {
                    Entry &t = entries[v][i];
                    bit[t.i1].add(t.dep, x);
                    if (t.i2 != -1) {
                        bit[t.i2].add(t.dep, x);
                    }
                }
                w[v] += x;
            }
            else {
                int ret = 0;
                for (int i = 0; i < (int)entries[v].size(); ++ i) {
                    Entry &t = entries[v][i];
                    if (t.dep > x) continue;
                    ret += bit[t.i1].sum(x - t.dep);
                    if (t.i2 != -1) {
                        ret -= bit[t.i2].sum(x - t.dep);
                    }
                }
                printf("%d\n", ret);
            }
        }
    }
    return 0;
}
