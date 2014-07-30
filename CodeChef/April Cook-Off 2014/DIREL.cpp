#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 300;

map<string, int> IDCache;
vector<int> ds[MAXN];
bool bs[MAXN][MAXN];
int dis[MAXN][MAXN];

int main() {
	int N, R, M;
	cin >> N >> R;
	memset(dis, 0, sizeof(dis));
	memset(bs, 0, sizeof(bs));
	for (int i = 0; i < N; ++ i) ds[i].clear();
	IDCache.clear(); M = 0;
	while (R --) {
		string A, is, F, of , B;
		cin >> A >> is >> F >> of >> B;
		if (!IDCache.count(A)) IDCache[A] = M ++;
		if (!IDCache.count(B)) IDCache[B] = M ++;
		int u = IDCache[A], v = IDCache[B];
		if (F == "father" || F == "mother") ds[u].push_back(v), dis[u][v] = dis[v][u] = 1;
		if (F == "brother" || F == "sister") dis[u][v] = dis[v][u] = bs[u][v] = bs[v][u] = 1;
		if (F == "son" || F == "daughter") ds[v].push_back(u), dis[u][v] = dis[v][u] = 1;
	}
	while (true) {
		bool flag = false;
		for (int i = 0; i < M; ++ i) {
			//brother/sister + parents -> parents
			for (int j = 0; j < (int)ds[i].size(); ++ j) {
				for (int k = 0, v = ds[i][j]; k < M; ++ k) {
					if (bs[v][k] && !dis[i][k]) {
						dis[i][k] = dis[k][i] = 1;
						ds[i].push_back(k);
						flag = true;
					}
				}
			}
			//parents + parents -> brother/sister
			for (int j = 0; j < (int)ds[i].size(); ++ j) {
				for (int k = j + 1; k < (int)ds[i].size(); ++ k) {
					int u = ds[i][j], v = ds[i][k];
					if (!dis[u][v]) {
						dis[u][v] = dis[v][u] = 1;
						bs[u][v] = bs[v][u] = 1;
						flag = true;
					}
				}
			}
			//brother/sister + brother/sister -> brother/sister
			for (int j = 0; j < M; ++ j) {
				if (!bs[i][j]) continue;
				for (int k = 0; k < M; ++ k) {
					if (bs[j][k] && !bs[i][k] && i != k) {
						bs[i][k] = bs[k][i] = 1;
						dis[i][k] = dis[k][i] = 1;
						flag = true;
					}
				}
			}
		}
		if (!flag) break;
	}
	for (int i = 0; i < M; ++ i) {
		for (int j = 0; j < M; ++ j) {
			if (!dis[i][j]) dis[i][j] = 1e9;
		}
	}
	for (int k = 0; k < M; ++ k) {
		for (int i = 0; i < M; ++ i) {
			for (int j = 0; j < M; ++ j) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	cin >> R;
	while (R --) {
		string x, y; cin >> x >> y;
		int u = IDCache[x], v = IDCache[y];
		int ret = dis[u][v];
		if (ret > M) ret = -1;
		cout << ret << endl;
	}
	return 0;
}
