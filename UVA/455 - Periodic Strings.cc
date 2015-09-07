#include <cstdio>
#include <cstring>
#include <cstdlib>

const int SIZE = 1000010;

char s[SIZE];
int next[SIZE];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int n = strlen(s);
		next[0] = -1;
		for (int i = 1, j; i < n; ++ i) {
			j = next[i - 1];
			while (j >= 0 && s[j + 1] != s[i]) j = next[j];
			if (s[j + 1] == s[i]) j ++;
			next[i] = j;
		}
		if (n % (n - 1 - next[n - 1]) == 0) {
			printf("%d\n", n - 1 - next[n - 1]);
		}
		else printf("%d\n", n);
		if (T) puts("");
	}
	return 0;
}
