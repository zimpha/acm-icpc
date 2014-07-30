#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN=2005;

struct node {
	int x, y, d;
};

vector<int> G[MAXN];
node ball[MAXN], move[MAXN];
bool vis[MAXN];
int N, cnt;

void dfs(int u) {
	vis[u] = true;
	for (int i = 0; i < (int)G[u].size(); ++ i) {
		int v = G[u][i];
		if (!vis[v]) {
			dfs(v);
			move[cnt] = ball[v];
			if (ball[u].x == ball[v].x && ball[u].y < ball[v].y) move[cnt].d = 4;
			if (ball[u].x == ball[v].x && ball[u].y > ball[v].y) move[cnt].d = 3;
			if (ball[u].y == ball[v].y && ball[u].x < ball[v].x) move[cnt].d = 1;
			if (ball[u].y == ball[v].y && ball[u].x > ball[v].x) move[cnt].d = 2;
			++ cnt;
		}
	}
}

int main() {
	while (scanf("%d", &N) == 1) {
		for (int i = 1; i <= N; ++ i) {
			scanf("%d%d", &ball[i].x, &ball[i].y);
			G[i].clear();
		}
		for (int i = 1; i <= N; ++ i)
			for (int j = i + 1; j <= N; ++ j)
				if (ball[i].x == ball[j].x || ball[i].y == ball[j].y) {
					G[i].push_back(j);
					G[j].push_back(i);
				}
		int ret = 0;
		cnt = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= N; ++ i)
			if (!vis[i]) {
				ret ++;
				dfs(i);
			}
		printf("%d\n", ret);
		for (int i = 0; i < cnt; ++ i) {
			printf("(%d, %d) ", move[i].x, move[i].y);
			switch (move[i].d) {
				case 1: puts("LEFT"); break;
				case 2: puts("RIGHT"); break;
				case 3: puts("UP"); break;
				case 4: puts("DOWN"); break;
			}
		}
	}
	return 0;
}
