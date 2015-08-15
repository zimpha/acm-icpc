#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
const int MOD = 1e9 + 7;

double dp[MAXN], LA[MAXN];
int A[MAXN], P[MAXN], Q[MAXN];
int N, K;

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; ++ i) {
		scanf("%d", &A[i]);
		LA[i] = log((double)A[i]);
	}
	int head = 1, tail = 1;
	dp[1] = LA[1]; Q[1] = 1;
	for (int i = 2; i <= N; ++ i) {
		while (head <= tail && i - Q[head] > K) head ++;
		P[i] = Q[head]; dp[i] = LA[i] + dp[Q[head]];
		while (head <= tail && dp[i] <= dp[Q[tail]]) tail --;
		Q[++ tail] = i;
	}
	int ret = A[1];
	for (int i = N; i != 1; i = P[i]) {
		ret = (long long)ret * A[i] % MOD;
	}
	printf("%d\n", ret);
	return 0;
}
