#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;

vector<int> G[MAXN];
int sum[MAXN], N, M;

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= N; ++ i) {
            G[i].clear();
            sum[i] = 0;
        }
        for (int i = 0; i < M; ++ i) {
            int x, y; scanf("%d%d", &x, &y);
            G[y].push_back(x);
            G[x].push_back(y);
        }
        scanf("%d", &M);
        while (M --) {
            int type, u, v;
            scanf("%d%d", &type, &u);
            if (type == 0) {
                scanf("%d", &v);
                for (int i = 0; i < (int)G[u].size(); ++ i) sum[G[u][i]] += v;
            }
            else {
                printf("%d\n", sum[u]);
            }
        }
    }
    return 0;
}
