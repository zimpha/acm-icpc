#include <cstdio>
#include <cstring>

const int SIZE = 200;

int main() {
	int n;
	int cnt[SIZE];
	while (scanf("%d", &n) == 1 &&n) {
		memset(cnt, 0, sizeof(cnt));
		while (n --) {
			int x; scanf("%d", &x);
			cnt[x] ++;
		}
		bool first = true;
		for (int i = 1; i <= 100; ++ i) {
			while (cnt[i] --) {
				if (!first) putchar(' ');
				else first = false;
				printf("%d", i);
			}
		}
		puts("");
	}
	return 0;
}
