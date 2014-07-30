#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 50000 + 10;
const int MAXM = 50000 + 10;

struct Edge {
	int u, v, w;
	void read() {
		scanf("%d%d%d", &u, &v, &w);
	}
};

vector<PII> E[MAXN];
vector<int> S;
Edge edge[MAXM];
LL sum[MAXN][2];
int flag[MAXN], deg[MAXN];
int N, M, Q, L;

void Modify(int u) {
	for (int i = 0; i < (int)E[u].size(); ++ i) {
		int v = E[u][i].first, w = E[u][i].second;
		w *= flag[u] * flag[v];
		if (deg[v] <= L) v = 0;
		sum[v][0] -= w; sum[v][1] -= w;
	}
	if (deg[u] > L) {
		sum[u][0] = -sum[u][0]; sum[u][1] = -sum[u][1];
		swap(sum[u][0], sum[u][1]);
	}
	flag[u] = -flag[u];
}

LL getsum(int x) {
	LL ret = sum[0][x];
	for (int i = 0; i < (int)S.size(); ++ i) ret += sum[S[i]][x];
	return ret;
}

int main() {
	int cas = 0;
	while (scanf("%d%d%d", &N, &M, &Q) == 3) {
		fill(deg, deg + 1 + N, 0);
		for (int i = 0; i < M; ++ i) {
			edge[i].read();
			deg[edge[i].u] ++;
			deg[edge[i].v] ++;
		}
		L = (int)sqrt(2 * M); S.clear();
		for (int i = 0; i <= N; ++ i) {
			E[i].clear(); flag[i] = 1;
			sum[i][0] = sum[i][1] = 0;
			if (deg[i] > L) S.push_back(i);
		}
		for (int i = 0; i < M; ++ i) {
			int u = edge[i].u, v = edge[i].v, w = edge[i].w;
			if (deg[u] > L) {
				E[v].push_back(PII(u, w));
				sum[u][w > 0] += w;
			}
			else if (deg[v] > L) {
				E[u].push_back(PII(v, w));
				sum[v][w > 0] += w;
			}
			else {
				E[v].push_back(PII(u, w));
				E[u].push_back(PII(v, w));
				sum[0][w > 0] += w;
			}
		}
		if (cas ++) puts("");
		while (Q --) {
			char st[10]; scanf("%s", st);
			if (st[0] == 'Q') {
				scanf("%s", st);
				LL ret = 0;
				if (st[0] == 'A') ret = getsum(0) + getsum(1);
				else if (st[0] == '-') ret = getsum(0);
				else if (st[0] == '+') ret = getsum(1);
				printf("%lld\n", ret);
			}
			else {
				int x; scanf("%d", &x);
				Modify(x);
			}
		}
	}
	return 0;
}
