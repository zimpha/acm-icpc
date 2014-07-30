#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 100;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

double V[MAXN][MAXN];
double A[MAXN][MAXN], sol[MAXN];
int H[MAXN][MAXN], id[MAXN][MAXN];
bool vis[MAXN][MAXN];
int N, M, cnt;

bool check(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) return false;
	if (H[x][y] == -1) return false;
	return true;
}

bool bfs(int sx, int sy, int ex, int ey) {
	queue<int> qx, qy;
	memset(vis, 0, sizeof(vis));
	qx.push(sx); qy.push(sy);
	vis[sx][sy] = true;
	while (!qx.empty()) {
		int x = qx.front(), y = qy.front();
		qx.pop(); qy.pop();
		for (int i = 0; i < 4; ++ i) {
			int xx = x + dx[i], yy = y + dy[i];
			if (check(xx, yy) && !vis[xx][yy]) {
				vis[xx][yy] = true;
				qx.push(xx); qy.push(yy);
			}
		}
	}
	return vis[ex][ey];
}

void gauss(int n, double A[][MAXN], double sol[]) {
	for (int i = 0; i < n; ++ i) {
		int r = i;
		for (int j = i + 1; j < n; ++ j) {
			if (fabs(A[j][i]) > fabs(A[r][i])) r = j;
		}
		for (int j = 0; j < n; ++ j) swap(A[r][j], A[i][j]);
		swap(sol[r], sol[i]);
		double now = A[i][i];
		for (int j = 0; j < n; ++ j) A[i][j] /= now; sol[i] /= now;
		for (int j = 0; j < n; ++ j) {
			if (j == i) continue;
			double t = A[j][i] / A[i][i];
			for (int k = 0; k < n; ++ k) A[j][k] -= A[i][k] * t;
			sol[j] -= sol[i] * t;
		}
	}
}

int main() {
	while (scanf("%d%d", &N, &M) == 2) {
		for (int i = 0; i < N; ++ i) {
			for (int j = 0; j < M; ++ j) {
				scanf("%d", &H[i][j]);
				if (H[i][j] > H[0][0]) V[i][j] = H[i][j] = -1;
				else {
					V[i][j] = sqrt(20.0 * (H[0][0] - H[i][j]));
				}
			}
		}
		if (!bfs(0, 0, N - 1, M - 1)) {
			puts("Never reach!");
			continue;
		}
		cnt = 0;
		for (int i = 0; i < N; ++ i) {
			for (int j = 0; j < M; ++ j) {
				if (vis[i][j]) id[i][j] = cnt ++;
			}
		}
		memset(A, 0, sizeof(A)); memset(sol, 0, sizeof(sol));
		for (int i = 0; i < N; ++ i) {
			for (int j = 0; j < M; ++ j) {
				if (!vis[i][j]) continue;
				if (i == N - 1 && j == M - 1) {
					A[id[i][j]][id[i][j]] = 1.0;
					sol[id[i][j]] = 0;
					continue;
				}
				int sum = 0;
				for (int k = 0; k < 4; ++ k) {
					int x = i + dx[k], y = j + dy[k];
					if (check(x, y) && vis[x][y]) sum ++;
				}
				for (int k = 0; k < 4; ++ k) {
					int x = i + dx[k], y = j + dy[k];
					if (!(check(x, y) && vis[x][y])) continue;
					A[id[i][j]][id[x][y]] = -1.0 / sum;
					double h = sqrt(1 + (H[i][j] - H[x][y]) * (H[i][j] - H[x][y]));
					sol[id[i][j]] += 2 * h / (V[i][j] + V[x][y]) / sum;
				}
				A[id[i][j]][id[i][j]] = 1.0;
			}
		}
		gauss(cnt, A, sol);
		printf("%.10f\n", sol[0]);
	}
	return 0;
}
