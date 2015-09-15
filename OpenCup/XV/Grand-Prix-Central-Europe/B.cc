#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 200000 + 10, inf = 2e9 + 10;

struct W {
    int val, idx;
    W(int a = 0, int b = 0): val(a), idx(b) {}
    bool operator < (const W &rhs) const {
        return val < rhs.val;
    }
    W operator + (const int x) const {
        return W(x + val, idx);
    }
} dis[MAXN];

struct Entry {
    int u, v, w, idx;
    Entry() {}
    Entry(int a, int b, int c, int d = -1):
        u(a), v(b), w(c), idx(d) {}
    bool operator < (const Entry &rhs) const {
        if (w == rhs.w) return idx < rhs.idx;
        else return w < rhs.w;
    }
};
vector<Entry> event;
vector<PII> G[MAXN];
int A[MAXN], B[MAXN], C[MAXN];
int ret[MAXN], dsu[MAXN];
bool ok[MAXN], vis[MAXN];
int n, m, s;

int get(int x) {
    return x == dsu[x] ? dsu[x] : dsu[x] = get(dsu[x]);
}

void spfa() {
    for (int i = 1; i <= n; ++ i) dis[i] = W(inf, -1);
    queue<int> Q;
    for (int i = 1; i <= n; ++ i) if (ok[i]) {
        Q.push(i); vis[i] = 1; dis[i] = W(0, i);
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop(); vis[u] = 0;
        for (auto &x : G[u]) {
            if (dis[u] + x.second < dis[x.first]) {
                dis[x.first] = dis[u] + x.second;
                if (!vis[x.first]) vis[x.first] = 1, Q.push(x.first);
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &s, &m);
    for (int i = 0, x; i < s; ++ i) scanf("%d", &x), ok[x] = true;
    for (int i = 0; i < m; ++ i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        A[i] = u; B[i] = v; C[i] = w;
        G[u].push_back(PII(v, w));
        G[v].push_back(PII(u, w));
    }
    spfa();
    for (int i = 0; i < m; ++ i) {
        int u = dis[A[i]].idx, v = dis[B[i]].idx;
        int w = dis[A[i]].val + dis[B[i]].val + C[i];
        event.push_back(Entry(u, v, w));
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++ i) {
        int x, y, b; scanf("%d%d%d", &x, &y, &b);
        event.push_back(Entry(x, y, b, i));
    }
    sort(event.begin(), event.end());
    for (int i = 1; i <= n; ++ i) dsu[i] = i;
    for (auto &x : event) {
        if (x.idx == -1) {
            int u = get(x.u), v = get(x.v);
            if (u != v) dsu[u] = v;
        }
        else {
            int u = get(x.u), v = get(x.v);
            if (u == v) ret[x.idx] = 1;
        }
    }
    for (int i = 0; i < m; ++ i) puts(ret[i] ? "TAK" : "NIE");
    return 0;
}