#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;

int x[MAXN], y[MAXN], r[MAXN], n;
int d[MAXN], p[MAXN], q[MAXN];

inline int sqr(int x) {return x * x;}
inline int dis(int a, int b) {
    return sqr(x[a] - x[b]) + sqr(y[a] - y[b]);
}
inline bool touch(int a, int b) {
    return dis(a, b) == sqr(r[a] + r[b]);
}

void dfs(int u) {
    for (int v = 0; v < n; ++ v) if (d[v] == -1 && touch(u, v)) {
        d[v] = d[u] ^ 1;
        p[v] = p[u] * r[u];
        q[v] = q[u] * r[v];
        int g = __gcd(p[v], q[v]);
        p[v] /= g; q[v] /= g;
        dfs(v);
    }
}

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++ i) {
            d[i] = -1;
            scanf("%d%d%d", x + i, y + i, r + i);
        }
        d[0] = 1; p[0] = q[0] = 1;
        dfs(0);
        for (int i = 0; i < n; ++ i) {
            if (d[i] == -1) puts("not moving");
            else {
                if (q[i] == 1) printf("%d ", p[i]);
                else printf("%d/%d ", p[i], q[i]);
                if (d[i]) puts("clockwise");
                else puts("counterclockwise");
            }
        }
    }
}