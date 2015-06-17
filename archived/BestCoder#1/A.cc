#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 30000 + 10;

vector<int> G[MAXN];
int deg[MAXN], N, M;

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= N; ++ i) {
            G[i].clear();
            deg[i] = 0;
        }
        for (int i = 0; i < M; ++ i) {
            int x, y; scanf("%d%d", &x, &y);
            G[y].push_back(x);
            ++ deg[x];
        }
        priority_queue<int> Q;
        for (int i = 1; i <= N; ++ i) {
            if (deg[i] == 0) Q.push(i);
        }
        vector<int> ret;
        while (!Q.empty()) {
            int u = Q.top(), v; Q.pop();
            ret.push_back(u);
            for (int i = 0; i < (int)G[u].size(); ++ i) {
                if ((-- deg[v = G[u][i]]) == 0) {
                    Q.push(v);
                }
            }
        }
        for (int i = ret.size() - 1; i >= 0; -- i) {
            printf("%d%c", ret[i], " \n"[i == 0]);
        }
    }
    return 0;
}
