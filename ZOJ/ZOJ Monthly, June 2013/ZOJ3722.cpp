#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 55;
const int MAXK = 10;
const int inf = 1e9;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct Ruins {
	int x, y, s;
	void read() {
		scanf("%d%d%d", &x, &y, &s);
	}
};

struct Node {
	int x, y;
	Node() {}
	Node(int x, int y) : x(x), y(y) {}
};

char land[MAXN][MAXN];
bool nowland[MAXN][MAXN];
int stones[MAXN][MAXN];
int dis[MAXK][MAXN][MAXN];
int p[MAXK], vis[MAXK];
int N, M, C, K, ret;
Ruins ruin[MAXK];

inline bool fitRange(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < M);
}

void bfs(int sx, int sy, int d[MAXN][MAXN]) {
	for (int i = 0; i < N; ++ i) {
		for (int j = 0; j < M; ++ j) {
			d[i][j] = inf;
		}
	}
	queue<Node> Q;
	d[sx][sy] = 0; Q.push(Node(sx, sy));
	while (!Q.empty()) {
		int x = Q.front().x, y = Q.front().y; Q.pop();
		for (int i = 0; i < 4; ++ i) {
			int xx = x + dx[i], yy = y + dy[i];
			if (!fitRange(xx, yy) || land[xx][yy] == 'X') continue;
			if (d[xx][yy] > d[x][y] + 1) {
				d[xx][yy] = d[x][y] + 1;
				Q.push(Node(xx, yy));
			}
		}
	}
}

int solve() {
	memset(nowland, 0, sizeof(nowland));
	vector<Node> now, next;
	for (int i = 0; i < N; ++ i) {
		for (int j = 0; j < M; ++ j) {
			if (land[i][j] != '*') continue;
			nowland[i][j] = true;
			now.push_back(Node(i, j));
		}
	}
	vector<int> produce;
	priority_queue<int> opt;
	int total = 0, idx = 1, extra = dis[K][ruin[p[1]].x][ruin[p[1]].y];
	for (int times = 0; ; ++ times) {
		if (total >= C) return times;
		if (times % 5 == 0) {
			next.clear();
			for (int i = 0; i < (int)now.size(); ++ i) {
				int x = now[i].x, y = now[i].y;
				if (stones[x][y] > 0) opt.push(stones[x][y]);
				for (int j = 0; j < 4; ++ j) {
					int xx = x + dx[j], yy = y + dy[j];
					if (fitRange(xx, yy) && !nowland[xx][yy] && land[xx][yy] != 'X') {
						next.push_back(Node(xx, yy));
						nowland[xx][yy] = true;
					}
				}
			}
			now = next;
			if (!opt.empty()) {
				produce.push_back(opt.top());
				opt.pop();
			}
		}
		bool flag = true;
		for (int i = 0; i < (int)produce.size(); ++ i) {
			if (produce[i] == 0) continue;
			total += produce[i] --; flag = false;
		}
		if (idx <= K && 2 * (times + 1) >= extra) {
			total += ruin[p[idx]].s;
			extra += dis[p[idx]][ruin[p[idx + 1]].x][ruin[p[idx + 1]].y];
			idx ++;
		}
		if (now.empty() && flag && opt.empty() && (idx > K || extra >= inf)) return inf;
	}
	return 0;
}

void dfs(int dep) {
	if (dep > K) {
		ret = min(ret, solve());
		return;
	}
	for (int i = 0; i < K; ++ i) {
		if (vis[i]) continue;
		p[dep] = i; vis[i] = true;
		dfs(dep + 1);
		vis[i] = false;
	}
}

int main() {
	while (scanf("%d%d%d", &N, &M, &C) == 3) {
		for (int i = 0; i < N; ++ i) scanf("%s", land[i]);
		for (int i = 0; i < N; ++ i) {
			for (int j = 0; j < M; ++ j) {
				scanf("%d", &stones[i][j]);
			}
		}

		scanf("%d", &K);
		for (int i = 0; i < K; ++ i) ruin[i].read();
		scanf("%d%d", &ruin[K].x, &ruin[K].y);

		for (int i = 0; i <= K; ++ i) {
			ruin[i].x --; ruin[i].y --;
			bfs(ruin[i].x, ruin[i].y, dis[i]);
		}

		ret = inf;
		memset(vis, 0, sizeof(vis));
		p[0] = K;
		dfs(1);
		if (ret == inf) ret = -1;
		printf("%d\n", ret);
	}
	return 0;
}


