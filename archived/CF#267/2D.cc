#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int MAXN = 500000 + 10;

vector<int> G[MAXN];
map<string, int> mp;
PII best[MAXN];
priority_queue<pair<PII, int> > Q;
int word[MAXN], vis[MAXN];
int n, m, sz;

int get(string s) {
    for (int i = 0; i < (int)s.size(); ++ i) s[i] = tolower(s[i]);
    if (mp.count(s)) return mp[s];
    mp[s] = ++ sz;
    int cr = 0;
    for (int i = 0; i < (int)s.size(); ++ i) cr += (s[i] == 'r');
    best[sz] = PII(-cr, -s.size());
    Q.push(make_pair(best[sz], sz));
    return sz;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        string st; cin >> st;
        word[i] = get(st);
    }
    cin >> m;
    for (int i = 0; i < m; ++ i) {
        string x, y; cin >> x >> y;
        int u = get(x), v = get(y);
        G[v].push_back(u);
    }
    while (!Q.empty()) {
        int u = Q.top().second; Q.pop();
        if (vis[u]) continue; vis[u] = true;
        for (auto &v : G[u]) {
            if (best[v] < best[u]) {
                best[v] = best[u];
                Q.push(make_pair(best[v], v));
            }
        }
    }
    long long cr = 0, cl = 0;
    for (int i = 0; i < n; ++ i) {
        cr -= best[word[i]].first;
        cl -= best[word[i]].second;
    }
    cout << cr << " " << cl << endl;
    return 0;
}
