#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN = 20;

char grid[MAXN][MAXN];
int N;

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) scanf("%s", grid[i]);
		for (int i = 0; i < N; ++ i) 
			for (int j = 0; j < N; ++ j) {
				if (grid[i][j] != '.') continue;
				for (char ch = 'A'; ch <= 'Z'; ++ ch) {
					bool flag = true;
					if (i > 0 && grid[i - 1][j] == ch) flag = false;
					if (j > 0 && grid[i][j - 1] == ch) flag = false;
					if (i < N - 1 && grid[i + 1][j] == ch) flag = false;
					if (j < N - 1 && grid[i][j + 1] == ch) flag = false;
					if (flag) {grid[i][j] = ch; break;}
				}
			}
		printf("Case %d:\n", cas);
		for (int i = 0; i < N; ++ i) puts(grid[i]);
	}
	return 0;
}
