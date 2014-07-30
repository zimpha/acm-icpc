#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 105;

char dp[MAXN][MAXN][2][MAXN];
char pr[MAXN][MAXN][2][MAXN];
int A[MAXN], B[MAXN];
int N;

int ID(char c) {
	char s[] = "ACGT";
	for (int i = 0; i < 4; ++ i)
		if (c == s[i]) return i;
	return -1;
}

int solve(int n, int i1, int i2, int i3) {
	if (i1 < 0 || i2 < 0 || i3 < 0) return N + 1;
	if (dp[n][i1][i2][i3] != -1) return dp[n][i1][i2][i3];
	if (n > N) return 0;
	char &ret = (dp[n][i1][i2][i3] = N + 1);
	for (int d1 = -1; d1 < 2; ++ d1) {
		for (int d2 = 0; d2 < 2; ++ d2) {
			for (int d3 = -1; d3 < 2; ++ d3) {
				if (((A[n] + i1 + d1 - (i3 + d3) + 2 * (i2 ^ d2)) % 4 + 4) % 4 == B[n]) {
					char w = (d1 == 1) + (d2 == 1 && i2 == 0) + (d3 == 1);
					char tmp = solve(n + 1, i1 + d1, i2 ^ d2, i3 + d3) + w;
					if (tmp < ret) {
						ret = tmp;
						pr[n][i1][i2][i3] = (d1 == -1) + (d1 == 1) * 2 + + (d2 == 1) * 4 + (d3 == -1) * 8 + (d3 == 1) * 16;
					}
				}
			}
		}	
	}
	return ret;
}

int main() {
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
	char s1[MAXN], s2[MAXN];
	scanf("%s%s", s1 + 1, s2 + 1);
	N = strlen(s1 + 1);
	for (int i = 1; i <= N; ++ i) {
		A[i] = ID(s1[i]);
		B[i] = ID(s2[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", solve(1, 0, 0, 0));
	int stk[3][MAXN], top[3];
	memset(stk, 0, sizeof(stk));
	memset(top, 0, sizeof(top));
	int i1 = 0, i2 = 0, i3 = 0;
	for (int n = 1; n <= N; ++ n) {
		int s = pr[n][i1][i2][i3];
		if (s & 1) printf("%d %d %d\n", stk[0][top[0] --], n - 1, 1), i1 --;
		if (s & 2) stk[0][++ top[0]] = n, i1 ++;
		if (s & 4) {
			if (i2) printf("%d %d %d\n", stk[1][top[1] --], n - 1, 2), i2 ^= 1;
			else stk[1][++ top[1]] = n, i2 ^= 1;
		}
		if (s & 8) printf("%d %d %d\n", stk[2][top[2] --], n - 1, 3), i3 --;
		if (s & 16) stk[2][++ top[2]] = n, i3 ++;
	}
	while (top[0]) printf("%d %d %d\n", stk[0][top[0] --], N, 1);
	while (top[1]) printf("%d %d %d\n", stk[1][top[1] --], N, 2);
	while (top[2]) printf("%d %d %d\n", stk[2][top[2] --], N, 3);
	fclose(stdin); fclose(stdout);
	return 0;
}
