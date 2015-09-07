#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
	int w, d, h1[30], h2[30], cnt[30];
	while (scanf("%d%d", &w, &d) == 2 && w) {
		memset(cnt, 0, sizeof(cnt));
		int ret = 0;
		for (int i = 0; i < w; ++ i) {
			scanf("%d", &h1[i]);
			cnt[h1[i]] ++; ret += h1[i];
		}
		for (int i = 0; i < d; ++ i) {
			scanf("%d", &h2[i]);
			if (cnt[h2[i]]) cnt[h2[i]] --;
			else ret += h2[i];
		}
		printf("%d\n", ret);
	}
	return 0;
}
