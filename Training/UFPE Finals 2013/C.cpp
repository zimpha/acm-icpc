#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char g[200][200];
char Q[200];
int N, M;

void gao(int n, int m) {
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j < m; j += 2)
			swap(g[i][j], g[i][j + 1]);
	}
	if (m & 1) {
		for (int i = 1; i < n; i += 2) swap(g[i][m], g[i + 1][m]);
	}
}

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		scanf("%s%d%d", Q, &N, &M);
		int len = strlen(Q);
		while (N * M < len) {
			if (N >= M) M += N;
			else N += M;
		}
		int r = len / M, c = len % M, cnt = 0;
		for (int i = M; i > 0; -- i) {
			for (int j = 1; j <= r; ++ j) g[j][i] = Q[cnt ++];
			if (i <= c) g[r + 1][i] = Q[cnt ++];
		}
		gao(r - (!c), M);
		cnt = 0;
		for (int i = 1; i <= r; ++ i) {
			for (int j = 1; j <= M; ++ j) {
				Q[cnt ++] = (g[i][j] - 'a' - i - j) % 26;
				if (Q[cnt - 1] < 0) Q[cnt - 1] += 26;
				Q[cnt - 1] += 'a';
			}
		}
		for (int i = 1; i <= c; ++ i) {
			Q[cnt ++] = (g[r + 1][i] - 'a' - i - r - 1) % 26;
			if (Q[cnt - 1] < 0) Q[cnt - 1] += 26;
			Q[cnt - 1] += 'a';
		}
		Q[cnt] = '\0';
		printf("Case #%d: %s\n", cas, Q);
	}
	return 0;
}
