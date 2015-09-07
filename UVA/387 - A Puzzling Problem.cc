#include <cstdio>
#include <cstring>
#include <cstdlib>

struct Block {
	int r, c;
	char a[10][10];
} A[20];

int n, grid[10][10], vis[20];
bool flag;

inline bool fill(int x, int y, int id) {
	for (int i = 0; i < A[id].r; ++ i)
		for (int j = 0; j < A[id].c; ++ j)
			if (A[id].a[i][j] == '1' && grid[x + i][y + j]) return false;
	for (int i = 0; i < A[id].r; ++ i)
		for (int j = 0; j < A[id].c; ++ j)
			if (A[id].a[i][j] == '1') grid[x + i][y + j] = id + 1;
	return true;
}

inline void unfill(int x, int y, int id) {
	for (int i = 0; i < A[id].r; ++ i)
		for (int j = 0; j < A[id].c; ++ j)
			if (A[id].a[i][j] == '1') grid[x + i][y + j] = 0;
}

inline bool check() {
	for (int i = 0; i < 4; ++ i)
		for (int j = 0; j < 4; ++ j)
			if (!grid[i][j]) return false;
	return true;
}

void dfs(int x, int y, int dep) {
	if (x >= 4) {
		if (dep == n && check()) {
			flag = 1;
			for (int i = 0; i < 4; ++ i) {
				for (int j = 0; j < 4; ++ j)
					printf("%d", grid[i][j]);
				puts("");
			}
		}
		return;
	}
	for (int i = 0; i < n && !flag; ++ i) {
		if (!vis[i] && fill(x, y, i)) {
			vis[i] = 1;
			if (y >= 3) dfs(x + 1, 0, dep + 1);
			else dfs(x, y + 1, dep + 1);
			unfill(x, y, i); vis[i] = 0;
		} 
	}
	if (flag) return;
	if (y >= 3) dfs(x + 1, 0, dep);
	else dfs(x, y + 1, dep);
}

int main() {
	int cas = 0;
	while (scanf("%d", &n) == 1 && n) {
		if (cas) puts(""); cas ++;
		for (int i = 0; i < n; ++ i) {
			scanf("%d%d", &A[i].r, &A[i].c);
			for (int j = 0; j < A[i].r; ++ j) scanf("%s", A[i].a[j]);
		}
		memset(grid, -1, sizeof(grid));
		for (int i = 0; i < 4; ++ i)
			for (int j = 0; j < 4; ++ j)
				grid[i][j] = 0;
		memset(vis, 0, sizeof(vis)); flag = false;
		dfs(0, 0, 0);
		if (!flag) puts("No solution possible");
	}
	return 0;
}
