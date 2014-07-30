#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

double dp[1<<13][13];

inline double sqr(double x) {return x * x;}

inline double dis(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt(sqr(x1 - x2) + sqr(y1 - y2) + sqr(z1 - z2));
}

struct Switch {
	int sx, sy, sz, k;
	int x[20], y[20], z[20];
	double mdis[20];
	void read() {
		scanf("%d%d%d%d", &k, &sx, &sy, &sz);
		for (int i = 0; i < k; ++ i) scanf("%d%d%d", x + i, y + i, z + i);
	}
	void solve() {
		for (int mask = 0; mask < (1 << k); ++ mask) for (int i = 0; i < k; ++ i) dp[mask][i] = 1e20;
		for (int i = 0; i < k; ++ i) dp[1 << i][i] = dis(sx, sy, sz, x[i], y[i], z[i]);
		for (int mask = 1; mask < (1 << k); ++ mask) {
			for (int i = 0; i < k; ++ i) if ((mask >> i) & 1) {
				for (int j = 0; j < k; ++ j) if (!((mask >> j) & 1)) {
					double d = dis(x[i], y[i], z[i], x[j], y[j], z[j]);
					if (dp[mask | (1 << j)][j] > dp[mask][i] + d) {
						dp[mask | (1 << j)][j] = dp[mask][i] + d;
					}
				}
			}
		}
		for (int i = 0; i < k; ++ i) mdis[i] = dp[(1 << k) - 1][i];
	}
} A[20];

int main() {
	int n, mx, my, mz;
	while (scanf("%d%d%d%d", &n, &mx, &my, &mz) == 4 && n) {
		for (int i = 0; i < n; ++ i) {
			A[i].read();
			A[i].solve();
		}
		for (int mask = 0; mask < (1 << n); ++ mask) for (int i = 0; i < n; ++ i) dp[mask][i] = 1e20;
		for (int i = 0; i < n; ++ i) dp[1 << i][i] = dis(mx, my, mz, A[i].sx, A[i].sy, A[i].sz);
		for (int mask = 1; mask < (1 << n); ++ mask) {
			for (int i = 0; i < n; ++ i) if ((mask >> i) & 1) {
				if (dp[mask][i] == -1) continue;
				for (int j = 0; j < n; ++ j) if (!((mask >> j) & 1)) {
					double d = 1e20;
					for (int k = 0; k < A[i].k; ++ k) {
						d = min(d, dis(A[j].sx, A[j].sy, A[j].sz, A[i].x[k], A[i].y[k], A[i].z[k]) + A[i].mdis[k]);
					}
					//double d = dis(A[j].sx, A[j].sy, A[j].sz, A[i].tx, A[i].ty, A[i].tz);
					if (dp[mask | (1 << j)][j] > dp[mask][i] + d) {
						dp[mask | (1 << j)][j] = dp[mask][i] + d;
					}
				}
			}
		}
		double ret = 1e20;
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < A[i].k; ++ j) 
				ret = min(ret, dp[(1 << n) - 1][i] + A[i].mdis[j]);
		}
		printf("%.10f\n", ret);
	}
	return 0;
}
