#include <cstdio>
#include <cstring>

const int MAXN=15;

int grid[MAXN][MAXN];
int now[MAXN][MAXN];
int N, M;

int main() {
	while (scanf("%d%d", &N, &M) == 2) {
		int ans = 10000000;
		for (int i = 1; i <= N; ++ i)
			for (int j = 1; j <= M; ++ j)
				scanf("%d", &grid[i][j]);
		for (int mask1 = 0; mask1 < (1 << N); ++ mask1)
			for (int mask2 = 0; mask2 < (1 << M); ++ mask2) {
				memset(now, 0, sizeof(now));
				for (int i = 0; i < N; ++ i) now[i + 1][0] = ((mask1 >> i) & 1);
				for (int i = 0; i < M; ++ i) now[1][i + 1] = ((mask2 >> i) & 1);
				bool flag = true;
				for (int i = 2; i <= N && flag; ++ i)
					for (int j = 1; j <= M && flag; ++ j) {
						now[i][j] = grid[i - 1][j] - now[i][j - 1] - now[i - 1][j - 1] - now[i - 2][j - 1] - now[i - 1][j] - now[i - 2][j];
						if (now[i][j] < 0 || now[i][j] > 1) flag = false;
					}
				for (int i = 1; i <= N && flag; ++ i)
					for (int j = 1; j <= M && flag; ++ j)
						if (grid[i][j] != now[i][j] + now[i - 1][j] + now[i + 1][j] + now[i][j - 1] + now[i - 1][j - 1] + now[i + 1][j - 1]) 
							flag = false;
				if (flag) {
					int tmp = 0;
					for (int i = 1; i <= N; ++ i)
						for (int j = 0; j <= M; ++ j)
							if (now[i][j]) tmp ++;
					if (tmp < ans) ans = tmp;
				}
			}
			printf("%d\n", ans);
	}
	return 0;
}
