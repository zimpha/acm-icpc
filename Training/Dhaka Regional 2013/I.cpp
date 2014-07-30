#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 3000;
const int MAXM = 50000 + 10;

struct Edge {
	int u, v, w, n;
	Edge() {}
	Edge(int u, int v, int w, int n) : u(u), v(v), w(w), n(n) {}
};

Edge E[MAXM];
int G[MAXN], vis[MAXN];
int N, M, cnt, S;

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		scanf("%d%d%d", &N, &M, &S);
		memset(G, -1, sizeof(G)); cnt = 0;
		for (int i = 0; i < M; ++ i) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			E[cnt] = Edge(u, v, 0, G[u]); G[u] = cnt ++;
			E[cnt] = Edge(v, u, 0, G[v]); G[v] = cnt ++;
		}
		queue<int> Q;
		memset(vis, 0, sizeof(vis));
		Q.push(S); vis[S] = 1; cnt = 0;
		while (!Q.empty()) {
			int u = Q.front(); Q.pop();
			for (int now = G[u]; now != -1; now = E[now].n) {
				int v = E[now].v;
				if (!vis[v]) vis[v] = true, Q.push(v);
				if (!E[now].w) E[now].w = E[now ^ 1].w = ++ cnt;
			}
		}
		for (int i = 0; i < M; ++ i)
			if (!E[i << 1].w) E[i << 1].w = ++ cnt;
		printf("Case %d:\n", cas);
		for (int i = 0; i < M; ++ i) {
			printf("%d %d %d\n", E[i << 1].u, E[i << 1].v, E[i << 1].w);
		}
	}
	return 0;
}
