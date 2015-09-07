#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAXN = 1000010;

char s[MAXN];
int fail[MAXN];
int N;

int main() {
	int cas = 0;
	while (scanf("%d", &N) == 1 && N) {
		scanf("%s", s);
		fail[0] = -1;
		for (int i = 1, j = -1; i < N; ++ i) {
			j = fail[i - 1];
			while (j >= 0 && s[j + 1] != s[i]) j = fail[j];
			if (s[j + 1] == s[i]) j ++;
			fail[i] = j;
		}
		printf("Test case #%d\n", ++ cas);
		for (int i = 0; i < N; ++ i) {
			if ((i + 1) % (i - fail[i]) == 0 && fail[i] >= 0) {
				printf("%d %d\n", i + 1, (i + 1) / (i - fail[i]));
			}
		}
		puts("");
	}
	return 0;
}
