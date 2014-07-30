#include <cstdio>
#include <cstring>

const int MAXN = 200;

int B[MAXN][MAXN], S[MAXN][MAXN];
int ret[MAXN][MAXN];
int N, M, Q, R;

inline void cover(int x0, int y0) {
	int sx = Q / 2, sy = R / 2;
	for (int i = 0; i < Q; ++ i) {
		for (int j = 0; j < R; ++ j) {
			int dx = i - sx, dy = j - sy;
			if (dx + x0 < 0 || dx + x0 >= N) continue;
			if (dy + y0 < 0 || dy + y0 >= M) continue;
			ret[dx + x0][dy + y0] |= S[i][j];
		}
	}
}

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; ++ i) {
			for (int j = 0; j < M; ++ j) {
				scanf("%d", &B[i][j]);
			}
		}
		scanf("%d%d", &Q, &R);
		for (int i = 0; i < Q; ++ i) {
			for (int j = 0; j < R; ++ j) {
				scanf("%d", &S[i][j]);
			}
		}
		memcpy(ret, B, sizeof(B));
		for (int i = 0; i < N; ++ i) {
			for (int j = 0; j < M; ++ j) {
				if (B[i][j] == 1) {
					cover(i, j);
				}
			}
		}
		printf("Case %d:\n", cas);
		for (int i = 0; i < N; ++ i) {
			for (int j = 0; j < M; ++ j) {
				if (j) putchar(' ');
				printf("%d", ret[i][j]);
			}
			puts("");
		}
	}
	return 0;
}
