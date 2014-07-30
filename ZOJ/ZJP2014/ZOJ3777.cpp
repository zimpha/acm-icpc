#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;

int N, M;
int dp[1<<13][600];
int p[20][20];

int gcd (int a,int b){
	if (b == 0) return a;
	else return gcd(b, a % b);	
}

int main(){
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; ++ i) {
			for (int j = 0; j < N; ++ j) {
				scanf("%d", &p[i][j]);
			}
		}
		for (int i = 0; i < (1 << N); ++ i)
			for (int j = 0; j <= M; ++ j) dp[i][j] = 0;
		int S = 1 << N;
		vector<int> st[20];
		for (int i = 0; i < N; ++ i) st[i].clear();
		for (int mask = 0; mask < S; ++ mask) {
			int t = __builtin_popcount(mask);
			st[t].push_back(mask);
		}
		
		dp[0][0] = 1;
		for (int i = 0; i < N; ++ i) {
			for (int t = 0; t < (int)st[i].size(); ++ t) {
				int mask = st[i][t];
				for (int w = 0; w <= M; ++ w) {
					for (int j = 0; j < N; ++ j) {
						if (dp[mask][w] == 0) continue;
						if (((mask >> j) & 1) == 0) {
							dp[mask|(1 << j)][min(w + p[i][j], M)] += dp[mask][w];
						}
					}
				}
			}
		}
		int sum = dp[S - 1][M], frac = 1;
		for (int i = 1; i <= N; ++ i) frac *= i;
		if (sum == 0) {puts("No solution"); continue;}
		int k = gcd(sum, frac);
		sum /= k; frac /= k;
		printf("%d/%d\n", frac, sum);	
	}
	return 0;	
}
