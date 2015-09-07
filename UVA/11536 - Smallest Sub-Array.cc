#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXK = 200;
const int MAXN = 1000010;
const int inf = 1000000000;

int cnt[MAXK], X[MAXN];

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		int N, M, K; scanf("%d%d%d", &N, &M, &K);
		X[1] = 1; X[2] = 2; X[3] = 3;
		for (int i = 4; i <= N; ++ i) {
			X[i] = (X[i - 1] + X[i - 2] + X[i - 3]) % M + 1;
		}
		memset(cnt, 0, sizeof(cnt));
		int ret = inf, num = 0;
		for (int i = 1, j = 1; i <= N; ++ i) {
			while (num < K && j <= N) {
				if (X[j] <= K) {
					cnt[X[j]] ++;
					if (cnt[X[j]] == 1) num ++;
				}
				j ++;
			}
			if (num == K) {
				ret = min(ret, j - i);
			}
			if (X[i] <= K) {
				cnt[X[i]] --;
				if (cnt[X[i]] == 0) num --;
			}
		}
		printf("Case %d: ", cas);
		if (ret == inf) puts("sequence nai");
		else printf("%d\n", ret);
	}
	return 0;
}
