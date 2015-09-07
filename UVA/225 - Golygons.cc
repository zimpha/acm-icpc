#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int N = 222;
const char ANS[5] = {"ensw"};
const int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int O = 105;

int t, n, m, g[N][N], ans[25], vis[N][N], sum[25], ansn;

void init() {
	ansn = 0;
	memset(g, 0, sizeof(g));
	memset(vis, 0, sizeof(vis));
	vis[O][O] = 1;
	scanf("%d%d", &n, &m);
	int x, y;
	while (m--) {
		scanf("%d%d", &x, &y);
		if (abs(x) > O || abs(y) > O) continue;
		g[y + O][x + O] = 1;
	}
}

bool judge(int x, int y, int xx, int yy, int k, int i) {
	if (abs(xx - O) + abs(yy - O) > sum[n] - sum[k + 1]) return false;	
	if ((vis[xx][yy] || g[xx][yy]) && !(xx == O && yy == O && k + 1 == n)) return false;
	int xxx = x, yyy = y;
	while (xxx != xx - d[i][0]) {
		xxx += d[i][0];
		if (g[xxx][y]) return false;
	}
	while (yyy != yy - d[i][1]) {
		yyy += d[i][1];
		if (g[x][yyy]) return false;
	}
	return true;
}

void dfs(int x, int y, int k, int v) {
	if (g[x][y]) return;
	if (k == n) {
		if (x == O && y == O) {
			ansn ++;
			for (int j = 0; j < k; j ++)
				printf("%c", ANS[ans[j]]);
			printf("\n");
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (i == v || i + v == 3) continue;
		int xx = x + d[i][0] * (k + 1);
		int yy = y + d[i][1] * (k + 1);
		if (!judge(x, y, xx, yy, k, i)) continue;
		ans[k] = i;
		vis[xx][yy]++;
		dfs(xx, yy, k + 1, i);
		vis[xx][yy]--;
	}
}

void solve() {
	dfs(O, O, 0, -1);
	printf("Found %d golygon(s).\n\n", ansn);
}

void sum_table() {
	sum[0] = 0;
	for (int i = 1; i <= 20; i++)
		sum[i] = sum[i - 1] + i;
}

int main() {
	sum_table();
	scanf("%d", &t);
	while (t--) {
		init();
		solve();
	}
	return 0;
}
