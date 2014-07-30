#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 500 + 10;
const int MAXM = 10000 + 10;

int G[MAXN][MAXN];
int x[MAXM], y[MAXM];
int col[MAXN], N, M;
bool vis[MAXM];

bool solve() {
	memset(col, -1, sizeof(col));
	memset(vis, 0, sizeof(vis));
	queue<int> Q;
	col[x[0]] = 0; col[y[0]] = 1;
	Q.push(0); vis[0] = true;
	while (!Q.empty()) {
		int idx = Q.front(); Q.pop();
		int u = x[idx], v = y[idx];
		for (int w = 0; w < N; ++ w) {
			if (col[w] == -1 && G[u][w] != -1 && G[v][w] != -1) {
				col[w] = 3 - col[u] - col[v];
			}
			if (col[w] != -1) {
				if (G[u][w] != -1 && !vis[G[u][w]]) {
					vis[G[u][w]] = true;
					if (col[u] == col[w]) return false;
					Q.push(G[u][w]);
				}
				if (G[v][w] != -1 && !vis[G[v][w]]) {
					vis[G[v][w]] = true;
					if (col[v] == col[w]) return false;
					Q.push(G[v][w]);
				}
			}
		}
	}
	for (int i = 0; i < M; ++ i) 
		if (col[x[i]] == col[y[i]]) return false;
	return true;
}

int main() {
	freopen("mayors.in", "r", stdin);
	freopen("mayors.out", "w", stdout);
	scanf("%d%d", &N, &M);
	memset(G, -1, sizeof(G));
	for (int i = 0; i < M; ++ i) {
		scanf("%d%d", &x[i], &y[i]);
		x[i] --; y[i] --;
		G[x[i]][y[i]] = G[y[i]][x[i]] = i;
	}
	if (N == 1) {
		puts("Plan OK\nR");
		return 0;
	}
	if (solve()) {
		puts("Plan OK");
		for (int i = 0; i < N; ++ i) {
			putchar("RGB"[col[i]]);
		}
		puts("");
	}
	else puts("Plan failed");
	memset(col, -1, sizeof(col));
	fclose(stdin); fclose(stdout);
	return 0;
}
