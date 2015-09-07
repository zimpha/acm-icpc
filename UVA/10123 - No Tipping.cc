#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 30;

struct Item {
	int p, w;
	double lm, rm;
};

vector<Item> L, R;
int ret[MAXN][2];
int len, w, n, m;

bool cmpL(const Item &a, const Item &b) {
	return a.lm < b.lm;
}

bool cmpR(const Item &a, const Item &b) {
	return a.rm < b.rm;
}

bool dfs(double ll, double lr, double rl, double rr, int num, int nl, int nr) {
	if (ll > rl || rr > lr) return false;
	if (num == n) return true;
	if (nl < (int)L.size()) {
		ret[num][0] = L[nl].p; ret[num][1] = L[nl].w;
		if (dfs(ll + L[nl].lm, lr + L[nl].rm, rl, rr, num + 1, nl + 1, nr)) return true;
	}
	if (nr < (int)R.size()) {
		ret[num][0] = R[nr].p; ret[num][1] = R[nr].w;
		if (dfs(ll, lr, rl + R[nr].lm, rr + R[nr].rm, num + 1, nl, nr + 1)) return true;
	}
	return false;
}

int main() {
	int cas = 0;
	while (scanf("%d%d%d", &len, &w, &n) == 3 && len) {
		double ll, lr, rl, rr;
		ll = rr = 1.0 * (len - 3) * (len - 3) * w / (8.0 * len);
		rl = lr = 1.0 * (len + 3) * (len + 3) * w / (8.0 * len);
		L.clear(); R.clear(); m = 0;
		for (int i = 0; i < n; ++ i) {
			int p, w; scanf("%d%d", &p, &w);
			if (abs(p * 2) <= 3) {
				ret[m][0] = p; ret[m ++][1] = w;
				lr += 1.0 * w * (1.5 - p);
				rl += 1.0 * w * (p + 1.5);
			} else {
				if (p < 0) L.push_back((Item){p, w, 1.0 * w * (-1.5 - p), 1.0 * w * (1.5 - p)});
				else R.push_back((Item){p, w, 1.0 * w * (p + 1.5), 1.0 * w * (p - 1.5)});
			}
		}
		sort(L.begin(), L.end(), cmpL);
		sort(R.begin(), R.end(), cmpR);
		printf("Case %d:\n", ++ cas);
		if (dfs(ll, lr, rl, rr, m, 0, 0)) {
			for (int i = n - 1; i >= 0; -- i) {
				printf("%d %d\n", ret[i][0], ret[i][1]);
			}
		} else puts("Impossible");
	}
	return 0;
}
