#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 40000 + 10;

struct Node {
    int len, vertex;
    Node() {}
    Node(int l, int v) : len(l), vertex(v) {}
};

vector<int> G[MAXN];
Node down[MAXN][2], best[MAXN][2];
int N, Q;

void dfs1(int u, int f) {
    down[u][0] = Node(0, u);
    down[u][1] = Node(0, 0);
    for (int i = 0; i < (int)G[u].size(); ++ i) {
        int v = G[u][i]; if (v == f) continue;
        dfs1(v, u);
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
    for (int i = 0; i < (int)G[u].size(); ++ i) {
        if (G[u][i] != f) dfs2(G[u][i], u);
    }
}

int LN[MAXN], LQ[MAXN];
long long SQ[MAXN];


int main() {
    while (scanf("%d%d", &N, &Q) == 2) {
        for (int i = 1; i <= N; ++ i) G[i].clear();
        for (int i = 1; i < N; ++ i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs1(1, 0);
        dfs2(1, 0);
        int dn = 0;
        for (int i = 1; i <= N; ++ i) {
            dn = max(dn, best[i][0].len);
            LN[i] = best[i][0].len;
        }
        for (int i = 1; i <= Q; ++ i) G[i].clear();
        for (int i = 1; i < Q; ++ i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs1(1, 0);
        dfs2(1, 0);
        int dq = 0;
        for (int i = 1; i <= Q; ++ i) {
            dq = max(dq, best[i][0].len);
            LQ[i] = best[i][0].len;
        }
        int D = max(dn, dq);
        sort(LQ + 1, LQ + 1 + Q); SQ[0] = 0;
        for (int i = 1; i <= Q; ++ i) SQ[i] = SQ[i - 1] + LQ[i];
        long long ret = 0;
        for (int i = 1; i <= N; ++ i) {
            int idx = lower_bound(LQ + 1, LQ + 1 + Q, D - LN[i] - 1) - LQ;
            ret += (idx - 1) * D + SQ[Q] - SQ[idx - 1] + (Q - idx + 1) * (LN[i] + 1);
        }
        printf("%.3f\n", 1.0 * ret / (N * Q * 1.0));
    }
    return 0;
}
