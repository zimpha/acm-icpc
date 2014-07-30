#include <vector>
#include <cctype>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 5000 + 10;

char buf[1000000];
vector<int> G[MAXN];
bitset<MAXN> C[MAXN];
int Q[MAXN], deg[MAXN];
int X[MAXN], N, K;

int main() {
	freopen("i.in", "r", stdin);
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; ++ i) scanf("%d ", X + i);
	for (int i = 0; i < N; ++ i) {
		G[i].clear(), deg[i] = 0;
		C[i].reset(); C[i].set(i, 1);
	}
	for (int i = 0; i < N; ++ i) {
		gets(buf);
		int id, flag = 0, v, len = strlen(buf);
		for (int i = 0; i < len; ++ i) {
			if (isdigit(buf[i])) {
				sscanf(buf + i, "%d", &v); v --;
				if (!flag) id = v, flag = 1;
				else G[id].push_back(v), deg[v] ++;
				while (isdigit(buf[i])) ++ i;
			}
		}
	}
	int h = 0, t = 0;
	for (int i = 0; i < N; ++ i) 
		if (deg[i] == 0) Q[t ++] = i;
	for (; h < t; h ++) {
		int u = Q[h];
		for (int i = 0, v; i < (int)G[u].size(); ++ i) {
			deg[v = G[u][i]] --;
			if (deg[v] == 0) Q[t ++] = v;
		}
	}
	for (int i = N - 1; i >= 0; -- i) {
		int u = Q[i];
		for (int j = 0; j < (int)G[u].size(); ++ j) C[u] |= C[G[u][j]];
	}
	sort(X, X + K);
	int ret, cnt = 0;
	for (int i = 0; i < K; ++ i) {
		int tmp = C[X[i] - 1].count();
		if (tmp > cnt) ret = X[i], cnt = tmp;
	}
	printf("%d\n", ret);
	fclose(stdin); return 0;
}
