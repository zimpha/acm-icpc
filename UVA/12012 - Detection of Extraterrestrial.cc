#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 10;

int next[MAXN], ret[MAXN];
char st[MAXN], tst[MAXN];

void get_next(char st[], int n) {
	next[0] = -1;
	for (int i = 1, j; i < n; ++ i) {
		j = next[i - 1];
		while (j >= 0 && st[j + 1] != st[i]) j = next[j];
		next[i] = (st[j + 1] == st[i]) ? ++ j : j;
	}
}

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		scanf("%s", st);
		int n = strlen(st);
		memset(ret, 0, sizeof(ret));
		for (int i = 0; i < n; ++ i) {
			int m = n - i;
			for (int j = 0; j < m; ++ j) tst[j] = st[i + j];
			get_next(tst, m);
			for (int j = 0; j < m; ++ j) {
				if (next[j] >= 0 && (j + 1) % (j - next[j]) == 0) {
					int len = (j + 1) / (j - next[j]);
					for (int k = 1; k <= len; ++ k) {
						if (len % k == 0) ret[k] = max(ret[k], j + 1);
						else ret[k] = max(ret[k], (j - next[j]) * k);
					}
				}
			}
		}
		ret[1] = n;
		printf("Case #%d:", cas);
		for (int i = 1; i <= n; ++ i) printf(" %d", ret[i]);
		puts("");
	}
	return 0;
}
