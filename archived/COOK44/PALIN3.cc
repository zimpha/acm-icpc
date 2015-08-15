#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;

const int MAXN = 2000000 + 10;

char S[MAXN];
int D[MAXN], R[MAXN], N;
int sum[MAXN][3];

void manacher(const char *s, int u[], int n) {
	for (int i = 0; i < 2 * n; ++ i) u[i] = 0;
	for (int i = 0, j = 0, k; i < 2 * n; i += k, j = max(j - k, 0)) {
		while (i >= j && i + j + 1 < 2 * N && s[(i - j) >> 1] == s[(i + j + 1) >> 1]) ++ j;
		u[i] = j;
		for (k = 1; i >= k && u[i] >= k && u[i - k] != u[i] - k; ++ k) {
			u[i + k] = min(u[i - k], u[i] - k);
		}
	}
}

int main() {
	scanf("%s", S); N = strlen(S);
	manacher(S, D, N);
	for (int i = 0; i < 2 * N; ++ i) {
		printf("%d ", D[i]);
	}
	puts("");
	for (int i = 0; i < N; ++ i) {
		R[i + 1] = (R[i] + S[i] - '0') % 3;
		memcpy(sum[i + 1], sum[i], sizeof(sum[i]));
		if (S[i] != '0') sum[i + 1][R[i + 1]] ++;
	}
	LL ret = 0;
	for (int i = 0; i < 2 * N; ++ i) {
		int l = (i + 1) >> 1;
		int r = l + ((D[i] + 1) >> 1);
		int mod = (i % 2) ? 0 : (S[i >> 1] - '0') % 3;
		if (mod) mod = 3 - mod;
		mod = (mod + R[l]) % 3;
		ret += (LL)sum[r][mod] - sum[l][mod];
	}
	for (int i = 0; i < N; ++ i) ret += (S[i] == '0');
	printf("%lld\n", ret);
	return 0;
}
