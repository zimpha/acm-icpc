#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;;
const int MAXN = 2000 + 10;

bool r[MAXN], c[MAXN], d1[MAXN], d2[MAXN];
bool Q[MAXN][MAXN];
int N, M;

int fork(int x, int y) {
	int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
	int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
	int ret = 0;
	for (int i = 0; i < 8; ++ i) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx < 1 || xx > N || yy < 1 || yy > N) continue;
		if (Q[xx][yy]) ret ++;
	}
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		memset(r, 0, sizeof(r));
		memset(c, 0, sizeof(c));
		memset(d1, 0, sizeof(d1));
		memset(d2, 0, sizeof(d2));
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= N; ++ i) {
			for (int j = 1; j <= N; ++ j) {
				Q[i][j] = false;
			}
		}
		while (M --) {
			int x, y; scanf("%d%d", &x, &y);
			r[x] = c[y] = Q[x][y] = true;
			d1[x + y] = d2[x - y + N] = true;
		}
		int ret = 0;
		for (int x = 1; x <= N; ++ x) {
			for (int y = 1; y <= N; ++ y) {
				if (r[x] || c[y] || d1[x + y] || d2[x - y + N]) continue;
				if (Q[x][y]) continue;
				if (fork(x, y) >= 2) ret ++;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
