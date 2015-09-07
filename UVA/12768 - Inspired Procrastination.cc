#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 100, inf = 1e9;

vector<pair<int, int> > G[MAXN];
int dis[MAXN], vis[MAXN], times[MAXN];
int N, M;

bool spfa() {
	queue<int> Q;
	for (int i = 1; i <= N; ++ i) dis[i] = -inf, vis[i] = false, times[i] = 0;
	Q.push(1); vis[1] = true; dis[1] = 0;
	while (!Q.empty()) {
		int u = Q.front(); Q.pop(); vis[u] = false;
		times[u] ++;
		if (times[u] > N) return false;
		for (int i = 0; i < (int)G[u].size(); ++ i) {
			int v = G[u][i].first, w = G[u][i].second;
			if (dis[v] < dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!vis[v]) vis[v] = true, Q.push(v);
			}
		}
	}
	return true;
}

int main() {
	while (scanf("%d%d", &N, &M) == 2 && N) {
		for (int i = 1; i <= N; ++ i) G[i].clear();
		while (M --) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			G[a].push_back(make_pair(b, c));
		}
		if (spfa()) {
			int ret = 0;
			for (int i = 1; i <= N; ++ i) ret = max(ret, dis[i]);
			printf("%d\n", ret);
		}
		else puts("Unlimited!");
	}
	return 0;
}
