#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 10, inf = 0x3f3f3f3f;

int G[MAXN][MAXN], ID[MAXN];
int match[MAXN], stk[MAXN];
int vis[MAXN], dis[MAXN];
int N, M, K, top;

bool spfa(int u) {
	stk[top ++] = u;
	if (vis[u]) return true;
	vis[u] = true;
	for (int i = 1; i <= K; ++ i) {
		if (i != u && i != match[u] && !vis[i]) {
			int v = match[i];
			if (dis[v] < dis[u] + G[u][i] - G[i][v]) {
				dis[v] = dis[u] + G[u][i] - G[i][v];
				if (spfa(v)) return true;
			}
		}
	}
	top --; vis[u] = false;
	return false;
}

int MaxWeightMatch() {
	for (int i = 1; i <= K; ++ i) ID[i] = i;
	for (int i = 1; i <= K; i += 2) match[i] = i + 1, match[i + 1] = i;
	for (int times = 0, flag; times < 3; ) {
		memset(dis, 0, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		top = 0; flag = 0;
		for (int i = 1; i <= K; ++ i) {
			if (spfa(ID[i])) {
				flag = 1;
				int t = match[stk[top - 1]], j = top - 2;
				while (stk[j] != stk[top - 1]) {
					match[t] = stk[j];
					swap(t, match[stk[j]]);
					-- j;
				}
				match[t] = stk[j]; match[stk[j]] = t;
				break;
			}
		}
		if (!flag) times ++;
		if (!flag) random_shuffle(ID + 1, ID + K + 1);
	}
	int ret = 0;
	for (int i = 1; i <= K; ++ i)
		if (i < match[i]) ret += G[i][match[i]];
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		scanf("%d%d%d", &N, &M, &K);
		memset(G, 0x3f, sizeof(G));
		for (int i = 1; i <= N; ++ i) G[i][i] = 0;
		for (int i = 0; i < M; ++ i) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			G[u][v] = G[v][u] = w;
		}
		printf("Case %d: ", cas);
		if (K & 1) {
			puts("Impossible");
			continue;
		}
		for (int k = 1; k <= N; ++ k) {
			for (int i = 1; i <= N; ++ i) {
				for (int j = 1; j <= N; ++ j) {
					G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
				}
			}
		}
		for (int i = 1; i <= K; ++ i) {
			for (int j = 1; j <= K; ++ j) {
				G[i][j] = -G[i][j];
			}
			G[i][i] = -inf;
		}
		printf("%d\n", -MaxWeightMatch());
	}
	return 0;
}
