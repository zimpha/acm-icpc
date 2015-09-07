#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 3010;
const int MAXM = 100010;

struct Node {
	int u, v, w;
	bool operator < (const Node &oth) const {
		return (w < oth.w);
	}
};

vector <int> G[MAXN], W[MAXN];
int f[MAXN], ret[MAXN][MAXN];
Node E[MAXM];
int N, M;

int Find(int x) {
	if (x != f[x]) f[x] = Find(f[x]);
	return f[x];
}

void Kruskal() {
	sort(E, E + M);
	for (int i = 0; i < N; ++ i) {
		f[i] = i;
		G[i].clear();
		W[i].clear();
	}
	for (int i = 0; i < M; ++ i) {
		int u = Find(E[i].u), v = Find(E[i].v);
		if (u != v) {
			G[E[i].u].push_back(E[i].v); W[E[i].u].push_back(E[i].w);
			G[E[i].v].push_back(E[i].u); W[E[i].v].push_back(E[i].w);
			f[u] = v;
		}	
	}
}

void get_ans(int a, int u, int f, int w) {
	for (int i = 0; i < (int)G[u].size(); ++ i) {
		int v = G[u][i];
		if (v != f) {
			ret[a][v] = max(w, W[u][i]);
			get_ans(a, v, u, ret[a][v]);
		}
	}
}

int main() {
	int T, Q;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < M; ++ i) {
			scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].w);
			E[i].u --; E[i].v --;
		}
		Kruskal();
		scanf("%d", &Q);
		printf("Case %d\n", cas);
		memset(ret, -1, sizeof(ret));
		for (int i = 0, a, b; i < Q; ++ i) {
			scanf("%d%d", &a, &b);
			a--; b--;
			if (ret[a][b] == -1) {
				get_ans(a, a, -1, -1);
			}
			printf("%d\n", ret[a][b]);
		}
		puts("");
	}
	return 0;
}
