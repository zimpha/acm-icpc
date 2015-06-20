#include <bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;

const int MAXN = 100000 + 10, inf = 1e9;

struct Edge {
    int v, w, nxt;
    Edge() {}
    Edge(int _v, int _w, int _n) : v(_v), w(_w), nxt(_n) {}
} E[MAXN << 1];

int G[MAXN], size[MAXN];
long long dis[MAXN];
int st[MAXN], ed[MAXN], belong[MAXN];
int n, sz, root, mins;

void getroot(int u, int f = -1) {
    size[u] = 1; int mx = 0;
    for (int now = G[u]; ~now; now = E[now].nxt) {
        int v = E[now].v; if (v == f) continue;
        getroot(v, u); size[u] += size[v];
        mx = max(mx, size[v]);
    }
    mx = max(mx, n - size[u]);
    if (mx < mins || (mx == mins && u < root)) root = u, mins = mx;
}

void dfs(int u, int f, int subtree) {
    size[u] = 1; belong[u] = subtree; st[u] = sz ++;
    for (int now = G[u]; ~now; now = E[now].nxt) {
        int v = E[now].v, w = E[now].w; if (v == f) continue;
        dis[v] = dis[u] + w;dfs(v, u, subtree); size[u] += size[v];
    }
    ed[u] = sz;
}

namespace SegTree {
    int mx[MAXN << 2];
    void modify(int rt, int l, int r, int p, int v) {
        if (l + 1 == r) {mx[rt] = v; return;}
        if (p < mid) modify(lson, l, mid, p, v);
        else modify(rson, mid, r, p, v);
        mx[rt] = min(mx[lson], mx[rson]);
    }
    int query(int rt, int l, int r, int L, int R) {
        if (L <= l && R >= r) return mx[rt];
        int ret = inf;
        if (L < mid) ret = min(ret, query(lson, l, mid, L, R));
        if (R > mid) ret = min(ret, query(rson, mid, r, L, R));
        return ret;
    }
}

typedef pair<int, int> PII;
set<PII> S;
int match[MAXN];

void solve() {
    mins = inf; getroot(0);
    sz = 0; belong[root] = root; dis[root] = 0;
    for (int now = G[root]; ~now; now = E[now].nxt) {
        int v = E[now].v, w = E[now].w;
        dis[v] = w; dfs(v, root, v);
        S.insert(PII(size[v] <<= 1, v));
    }
    st[root] = sz ++; ed[root] = sz; size[root] = 2;
    S.insert(PII(size[root], root));
    long long ret = 0;
    for (int i = 0; i < n; ++ i) {
        SegTree::modify(1, 0, n, st[i], i);
        ret += dis[i];
    }
    for (int i = 0; i < n; ++ i) {
        int unmatch = n - i, anc = belong[i], pt = inf;
        S.erase(PII(size[anc], anc));
        if (!S.empty()) {
            auto it = S.rbegin();
            if (it->second != root && it->first > unmatch - 1) {
                pt = SegTree::query(1, 0, n, st[it->second], ed[it->second]);
            }
            else {
                if (ed[anc] < sz) pt = SegTree::query(1, 0, n, ed[anc], sz);
                if (st[anc] > 0) pt = min(pt, SegTree::query(1, 0, n, 0, st[anc]));
                pt = min(pt, SegTree::query(1, 0, n, st[root], ed[root]));
            }
        }
        else pt = SegTree::query(1, 0, n, st[root], ed[root]);
        match[i] = pt;
        SegTree::modify(1, 0, n, st[pt], inf);
        if (-- size[anc]) S.insert(PII(size[anc], anc));
        anc = belong[pt]; S.erase(PII(size[anc], anc));
        if (-- size[anc]) S.insert(PII(size[anc], anc));
    }
    printf("%lld\n", ret << 1);
    for (int i = 0; i < n; ++ i) {
        printf("%d%c", match[i] + 1, " \n"[i == n - 1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++ i) G[i] = -1;
    for (int i = 1; i < n; ++ i) {
        int u, v, w; cin >> u >> v >> w; -- u, -- v;
        E[sz] = Edge(v, w, G[u]); G[u] = sz ++;
        E[sz] = Edge(u, w, G[v]); G[v] = sz ++;
    }
    solve();
    return 0;
}
