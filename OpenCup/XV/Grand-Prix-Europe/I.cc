#include <bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef long long LL;
const int MAXN = 1000 + 10, MAXM = 100000 + 10, SIZE = MAXM << 6;
vector<int> G[MAXN];
int ls[SIZE], rs[SIZE], cnt[SIZE], rt[MAXM];
int wt[MAXN][MAXN], dsu[MAXN], vis[MAXN];
int sz, n, m, cas;
LL E[MAXM];

void ins(int &now, int pre, int p, int v, int l = 0, int r = m) {
    now = sz ++; cnt[now] = cnt[pre] + v;
    ls[now] = ls[pre], rs[now] = rs[pre];
    if (l + 1 == r) return;
    if (p < mid) ins(ls[now], ls[pre], p, v, l, mid);
    else ins(rs[now], rs[pre], p, v, mid, r);
}

int ask(int rt, int l, int r, int L, int R) {
    if (L <= l && R >= r) return cnt[rt];
    int ret = 0;
    if (L < mid) ret += ask(ls[rt], l, mid, L, R);
    if (R > mid) ret += ask(rs[rt], mid, r, L, R);
    return ret;
}

int get(int x) {
    return x == dsu[x] ? x : dsu[x] = get(dsu[x]);
}

bool get(int b, int e, int &x, int &y, int &z) {
    static int Q[MAXN], P[MAXN];
    if (get(b) != get(e)) return dsu[get(b)] = get(e), false;
    ++ cas; Q[0] = b; vis[b] = cas;
    for (int h = 0, t = 1; h < t; ++ h) {
        int u = Q[h];
        if (u == e) {
            x = y = z = -1;
            for (; h; h = P[h]) {
                int v = Q[P[h]];
                if (wt[u][v] > z) z = wt[u][v], x = u, y = v;
                u = v;
            }
            return true;
        }
        for (auto &v : G[u]) if (vis[v] != cas) {
            vis[v] = cas; P[t] = h; Q[t ++] = v;
        }
    }
    return true;
}

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &n, &m); cas = 0;
        for (int i = 0; i < n; ++ i) {G[i].clear(); dsu[i] = i;}
        for (int i = 0; i < m; ++ i) {
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            if (u > v) swap(u, v); -- u, -- v;
            E[i] = ((LL)w << 20) | (u << 10) | v;
        }
        sort(E, E + m); rt[m] = ls[0] = rs[0] = cnt[0] = 0; sz = 1;
        for (int i = m - 1; i >= 0; -- i) {
            int u = (E[i] >> 10) & 1023, v = E[i] & 1023, w = E[i] >> 20;
            int x, y, z; rt[i] = rt[i + 1];
            if (get(u, v, x, y, z)) {
                if (x > y) swap(x, y);
                int now = lower_bound(E, E + m, ((LL)z << 20) | (x << 10) | y) - E;
                ins(rt[i], rt[i], now, -z);
                for (auto it = G[x].begin(); it != G[x].end(); ++ it) {
                    if (*it == y) {G[x].erase(it); break;}
                }
                for (auto it = G[y].begin(); it != G[y].end(); ++ it) {
                    if (*it == x) {G[y].erase(it); break;}
                }
            }
            ins(rt[i], rt[i], i, w);
            G[u].push_back(v); G[v].push_back(u);
            wt[u][v] = wt[v][u] = w;
        }
        int q; scanf("%d", &q);
        for (int i = 0, last = 0; i < q; ++ i) {
            int l, r; scanf("%d%d", &l, &r);
            l -= last; r -= last;
            int x = lower_bound(E, E + m, (LL)l << 20) - E;
            int y = upper_bound(E, E + m, ((LL)r << 20) | (n << 10) | n) - E;
            last = ask(rt[x], 0, m, x, y);
            printf("%d\n", last);
        }
    }
    return 0;
}