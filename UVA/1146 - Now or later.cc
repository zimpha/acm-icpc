#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 4000 + 10;

vector<int> G[MAXN];
int low[MAXN], dfn[MAXN], stk[MAXN], belong[MAXN];
int vis[MAXN], T[MAXN][2];
int n, m, cnt, top, tid;

void dfs(int x) {
	low[x] = dfn[x] = ++ tid;
	stk[top ++] = x; vis[x] = true;
	for (int i = 0, y; i < (int)G[x].size(); ++ i) {
		if (!dfn[y = G[x][i]]) {
			dfs(y);
			low[x] = min(low[x], low[y]);
		}
		else if (vis[y]) low[x] = min(low[x], dfn[y]);
	}
	if (dfn[x] == low[x]) {
		int y;
		do {
			y = stk[-- top];
			vis[y] = false;
			belong[y] = cnt;
		} while (y != x);
		cnt ++;
	}
}

bool check() {
	for (int i = 0; i < 2 * n; ++ i) {
		vis[i] = 0; dfn[i] = 0;
	}
	cnt = top = tid = 0;
	for (int i = 0; i < 2 * n; ++ i)
		if (!dfn[i]) dfs(i);
	for (int i = 0; i < 2 * n; ++ i)
		if (belong[i] == belong[i ^ 1]) return false;
	return true;
}

void build(int lim) {
	for (int i = 0; i < 2 * n; ++ i) G[i].clear();
	for (int i = 0; i < n; ++ i) for (int a = 0; a < 2; ++ a) {
		for (int j = i + 1; j < n; ++ j) for (int b = 0; b < 2; ++ b) {
			int u = 2 * i + a, v = 2 * j + b;
			if (abs(T[i][a] - T[j][b]) < lim) {
				G[u].push_back(v ^ 1);
				G[v].push_back(u ^ 1);
			}
		}
	}
}

int main() {
	while (scanf("%d", &n) == 1) {
		int left = 0, right = 0;
		for (int i = 0; i < n; ++ i) {
			scanf("%d%d", &T[i][0], &T[i][1]);
			right = max(right, T[i][1]);
			right = max(right, T[i][0]);
		}
		while (left < right) {
			int mid = (left + right + 1) >> 1;
			build(mid);
			if (check()) left = mid;
			else right = mid - 1;
		}
		printf("%d\n", left);
	}
	return 0;
}
