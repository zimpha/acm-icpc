#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
struct Edge {
    int v, nxt;
    Edge() {}
    Edge(int a, int b) :
        v(a), nxt(b) {}
} E[MAXN << 1];

vector<int> pt[MAXN];
int size[MAXN], bel[MAXN], G[MAXN];
int n, rt, ms, sz;
LL ret;

void getCenter(int u, int f = -1) {
    int mx = 0; size[u] = 1;
    for (int it = G[u]; ~it; it = E[it].nxt) {
        int v = E[it].v; if (v == f) continue;
        getCenter(v, u); size[u] += size[v];
        mx = max(mx, size[v]);
    }
    mx = max(mx, n - size[u]);
    if (mx < ms) ms = mx, rt = u;
}

void dfs(int u, int d, int f = -1) {
    pt[sz].push_back(u); ret += d; bel[u] = sz;
    for (int it = G[u]; ~it; it = E[it].nxt) {
        if (E[it].v != f) dfs(E[it].v, d + 1, u);
    }
}

int main() {
    scanf("%d", &n); sz = 0;
    for (int i = 1; i <= n; ++ i) G[i] = -1;
    for (int i = 1; i < n; ++ i) {
        int a, b; scanf("%d%d", &a, &b);
        E[sz] = Edge(b, G[a]); G[a] = sz ++;
        E[sz] = Edge(a, G[b]); G[b] = sz ++;
    }
    ms = n, rt = 1; sz = 0;
    getCenter(1);
    priority_queue<PII> Q;
    bel[rt] = -1; ret = 0;
    for (int it = G[rt]; ~it; it = E[it].nxt) {
        pt[sz].clear();
        dfs(E[it].v, 1, rt);
        Q.push(PII(pt[sz].size(), sz));
        ++ sz;
    }
    printf("%lld\n", ret * 2);
    printf("%d", rt);
    for (int i = 1; i < n; ++ i) {
        vector<PII> tp; tp.clear();
        while (!Q.empty() && Q.top().second == bel[rt]) {
            tp.push_back(Q.top());
            Q.pop();
        }
        PII now = Q.top(); Q.pop();
        rt = pt[now.second].back();
        pt[now.second].pop_back();
        now.first --;
        if (now.first) Q.push(now);
        while (!tp.empty()) Q.push(tp.back()), tp.pop_back();
        printf(" %d", rt);
    }
    puts("");
    return 0;
}
