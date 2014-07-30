#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;

typedef vector <LL> VI;

vector <VI> Price, Discount, dp;

int main() {
	int T, N, M; scanf("%d", &T);
	while (T --) {
		Price.clear(); Discount.clear(); dp.clear();
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; ++ i) {
			VI tmp; tmp.clear();
			for (int j = 0, x; j < M; ++ j) {
				scanf("%d", &x); tmp.push_back(x);
			}
			Price.push_back(tmp);
		}
		for (int i = 0; i < N; ++ i) {
			VI tmp; tmp.clear();
			for (int j = 0, x; j < M; ++ j) {
				scanf("%d", &x); tmp.push_back(x);
			}
			Discount.push_back(tmp);
		}
		LL mx;
		for (int i = 0; i < N; ++ i) {
			VI tmp; tmp.clear();
			if (i) {
				for (int j = 0; j < M; ++ j) {
					tmp.push_back(min(mx + Price[i][j], dp[i - 1][j] + max(0ll, Price[i][j] - Discount[i - 1][j])));
				}
			}
			else {
				for (int j = 0; j < M; ++ j) {
					tmp.push_back(Price[i][j]);
				}
			}
			mx = 1e18;
			for (int j = 0; j < M; ++ j) mx = min(mx, tmp[j]);
			dp.push_back(tmp);
		}
		mx = 1e18;
		for (int i = 0; i < M; ++ i) mx = min(mx, dp[N - 1][i]);
		printf("%lld\n", mx);
	}
	return 0;
}
