#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 10;

char st[MAXN];
int cnt[MAXN];
int N;

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		scanf("%s", st); N = strlen(st);
		int m = 0; cnt[0] = 1;
		for (int i = 1; i < N; ++ i) {
			if (st[i] == st[i - 1]) cnt[m] ++;
			else m ++, st[m] = st[i], cnt[m] = 1;
		}
		N = m + 1;
		int ret = 1;
		for (int i = 0; i < N; ++ i) {
			if (st[i] == '0' || st[i] == '1') ret = max(ret, cnt[i]);
			else {
				if (ret >= 2 && cnt[i] != 1) continue;
				if (i == 0 || i == N - 1) continue;
				if (st[i - 1] == st[i + 1] && cnt[i] % 2 == 1) continue;
				if (st[i - 1] != st[i + 1] && cnt[i] % 2 == 0) continue;
				if (cnt[i - 1] <= cnt[i + 1]) {
					cnt[i - 1] ++;
					ret = max(cnt[i - 1], ret);
				} else {
					cnt[i + 1] ++;
					ret = max(cnt[i + 1], ret);
				}
			}
		}
		printf("Case %d: %d\n", cas, ret);
	}
	return 0;
}
