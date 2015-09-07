#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 200000 + 10;

vector<int> G[MAXN], blk[MAXN];
int low[MAXN], dfn[MAXN], stk[MAXN], belong[MAXN];
int vis[MAXN], sol[MAXN], age[MAXN];
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
			blk[cnt].push_back(y);
			belong[y] = cnt;
		} while (y != x);
		cnt ++;
	}
}

inline int get_value(int x) {
	int r = (x & 1) ? x ^ 1 : x;
	if (sol[r] == -1) return -1;
	return (x & 1) ? !sol[r] : sol[r];
}

void construct() {
	for (int i = 0; i < cnt; ++ i) {
		int val = 1;
		for (int j = 0; j < (int)blk[i].size(); ++ j) {
			int cur = blk[i][j];
			if (get_value(cur) == 0) val = 0;
			for (int k = 0; k < (int)G[cur].size(); ++ k)
				if (get_value(G[cur][k]) == 0) val = 0;
			if (val == 0) break;
		}
		for (int j = 0; j < (int)blk[i].size(); ++ j) {
			if (blk[i][j] & 1) sol[blk[i][j] ^ 1] = !val;
			else sol[blk[i][j]] = val;
		}
	}
}

bool check(int n) {
	for (int i = 0; i < 2 * n; ++ i) {
		vis[i] = 0; dfn[i] = 0;
		sol[i] = -1;
		blk[i].clear();
	}
	cnt = top = tid = 0;
	for (int i = 0; i < 2 * n; ++ i)
		if (!dfn[i]) dfs(i);
	for (int i = 0; i < 2 * n; ++ i)
		if (belong[i] == belong[i ^ 1]) return false;
	construct();
	return true;
}

int main() {
	while (scanf("%d%d", &n, &m) == 2 && n) {
		int ave = 0;
		for (int i = 0; i < n; ++ i) {
			scanf("%d", &age[i]);
			ave += age[i];
		}
		for (int i = 0; i < 2 * n; ++ i) G[i].clear();
		while (m --) {
			int a, b; scanf("%d%d", &a, &b);
			a --; b --;
			int u = a * 2, v = b * 2;
			if ((n * age[a] >= ave && n * age[b] >= ave) || (n * age[a] < ave && n * age[b] < ave)) {
				G[u].push_back(v ^ 1);
				G[v].push_back(u ^ 1);
				G[u ^ 1].push_back(v);
				G[v ^ 1].push_back(u);
			}
			else {
				G[u ^ 1].push_back(v);
				G[v ^ 1].push_back(u);
			}
		}
		if (check(n)) {
			for (int i = 0; i < n; ++ i) {
				if (n * age[i] >= ave) {
					if (sol[2 * i] == 1 || sol[2 * i + 1] == 0) puts("A");
					else puts("C");
				}
				else {
					if (sol[2 * i] == 1 || sol[2 * i + 1] == 0) puts("B");
					else puts("C");
				}
			}
		}
		else {
			puts("No solution.");
		}
	}
	return 0;
}
