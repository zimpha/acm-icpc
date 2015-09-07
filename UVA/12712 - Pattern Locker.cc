#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;

const LL MOD = 10000000000007LL;

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		int L, M, N; scanf("%d%d%d", &L, &M, &N);
		L = L * L;
		long long ret = 0, tmp = 1;
		for (int i = L, j = 1; i > 0; -- i, ++ j) {
			tmp = tmp * i % MOD;
			if (j >= M && j <= N) ret = (ret + tmp) % MOD;
		}
		printf("Case %d: %lld\n", cas, ret);
	}
	return 0;
}
