#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;

vector<int> G[MAXN], SCC[MAXN];
int low[MAXN], dfn[MAXN], stk[MAXN], vis[MAXN], cost[MAXN];
int n, m, scc_cnt, top, tid;

void dfs(int x) {
	low[x] = dfn[x] = ++ tid;
	stk[top ++] = x; vis[x] = true;
	for (int y : G[x]) {
		if (!dfn[y]) {
			dfs(y);
			low[x] = min(low[x], low[y]);
		}
		else if (vis[y]) low[x] = min(low[x], low[y]);
	}
	if (dfn[x] == low[x]) {
		int y;
		do {
			y = stk[-- top];
			vis[y] = false;
			SCC[scc_cnt].push_back(cost[y]);
		} while (y != x);
		scc_cnt ++;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++ i) cin >> cost[i];
	cin >> m;
	for (int i = 0, a, b; i < m; ++ i) {
		cin >> a >> b; a --, b --;
		G[a].push_back(b);
	}
	scc_cnt = 0, top = 0, tid = 0;
	for (int i = 0; i < n; ++ i)
		if (!dfn[i]) dfs(i);
	long long money = 0, ret = 1;
	for (int i = 0; i < scc_cnt; ++ i) {
		sort(SCC[i].begin(), SCC[i].end());
		long long tmp = 0;
		for (int j : SCC[i]) tmp += (j == SCC[i][0]);
		ret = ret * tmp % 1000000007l;
		money += SCC[i][0];
	}
	cout << money << " " << ret << endl;
	return 0;
}
