#include <bits/stdc++.h>
using namespace std;

const int SIZE = 2000000 + 10, MAXN = 100000 + 10;

vector<int> prime[SIZE], G[MAXN], stk[SIZE];
int val[MAXN], ret[MAXN], pt[MAXN], n, q;

void sieve() {
    for (int i = 2; i < SIZE; ++ i) {
        if (!prime[i].empty()) continue;
        for (int j = i; j < SIZE; j += i) prime[j].push_back(i);
    }
}

void dfs(int u, int f, int d) {
    for (auto p : prime[val[u]]) stk[p].push_back(d); pt[d] = u;
    for (auto v : G[u]) {
        if (v == f) continue;
        int dep = -1;
        for (auto p : prime[val[v]]) {
            if (stk[p].empty()) continue;
            dep = max(dep, stk[p].back());
        }
        if (dep != -1) ret[v] = pt[dep];
        dfs(v, u, d + 1);
    }
    for (auto p : prime[val[u]]) stk[p].pop_back();
}

int main() {
    sieve();
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 0; i < n; ++ i) cin >> val[i];
    for (int i = 1; i < n; ++ i) {
        int u, v; cin >> u >> v; -- u, -- v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 0; i < n; ++ i) ret[i] = -2;
    dfs(0, -1, 0);
    while (q --) {
        int t, u; cin >> t >> u; -- u;
        if (t == 1) cout << ret[u] + 1 << endl;
        else {
            int w; cin >> w; val[u] = w;
            for (int i = 0; i < n; ++ i) ret[i] = -2;
            dfs(0, -1, 0);
        }
    }
    return 0;
}
