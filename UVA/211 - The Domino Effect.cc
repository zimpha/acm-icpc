#include <cstdio>
#include <cstring>
#include <cstdlib>
const int R = 7;
const int C = 8;
const int dx[] = {0, 1};
const int dy[] = {1, 0};

int pip[7][7], grid[10][10], ret[10][10], ans, rec[100];

inline void init() {
	int ret = 0;
	for (int i = 0; i < 7; ++ i)
		for (int j = i; j < 7; ++ j)
			pip[i][j] = pip[j][i] = ++ ret;
}

inline bool Read() {
	for (int i = 0; i < R; ++ i)
		for (int j = 0; j < C; ++ j)
			if (scanf("%d", &grid[i][j]) != 1) return false;
	return true;
}

inline void output() {
	for (int i = 0; i < R; ++ i) {
		for (int j = 0; j < C; ++ j) 
			printf("%4d", ret[i][j]);
		puts("");
	}
	puts("");
}

void dfs(int x, int y, int cnt) {
	if (cnt == 28) {
		ans ++;
		output();
		return;
	}
	if (y == C) x ++, y = 0;
	if (ret[x][y]) dfs(x, y + 1, cnt);
	else {
		for (int i = 0; i < 2; ++ i) {
			int p = x + dx[i], q = y + dy[i];
			if (p >= R || q >= C || ret[p][q]) continue;
			int bones = pip[grid[x][y]][grid[p][q]];
			if (rec[bones]) continue;
			ret[x][y] = ret[p][q] = bones; rec[bones] = 1;
			dfs(x, y + 1, cnt + 1);
			ret[x][y] = ret[p][q] = rec[bones] = 0;
		}
	}
}

int main() {
	int cas = 0;
	init();
	while (Read()) {
		if (cas) printf("\n\n\n");
		printf("Layout #%d:\n\n", ++ cas);
		for (int i = 0; i < R; ++ i) {
			for (int j = 0; j < C; ++ j) printf("%4d", grid[i][j]);
			puts("");
		}
		printf("\nMaps resulting from layout #%d are:\n\n", cas);
		ans = 0;
		memset(rec, 0, sizeof(rec));
		memset(ret, 0, sizeof(ret));
		dfs(0, 0, 0);
		printf("There are %d solution(s) for layout #%d.\n", ans, cas);
	}
	return 0;
}
