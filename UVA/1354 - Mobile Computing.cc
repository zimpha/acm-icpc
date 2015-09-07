#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 10;
const int SIZE = 100;

struct Node {
	double l, r;
};

vector<Node> S[SIZE];
double w[MAXN], weight[SIZE], len;
int vis[SIZE], n, m;

void solve(int state) {
	if (vis[state]) return;
	vis[state] = true;
	for (int m1 = (state & (state - 1)); m1 > 0; m1 = (m1 - 1) & state) {
		int m2 = state ^ m1;
		solve(m1); solve(m2);
		for (int i = 0; i < (int)S[m1].size(); ++ i) {
			for (int j = 0; j < (int)S[m2].size(); ++ j) {
				double l = weight[m2] / (weight[m1] + weight[m2]);
				double r = weight[m1] / (weight[m1] + weight[m2]);
				Node tmp;
				tmp.l = max(S[m1][i].l + l, S[m2][j].l - r);
				tmp.r = max(S[m1][i].r - l, S[m2][j].r + r);
				if (tmp.l + tmp.r <= len) S[state].push_back(tmp);
			}
		}
	}
	if (__builtin_popcount(state) == 1) S[state].push_back((Node){0, 0});
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%lf%d", &len, &n); m = (1 << n) - 1;
		for (int i = 0; i < n; ++ i) scanf("%lf", &w[i]);
		for (int mask = 0; mask < (1 << n); ++ mask) {
			weight[mask] = 0; vis[mask] = 0; S[mask].clear();
			for (int i = 0; i < n; ++ i) 
				if (mask & (1 << i)) weight[mask] += w[i];
		}
		solve(m);
		double ret = -1;
		for (int i = 0; i < (int)S[m].size(); ++ i)
			ret = max(ret, S[m][i].l + S[m][i].r);
		printf("%.20f\n", ret);
	}
	return 0;
}
