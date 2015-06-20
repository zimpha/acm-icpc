#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 200000 + 10;

vector<int> g[MAXN];
int col[MAXN], n;

void add_edge(int u, int v) {
	g[u].push_back(v); 
	g[v].push_back(u); 
}

void dfs(int u, int c) {
	if (col[u] == -1) col[u] = c;
	else return;
	for (int v : g[u]) dfs(v, c ^ 1);
}

int main() {
	cin >> n;
	vector<pair<int, int> > pos;
	for (int i = 0; i < n; ++ i) {
		int a, b; cin >> a >> b;
		pos.push_back(make_pair(a << 1, i << 1));
		pos.push_back(make_pair(b << 1 | 1, i << 1 | 1));
		add_edge(i << 1, i << 1 | 1);
	}
	sort(pos.begin(), pos.end());
	for (int i = 0; i < (int)pos.size(); i += 2) {
		add_edge(pos[i].second, pos[i + 1].second);
	}
	fill(col, col + 2 * n, -1);
	for (int i = 0; i < 2 * n; ++ i)
		if (col[i] == -1) dfs(i, 0);
	for (int i = 0; i < n; ++ i)
		cout << col[i << 1] << " \n"[i == n - 1];
	return 0;
}
