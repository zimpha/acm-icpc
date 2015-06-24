#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 300 + 10;
int h[MAXN][MAXN], U[MAXN][MAXN], D[MAXN][MAXN];
int L[MAXN][MAXN], R[MAXN][MAXN];
int n, m, t, tt[3];
int ret, x1, x2, Y1, y2;

inline int cmp(int a, int b) {
	if (a > b) return 1;
	else if (a == b) return 0;
	else return 2;
}

void solve(int low, int upp) {
	static int LL[MAXN], RR[MAXN], DD[MAXN], UU[MAXN];
	for (int i = 1; i <= m; ++ i) {
		LL[i] = L[upp][i], RR[i] = R[low][i];
		DD[i] = D[upp][i] - D[low][i];
		UU[i] = U[low][i] - U[upp][i];
	}
	map<int, int> mp; mp.clear();
	map<int, int>::iterator it;
	for (int i = 2; i <= m; ++ i) {
		int now = t - (DD[i] + RR[i] - LL[i]);
		it = mp.lower_bound(now);
		if (it != mp.end()) {
			if (abs(it->first - now) < ret) {
				ret = abs(it->first - now);
				x1 = low, Y1 = it->second;
				x2 = upp, y2 = i;
			}
		}
		if (it != mp.begin()) {
			-- it;
			if (abs(it->first - now) < ret) {
				ret = abs(it->first - now);
				x1 = low, Y1 = it->second;
				x2 = upp, y2 = i;
			}
		}
		if (i >= 2) mp[UU[i - 1] + LL[i - 1] - RR[i - 1]] = i - 1;
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &t);
	scanf("%d%d%d", &tt[0], &tt[1], &tt[2]);
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			scanf("%d", &h[i][j]);
		}
	}

	for (int j = 1; j <= m; ++ j) U[n][j] = 0;
	for (int i = n - 1; i >= 1; -- i) {
		for (int j = 1; j <= m; ++ j) {
			U[i][j] = tt[cmp(h[i][j], h[i + 1][j])] + U[i + 1][j];
		}
	}
	for (int j = 1; j <= m; ++ j) D[1][j] = 0;
	for (int i = 2; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			D[i][j] = D[i - 1][j] + tt[cmp(h[i][j], h[i - 1][j])];
		}
	}
	for (int i = 1; i <= n; ++ i) R[i][1] = 0;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 2; j <= m; ++ j) {
			R[i][j] = R[i][j - 1] + tt[cmp(h[i][j], h[i][j - 1])];
		}
	}
	for (int i = 1; i <= n; ++ i) L[i][m] = 0;
	for (int i = 1; i <= n; ++ i) {
		for (int j = m - 1; j >= 1; -- j) {
			L[i][j] = L[i][j + 1] + tt[cmp(h[i][j], h[i][j + 1])];
		}
	}

	ret = 2e9;
	for (int i = 1; i <= n; ++ i) {
		for (int j = i + 2; j <= n; ++ j) {
			solve(i, j);
		}
	}
	printf("%d %d %d %d\n", x1, Y1, x2, y2);
	return 0;
}
