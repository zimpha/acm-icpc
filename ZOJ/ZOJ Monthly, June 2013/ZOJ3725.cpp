#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 100000 + 10;

int f[MAXN], N, M;
int t[10][10];

int get(int x) {
	if (x < -1) return 0;
	else if (x == -1) return 1;
	else return f[x];
}

int main() {
	while (scanf("%d%d", &N, &M) == 2) {
		f[0] = 1;
		int ret = 1;
		for (int i = 1; i <= N; ++ i) {
			f[i] = 2 * f[i - 1] % MOD;
			if (i >= M) f[i] = (f[i] - get(i - M - 1)) % MOD;
			if (f[i] < 0) f[i] += MOD;
			ret = (ret * 2) % MOD;
		}
		ret -= f[N];
		if (ret < 0) ret += MOD;
		printf("%d\n", ret);
	}
	return 0;
}
