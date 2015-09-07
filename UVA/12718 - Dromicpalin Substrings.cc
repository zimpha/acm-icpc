#include <cstdio>
#include <cstring>

const int MAXN = 1000 + 10;

char S[MAXN];
int cnt[26], N;

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		scanf("%s", S); N = strlen(S);
		int ret = 0;
		for (int i = 0; i < N; ++ i) {
			memset(cnt, 0, sizeof(cnt));
			int odd = 0, even = 26;
			for (int j = i; j < N; ++ j) {
				int o = S[j] - 'a';
				if (cnt[o] & 1) odd --, even ++;
				else odd ++, even --;
				cnt[o] ++;
				if (odd <= 1) ret ++;
			}
		}
		printf("Case %d: %d\n", cas, ret);
	}
	return 0;
}
