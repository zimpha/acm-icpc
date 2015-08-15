#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 10;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct Node {
	int p, tag;
	int x, y;
	Node() {};
	Node(int p, int t, int x, int y) : p(p), tag(t), x(x), y(y) {};
	bool operator < (const Node &rhs) const {
		if (p != rhs.p) return p < rhs.p;
		return tag < rhs.tag;
	}
};

vector<Node> V;
char grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
int cover[MAXN];
int N, M;

void bfs(int sx, int sy) {
	queue<int> Qx, Qy;
	Qx.push(sx), Qy.push(sy);
	int a, b, c, d;
	a = b = sx; c = d = sy;
	vis[sx][sy] = true;
	while (!Qx.empty()) {
		int x = Qx.front(), y = Qy.front();
		Qx.pop(); Qy.pop();
		a = min(a, x); b = max(b, x);
		c = min(c, y); d = max(d, y);
		for (int i = 0; i < 4; ++ i) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx < 0 || xx >= N || yy < 0 || yy >= M) continue;
			if (grid[xx][yy] != 'W' || vis[xx][yy]) continue;
			vis[xx][yy] = true;
			Qx.push(xx); Qy.push(yy);
		}
	}
	if (a == 0 || b == N - 1) return;
	if (c == 0 || d == M - 1) return;
	V.push_back(Node(a - 1, 1, c, d));
	V.push_back(Node(b + 2, -1, c, d));
	cover[c] ++; cover[d + 1] --;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; ++ i) scanf("%s", grid[i]);
		memset(vis, 0, sizeof(vis));
		memset(cover, 0, sizeof(cover));
		V.clear();
		for (int i = 0; i < N; ++ i) {
			for (int j = 0; j < M; ++ j) {
				if (grid[i][j] == 'W' && !vis[i][j]) bfs(i, j);
			}
		}
		sort(V.begin(), V.end());
		int C = V.size(), cnt = 0;
		bool flag = false;
		for (int i = 0, j = 0; i <= N; ++ i) {
			while (j < C && V[j].p == i) {
				int x = V[j].x, y = V[j].y;
				if (V[j].tag == -1) {
					cnt --;
					cover[x] ++; cover[y + 1] --;
				}
				else {
					cnt ++;
					cover[x] --; cover[y + 1] ++;
				}
				j ++;
			}
			int maxcover = 0, now = 0;
			for (int t = 0; t < M; ++ t) {
				now = now + cover[t];
				if (now > maxcover) maxcover = now;
			}
			if (cnt + maxcover == C / 2) flag = true;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
