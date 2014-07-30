#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 400 + 10;

vector<int> G[MAXN];
int low[MAXN], dfn[MAXN], stk[MAXN], belong[MAXN];
int vis[MAXN], cnt, top, tid;

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

bool check(int n) {
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

int x[MAXN], y[MAXN], z[MAXN];

inline double sqr(double x) {return x * x;}

inline double dis(int i, int j) {
	return sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]) + sqr(z[i] - z[j]));
}

void build(int n, double lim) {
	for (int i = 0; i < 2 * n; ++ i) G[i].clear();
	for (int i = 0; i < 2 * n; ++ i) {
		for (int j = i + 1; j < 2 * n; ++ j) {
			if ((i ^ 1) == j) continue;
			double d = dis(i, j);
			if (d < 2 * lim) {
				G[i].push_back(j ^ 1);
				G[j].push_back(i ^ 1);
			}
		}
	}
}

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; ++ i) {
			scanf("%d%d%d", &x[2 * i], &y[2 *i], &z[2 * i]);
			scanf("%d%d%d", &x[2 * i + 1], &y[2 *i + 1], &z[2 * i + 1]);
		}
		double left = 0, right = 20000;
		for (int times = 0; times < 100; ++ times) {
			double mid = (left + right) * 0.5;
			build(n, mid);
			if (check(n)) left = mid;
			else right = mid;
		}
		printf("%.3f\n", (int)(left * 1000)/1000.0);
	}
	return 0;
}
