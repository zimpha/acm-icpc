#include <bits/stdc++.h>
using namespace std;

struct TwoSAT {
    static const int MAXN = 200000 + 10;
    vector<int> G[MAXN], SCC[MAXN];
    int low[MAXN], dfn[MAXN], stk[MAXN];
    int col[MAXN], mark[MAXN];
    int scc_cnt, top, sz, n;
    void init(int n) {
        this->n = n; scc_cnt = 0;
        for (int i = 0; i < n * 2; ++ i) {
            G[i].clear(); SCC[i].clear();
        }
    }
    void dfs(int x) {
        low[x] = dfn[x] = ++ sz; stk[top ++] = x; mark[x] = true;
        for (int i = 0, y; i < (int)G[x].size(); ++ i) {
            if (!dfn[y = G[x][i]]) {
                dfs(y); low[x] = min(low[x], low[y]);
            }
            else if (mark[y]) low[x] = min(low[x], dfn[y]);
        }
        if (dfn[x] == low[x]) {
            for (int y; ; ) {
                mark[y = stk[-- top]] = false;
                SCC[scc_cnt].push_back(y);
                col[y] = scc_cnt;
                if (y == x) break;
            }
            ++ scc_cnt;
        }
    }
    inline int get_val(int x) {
        int r = (x & 1) ? x ^ 1 : x;
        if (mark[r] == -1) return -1;
        return (x & 1) ? !mark[r] : mark[r];
    }
    void construct() {
        for (int i = 0; i < n * 2; ++ i) mark[i] = -1;
        for (int i = 0, j, val; i < scc_cnt; ++ i) {
            for (val = 1, j = 0; j < (int)SCC[i].size(); ++ j) {
                int cur = SCC[i][j];
                if (get_val(cur) == 0) val = 0;
                for (int k = 0; k < (int)G[cur].size(); ++ k) 
                    if (get_val(G[cur][k]) == 0) val = 0;
                if (val == 0) break;
            }
            for (j = 0; j < (int)SCC[i].size(); ++ j) {
                if (SCC[i][j] & 1) mark[SCC[i][j] ^ 1] = !val;
                else mark[SCC[i][j]] = val;
            }
        }
    }
    bool solve() {
        for (int i = 0; i < 2 * n; ++ i) mark[i] = false, dfn[i] = 0;
        top = sz = 0;
        for (int i = 0; i < 2 * n; ++ i)
            if (!dfn[i]) dfs(i);
        for (int i = 0; i < 2 * n; i += 2) 
            if (col[i] == col[i ^ 1]) return false;
        construct();
        return true;
    }
    void add_edge(int x, int y) { // x -> y
        G[x].push_back(y);
    }
    void add_var(int x, int xv) { // x = xv
        x = x << 1 | xv;
        G[x ^ 1].push_back(x);
    }
    void add_clause(int x, int xv, int y, int yv) { // x = xv or y = yv
        x = x << 1 | xv; y = y << 1 | yv;
        G[x].push_back(y ^ 1); G[y].push_back(x ^ 1);
    }
} Task;

const int MAXN = 100000 + 10;
int p[MAXN];
map<int, int> S;

int main() {
    int n, A, B;
    cin >> n >> A >> B;
    for (int i = 0; i < n; ++ i) {
        scanf("%d", p + i);
        S[p[i]] = i;
    }
    Task.init(n);
    for (int i = 0; i < n; ++ i) {
        auto it = S.find(A - p[i]);
        if (it == S.end()) Task.add_var(i, 0);
        else {
            Task.add_edge(i << 1, it->second << 1);
            Task.add_edge(it->second << 1 | 1, i << 1 | 1);
        }
        it = S.find(B - p[i]);
        if (it == S.end()) Task.add_var(i, 1);
        else {
            Task.add_edge(i << 1 | 1, it->second << 1 | 1);
            Task.add_edge(it->second << 1, i << 1);
        }
    }
    if (!Task.solve()) puts("NO");
    else {
        puts("YES");
        for (int i = 0; i < n; ++ i) {
            printf("%d%c", Task.mark[i << 1], " \n"[i == n - 1]);
        }
    }
    return 0;
}
