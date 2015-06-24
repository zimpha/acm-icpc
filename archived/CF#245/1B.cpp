#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 10;

int a[MAXN][MAXN];
int dp[4][MAXN][MAXN];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j)
			cin >> a[i][j];
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j) {
			dp[0][i][j] = max(dp[0][i][j - 1], dp[0][i - 1][j]) + a[i][j];
		}
	for (int i = 1; i <= n; ++ i)
		for (int j = m; j >= 1; -- j) {
			dp[1][i][j] = max(dp[1][i - 1][j], dp[1][i][j + 1]) + a[i][j];
		}
	for (int i = n; i >= 1; -- i) 
		for (int j = 1; j <= m; ++ j) {
			dp[2][i][j] = max(dp[2][i + 1][j], dp[2][i][j - 1]) + a[i][j];
		}
	for (int i = n; i >= 1; -- i)
		for (int j = m; j >= 1; -- j) {
			dp[3][i][j] = max(dp[3][i + 1][j], dp[3][i][j + 1]) + a[i][j];
		}
	int ret = 0;
	for (int i = 2; i < n; ++ i)
		for (int j = 2; j < m; ++ j) {
			ret = max(ret, dp[0][i - 1][j] + dp[1][i][j + 1] + dp[2][i][j - 1] + dp[3][i + 1][j]);
			ret = max(ret, dp[0][i][j - 1] + dp[1][i - 1][j] + dp[2][i + 1][j] + dp[3][i][j + 1]);
		}
	cout << ret << endl;
}
