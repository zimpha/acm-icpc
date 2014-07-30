#include <bits/stdc++.h>
using namespace std;

struct Node {
    int len, vertex;
    Node() {}
    Node(int l, int v) : len(l), vertex(v) {}
};

const int MAXN = 20000 + 10;

vector<int> G[MAXN];
Node down[MAXN][2], best[MAXN][2];
int dep[MAXN], fa[MAXN][15];
int N, Q;

void dfs1(int u, int f, int d) {
    dep[u] = d; fa[u][0] = f;
    down[u][0] = Node(0, u);
    down[u][1] = Node(0, 0);
    for (auto v : G[u]) {
        if (v == f) continue;
        dfs1(v, u, d + 1);
        if (down[v][0].len + 1 > down[u][1].len) {
            down[u][1] = down[v][0]; ++ down[u][1].len;
            if (down[u][1].len > down[u][0].len) {
                swap(down[u][0], down[u][1]);
            }
        }
    }
}

void dfs2(int u, int f) {
    best[u][0] = down[u][0];
    best[u][1] = down[u][1];
    if (f != 0) {
        for (int i = 0; i < 2; ++ i) {
            if (best[f][i].vertex != down[u][0].vertex) {
                if (best[f][i].len + 1 > best[u][1].len) {
                    best[u][1] = best[f][i];
                    ++ best[u][1].len;
                }
                if (best[u][1].len > best[u][0].len) {
                    swap(best[u][0], best[u][1]);
                }
                break;
            }
        }
    }
    for (auto v : G[u]) {
        if (v != f) {
            dfs2(v, u);
        }
    }
}

struct LCA {
    void build() {
        for (int i = 1; (1 << i) < N; ++ i) {
            for (int j = 1; j <= N; ++ j) {
                if (fa[j][i - 1] != -1) {
                    fa[j][i] = fa[fa[j][i - 1]][i - 1];
                }
            }
        }
    }
    int up(int u, int d) {
        for (int i = 0; i < 15; ++ i, d >>= 1) {
            if (d & 1) u = fa[u][i];
        }
        return u;
    }
    int anc(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        int delta = dep[u] - dep[v];
        for (int i = 14; i >= 0; -- i) {
            if (delta & (1 << i)) u = fa[u][i];
        }
        for (int i = 14; i >= 0; -- i) {
            if (fa[u][i] != fa[v][i]) {
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        if (u != v) u = fa[u][0];
        return u;
    }
} LCA;

int main() {
    cin >> N >> Q;
    for (int i = 1; i < N; ++ i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(fa, -1, sizeof(fa));
    memset(dep, 0, sizeof(dep));
    dfs1(1, 0, 0);
    dfs2(1, 0);
    LCA.build();
    while (Q --) {
        int u, d;
        cin >> u >> d;
        int v = best[u][0].vertex, len = best[u][0].len;
        int anc = LCA.anc(u, v);
        int du = dep[u] - dep[anc];
        int dv = dep[v] - dep[anc];
        assert(du + dv == len);
        if (d > len) cout << 0 << endl;
        else if (d <= du) cout << LCA.up(u, d) << endl;
        else cout << LCA.up(v, len - d) << endl;
    }
    return 0;
}
