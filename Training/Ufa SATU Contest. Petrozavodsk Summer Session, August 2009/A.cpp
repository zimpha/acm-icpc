#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;

vector<int> G[MAXN];
int A[MAXN], B[MAXN], deg[MAXN], SCC[MAXN];
bool mark[MAXN];
int cnt, N;

void dfs(int u, int col) {
    SCC[u] = col;
    for (int i = 0; i < (int)G[u].size(); ++ i) {
        int v = G[u][i];
        if (!SCC[v]) dfs(v, col);
    }
}

int getmin() {
    int ret = 0; cnt = 0;
    for (int i = 1; i <= N; ++ i) {
        if (!SCC[i]) dfs(i, ++ cnt);
    }
    memset(A, 0, sizeof(A));
    for (int i = 1; i <= N; ++ i) {
        if (deg[i] == 0) {
            ++ A[SCC[i]];
        }
    }
    for (int i = 1; i <=cnt; ++ i) {
        ret += A[i];
        if (!A[i]) ++ ret;
    }
    return ret;
}

int getmax() {
    queue<int> Q;
    memset(mark, 1, sizeof(mark));
    for (int i = 1; i <= N; ++ i) {
        A[i] = 1;
        if (deg[i] == 0) Q.push(i);
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        mark[u] = false;
        int v = B[u]; deg[v] --;
        A[v] += A[u];
        if (deg[v] == 0) Q.push(v);
    }
    int ret = cnt;
    for (int i = 1; i <= N; ++ i) {
        if (mark[i]) ret += A[i] - 1;
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++ i) {
        scanf("%d", A + i);
        ++ deg[A[i]]; B[i] = A[i];
        G[i].push_back(A[i]);
        G[A[i]].push_back(i);
    }
    int ret1 = getmin();
    int ret2 = getmax();
    printf("%d %d\n", ret1, ret2);
    return 0;
}
