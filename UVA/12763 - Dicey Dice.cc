#include <cstdio>
#include <cstring>

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int a[3][6];
		char st[10];
		scanf("%s", st);
		for (int i = 0; i < 3; ++ i) {
			for (int j = 0; j < 6; ++ j) {
				scanf("%d", &a[i][j]);
			}
		}
		int c1 = 0, c2 = 0, c3 = 0;
		for (int i = 0; i < 3; ++ i) {
			int w1a = 0, w2a = 0;
			int w1b = 0, w2b = 0;
			for (int j = 0, c = 0; j < 3; ++ j) {
				if (i == j) continue;
				w1a = w1b = 0;
				for (int x = 0; x < 6; ++ x) {
					for (int y = 0; y < 6; ++ y) {
						if (a[i][x] > a[j][y]) w1a ++;
						else if (a[i][x] < a[j][y]) w1b ++;
					}
				}
				if (!c) w2a = w1a, w2b = w1b, c = 1;
			}
			if (w1a > w1b && w2a > w2b) c1 ++;
			else if (w1a < w1b || w2a < w2b) c3 ++;
			else c2 ++;
		}
		if (c1) puts(st);
		else {
			if (c2) puts("fair");
			else printf("%c\n", !(st[0] - 'A') + 'A');
		}
	}
	return 0;
}
