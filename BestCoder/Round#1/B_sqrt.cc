#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;

vector<int> G[MAXN], P[MAXN];
int deg[MAXN], sum[MAXN], val[MAXN], N, M;

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= N; ++ i) {
            G[i].clear(); P[i].clear();
            sum[i] = deg[i] = val[i] = 0;
        }
        for (int i = 0; i < M; ++ i) {
            int x, y; scanf("%d%d", &x, &y);
            G[y].push_back(x); ++ deg[x];
            G[x].push_back(y); ++ deg[y];
        }
        int L = sqrt(2.0 * M);
        for (int u = 1; u <= N; ++ u) {
            for (int i = 0, v; i < (int)G[u].size(); ++ i) {
                if (deg[v = G[u][i]] > L) P[u].push_back(v);
            }
        }
        scanf("%d", &M);
        while (M --) {
            int type, u, v;
            scanf("%d%d", &type, &u);
            if (type == 0) {
                scanf("%d", &v);
                if (deg[u] <= L) {
                    for (int i = 0; i < (int)G[u].size(); ++ i) {
                        sum[G[u][i]] += v;
                    }
                }
                else {
                    val[u] += v;
                }
            }
            else {
                int ret = sum[u];
                for (int i = 0; i < (int)P[u].size(); ++ i) {
                    ret += val[P[u][i]];
                }
                printf("%d\n", ret);
            }
        }
    }
    return 0;
}
