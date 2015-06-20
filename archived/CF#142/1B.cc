#include <bits/stdc++.h>
using namespace std;

struct Node {
    int v, w;
    Node() {}
    Node(int v, int w) : v(v), w(w) {}
    bool operator < (const Node &rhs) const {
        return v < rhs.v;
    }
    bool operator == (const Node &rhs) const {
        return v == rhs.v;
    }
    bool operator <= (const Node &rhs) const {
        return v <= rhs.v;
    }
};

const int MAXN = 100000 + 10, inf = 2e9;

vector<Node> G[MAXN], A[MAXN];
int dis[MAXN], vis[MAXN];
int n, m;

int spfa() {
    queue<int> Q;
    for (int i = 1; i <= n; ++ i) dis[i] = inf, vis[i] = false;
    Q.push(1); dis[1] = 0; vis[1] = true;
    while (!Q.empty()) {
        int u = Q.front(), extra = 0; Q.pop(); vis[u] = false;
        size_t idx = lower_bound(A[u].begin(), A[u].end(), Node(dis[u], 0)) - A[u].begin(); 
        if (idx < A[u].size() && A[u][idx].v == dis[u]) extra = A[u][idx].w;
        for (auto x : G[u]) {
            if (dis[x.v] > dis[u] + x.w + extra) {
                dis[x.v] = dis[u] + x.w + extra;
                if (!vis[x.v]) vis[x.v] = true, Q.push(x.v);
            }
        }
    }
    if (dis[n] == inf) dis[n] = -1;
    return dis[n];
}

int main() {
    scanf("%d%d", &n, &m);
    while (m --) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        G[a].push_back(Node(b, c));
        G[b].push_back(Node(a, c));
    }
    for (int i = 1; i <= n; ++ i) {
        int k; scanf("%d", &k);
        for (int j = 0; j < k; ++ j) {
            int t; scanf("%d", &t);
            A[i].push_back(Node(t, 1));
        }
        for (int j = k - 2; j >= 0; -- j) {
            if (A[i][j].v + 1 == A[i][j + 1].v) A[i][j].w += A[i][j + 1].w;
        }
    }
    printf("%d\n", spfa());
    return 0;
}
