#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
const int MAXN = 50;
const int SIZE = 2000;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

vector<int> G[SIZE];
char grid[MAXN][MAXN];
int id[MAXN][MAXN];
int N, M, C;

bool fit(int x, int y) {
	return (x >= 0 && x < N && y >= 0&& y < M);
}

void gao(int sx, int sy, int c) {
	queue<int> qx, qy;
	qx.push(sx); qy.push(sy);
	id[sx][sy] = c;
	while (!qx.empty()) {
		int x = qx.front(), y = qy.front(); qx.pop(); qy.pop();
		for (int i = 0; i < 4; ++ i) {
			int xx = x + dx[i], yy = y + dy[i];
			if (fit(xx, yy) && id[xx][yy] == -1 && grid[xx][yy] == grid[sx][sy]) {
				id[xx][yy] = c;
				qx.push(xx); qy.push(yy);
			}
		}
	}
}

int dis[SIZE];

int bfs(int s) {
	queue<int> Q;
	memset(dis, -1, sizeof(dis));
	Q.push(s); dis[s] = 0;
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		for (int i = 0; i < (int)G[u].size(); ++ i) {
			int v = G[u][i];
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1;
				Q.push(v);
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < C; ++ i) ret = max(ret, dis[i]);
	return ret;
}

int main(){
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; ++ i) scanf("%s", grid[i]);
		memset(id, -1, sizeof(id));
		C = 0;
		for (int i = 0; i < N; ++ i) {
			for (int j = 0; j < M; ++ j) {
				if (id[i][j] == -1) {
					gao(i, j, C);
					C ++;
				}
			}
		}
		for (int i = 0; i < C; ++ i) G[i].clear();
		for (int x = 0; x < N; ++ x) {
			for (int y = 0; y < M; ++ y) {
				int u = id[x][y];
				for (int i = 0; i < 4; ++ i) {
					int xx = x + dx[i], yy = y + dy[i];
					if (!fit(xx, yy)) continue;
					int v = id[xx][yy];
					if (u == v) continue;
					G[u].push_back(v);
					G[v].push_back(u);
				}
			}
		}
		int ret = N * M;
		for (int i = 0; i < C; ++ i) {
			int t = bfs(i);
			if (t < ret) ret = t;
		}
		printf("%d\n", ret);
	}
	return 0;	
}
