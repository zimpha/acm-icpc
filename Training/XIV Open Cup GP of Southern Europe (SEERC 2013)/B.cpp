#include <set>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 500000 + 10;
typedef long long LL;

set<int> S[MAXN];
vector<int> G[MAXN];
int dis[MAXN], Q[MAXN];
int N, K, A, B;

void bfs1() {
	memset(dis, -1, sizeof(dis));
	int h = 0, t = 0;
	Q[t ++] = 1; dis[1] = 0;
	for (; h < t; ++ h) {
		int u = Q[h];
		for (int i = 0, v; i < (int)G[u].size(); ++ i) {
			if (dis[v = G[u][i]] == -1) {
				dis[v] = dis[u] + 1;
				Q[t ++] = v;
			}
		}
	}
}

int R[MAXN], L[MAXN];

void bfs2() {
	for (int i = 1; i <= N; ++ i) L[i] = i - 1, R[i] = i + 1;
	memset(dis, -1, sizeof(dis));
	int h = 0, t = 0;
	Q[t ++] = 1; dis[1] = 0;
	for (; h < t; h ++) {
		int u = Q[h];
		for (int v = R[1]; v != N + 1; v = R[v]) {
			if (S[u].count(v)) continue;
			dis[v] = dis[u] + 1; Q[t ++] = v;
			L[R[v]] = L[v]; R[L[v]] = R[v];
		}
	}
}

int main() {
	freopen("b.in", "r", stdin);
	scanf("%d%d%d%d", &N, &K, &A, &B);
	for (int i = 1; i <= N; ++ i) {
		G[i].clear(); S[i].clear();
	}
	while (K --) {
		int x, y; scanf("%d%d", &x, &y);
		G[x].push_back(y); G[y].push_back(x);
		S[x].insert(y); S[y].insert(x);
	}
	if (A == B) printf("%d\n", A);
	else if (A < B) {
		if (S[1].count(N)) printf("%d\n", A);
		else {
			bfs1();
			if (dis[N] == -1) printf("%d\n", B);
			else printf("%d\n", min(B, A * dis[N]));
		}
	}
	else {
		if (!S[1].count(N)) printf("%d\n", B);
		else {
			bfs2();
			if (dis[N] == -1) printf("%d\n", A);
			else printf("%d\n", min(B * dis[N], A));
		}
	}
	return 0;
}
