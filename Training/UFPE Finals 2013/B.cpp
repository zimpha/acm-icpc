#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 1e9;
typedef pair<int, int> PII;

vector<PII> rules[26];
int dp[150][150];
char S[150];
int N, M;

int calc(int o, int p) {
	int ret = 0;
	for (int i = 0; i < (int)rules[o].size(); ++ i) {
		if (p % rules[o][i].first) continue;
		ret += (p / rules[o][i].first) * rules[o][i].second;
	}
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		scanf("%s%d", S + 1, &M);
		N = strlen(S + 1);
		for (int i = 0, k, a, b; i < 26; ++ i) {
			rules[i].clear();
			scanf("%d", &k);
			while (k --) {
				scanf("%d%d", &a, &b);
				rules[i].push_back(make_pair(a, b));
			}
		}
		for (int i = 0; i <= N; ++ i)
			for (int j = 0; j <= N; ++ j)
				dp[i][j] = inf;
		dp[0][0] = 0;
		for (int i = 1; i <= N; ++ i) {
			dp[i][0] = 0;
			for (int j = 1; j <= i && j <= M; ++ j) {
				dp[i][j] = inf;
				int cost  =calc(S[i] - 'a', j);
				for (int k = 0; k < i; ++ k) {
					if (dp[k][j - 1] < dp[i][j]) dp[i][j] = dp[k][j - 1];
				}
				dp[i][j] += cost;
			}
		}
		int ret = inf;
		for (int i = M; i <= N; ++ i) ret = min(ret, dp[i][M]);
		printf("Case #%d: %d\n", cas, ret);
	}
	return 0;
}
