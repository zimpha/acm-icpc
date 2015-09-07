#include <cstdio>
#include <cstring>

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) == 2 && n) {
		if (n >= 49) puts("Let me try!");
		else {
			int f[50][50], flag = 0; memset(f, 0, sizeof(f));
			f[1][1] = 1;
			for (int i = 1; i <= n; ++ i) {
				for (int j = 1; j <= n; ++ j) {
					if (f[i][j]) {
						if (j + 2 * i + 1 <= n) f[i + 1][j + 2 * i + 1] |= f[i][j];
						if (j - 2 * i - 1 >= 1) f[i + 1][j - 2 * i - 1] |= f[i][j];
					}
				}
				if (f[i][m]) {flag = 1; break;}
			}
			if (flag) puts("Let me try!");
			else puts("Don't make fun of me!");
		}
	}
	return 0;
}
