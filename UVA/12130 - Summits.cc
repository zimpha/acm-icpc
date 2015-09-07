#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 510;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

struct Node {
	int h, x, y;
	Node () {}
	Node (int x, int y) : x(x), y(y) {}
	bool operator < (const Node &oth) const {
		return h > oth.h;
	}
};

Node p[MAXN * MAXN];
int h[MAXN][MAXN], v[MAXN][MAXN];
int N, M, D;

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d%d", &N, &M, &D);
		int lim = N * M;
		for (int i = 0; i < lim; ++ i) {
			int x = p[i].x = i / M;
			int y = p[i].y = i % M;
			scanf("%d", &p[i].h);
			h[x][y] = p[i].h;
			v[x][y] = -1;
		}
		sort(p, p + lim);
		queue <Node> Q;
		int ret = 0;
		for (int i = 0; i < lim; ++ i) {
			int sx = p[i].x, sy = p[i].y;
			if (v[sx][sy] != -1) continue;
			Q.push(Node(sx, sy));
			bool is_summit = true;
			int cnt = 0;
			while (!Q.empty()) {
				Node now = Q.front(); Q.pop();
				int x = now.x, y = now.y;
				cnt += h[x][y] == h[sx][sy];
				v[x][y] = h[sx][sy];
				for (int k = 0; k < 4; ++ k) {
					int nx = x + dx[k], ny = y + dy[k];
					if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
					if (h[nx][ny] > h[sx][sy] - D) {
						is_summit &= is_summit && v[nx][ny] <= h[sx][sy];
						if (v[nx][ny] == -1) {
							v[nx][ny] = h[sx][sy];
							Q.push(Node(nx, ny));
						}
					}
				}
			}
			if (is_summit) ret += cnt;
		}
		printf("%d\n", ret);
	}
	return 0;
}
