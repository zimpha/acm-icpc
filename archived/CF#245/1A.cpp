#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

vector<int> G[MAXN], ret;
int init[MAXN], goal[MAXN];
int n;

void solve(int u, int f, int e, int o, int d) {
	if (d) init[u] ^= o;
	else init[u] ^= e;
	if (init[u] != goal[u]) {
		if (d) o ^= 1;
		else e ^= 1;
		ret.push_back(u);
	}
	for (int i = 0; i < (int)G[u].size(); ++ i) {
		int v = G[u][i];
		if (v == f) continue;
		solve(v, u, e, o, d ^ 1);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++ i) G[i].clear();
	for (int i = 1; i < n; ++ i) {
		int u, v; cin >> u >> v;
		G[u].push_back(v); G[v].push_back(u);
	}
	for (int i = 1; i <= n; ++ i) cin >> init[i];
	for (int i = 1; i <= n; ++ i) cin >> goal[i];
	ret.clear();
	solve(1, -1, 0, 0, 0);
	cout << ret.size() << endl;
	for (int i = 0; i < (int)ret.size(); ++ i)
		cout << ret[i] << endl;
	return 0;
}
