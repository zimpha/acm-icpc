#include <cstdio>
#include <cstring>
#include <cstdlib>

const int SIZE = 1000010;

char s[SIZE];
int next[SIZE];

int main() {
	while (scanf("%s", s) == 1 && strcmp(s, ".") != 0) {
		int n = strlen(s);
		next[0] = -1;
		for (int i = 1, j = -1; i < n; ++ i) {
			while (j >= 0 && s[j + 1] != s[i]) j = next[j];
			if (s[j + 1] == s[i]) j ++;
			next[i] = j;
		}
		if (n % (n - 1 - next[n - 1]) == 0) {
			printf("%d\n", n / (n - 1 - next[n - 1]));
		}
		else printf("%d\n", 1);
	}
	return 0;
}
