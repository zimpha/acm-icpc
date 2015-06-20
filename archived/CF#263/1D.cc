#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 10, MOD = 1e9 + 7;
typedef pair<int, int> PII;
vector<PII> G[MAXN];
int col[MAXN], n, m;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    while (m --) {
        int a, b;
        string buf;
        cin >> a >> b >> buf;
        int u = n - 1 - abs(a - b), v = abs(a + b - n - 1);
        if (u > v) swap(u, v);
        G[u].push_back(PII(v + 2, buf[0] == 'o'));
        G[v + 2].push_back(PII(u, buf[0] == 'o'));
    }
    int cnt = 0;
    memset(col, -1, sizeof(col));
    for (int i = 0; i < n + 2; ++ i) {
        if (col[i] != -1) continue;
        col[i] = 0; ++ cnt;
        queue<int> Q; Q.push(i);
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (auto &x : G[u]) {
                int v = x.first, w = x.second;
                if (col[v] == -1) col[v] = col[u] ^ w, Q.push(v);
                else if ((col[v] ^ col[u]) != w) {
                    puts("0");
                    return 0;
                }
            }
        }
    }
    int ret = 1;
    for (int i = 0; i < cnt - 2; ++ i) ret = ret * 2 % MOD;
    cout << ret << endl;
    return 0;
}
