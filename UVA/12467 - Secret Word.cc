#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN = 1000010;

char s[MAXN], t[MAXN];
int fail[MAXN];

void get_fail(const char *s, int n) {
	fail[0] = -1;
	for (int i = 1, j = -1; i < n; ++ i) {
		while (j >= 0 && s[j + 1] != s[i]) j = fail[j];
		fail[i] = (s[j + 1] == s[i]) ? ++ j : j;
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%s", t);
		int n = strlen(t);
		for (int i = 0; i < n; ++ i) s[i] = t[n - i -1];
		get_fail(t, n);
		int ret = -1, pos;
		for (int i = 0, j = -1; i < n; ++ i) {
			while (j >= 0 && t[j + 1] != s[i]) j = fail[j];
			if (t[j + 1] == s[i]) j++;
			if (j > ret) {
				ret = j; 
				pos = i;
			}
		}
		for (int i = 0; i <= ret; ++ i) putchar(s[pos - i]);
		puts("");
	}
	return 0;
}
