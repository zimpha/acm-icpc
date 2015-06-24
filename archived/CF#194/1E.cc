#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000;
bitset<MAXN> A[MAXN];
int x[MAXN], y[MAXN];

struct Node {
    int i, j, d;
    bool operator < (const Node &rhs) const {
        return d > rhs.d;
    }
};

Node E[MAXN * MAXN];
int n, m;

bool add(int u, int v) {
    static bitset<MAXN> tmp;
    tmp = A[u] & A[v];
    if (tmp.any()) return true;
    A[u][v] = A[v][u] = 1;
    return false;
}

int main() {
    int n; cin >> n; m = 0;
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d", x + i, y + i);
        for (int j = 0; j < i; ++ j) {
            E[m ++] = (Node){i, j, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])};
        }
    }
    sort(E, E + m);
    int ret = 0;
    for (int i = 0; i < m; ++ i) {
        int u = E[i].i, v = E[i].j;
        if (add(u, v)) {
            ret = E[i].d;
            break;
        }
    }
    printf("%.10f\n", sqrt(1.0 * ret) * 0.5);
    return 0;
}
