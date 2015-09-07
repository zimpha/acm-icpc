#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN = 100010;

char s[MAXN], t[MAXN];
int fail[MAXN];

void get_fail(char s[], int n) {
	fail[0] = -1;
	for (int i = 1, j = -1; i < n; ++ i) {
		while (j >= 0 && s[j + 1] != s[i]) j = fail[j];
		fail[i] = (s[j + 1] == s[i]) ? ++ j : j;
	}
}

int main() {
	while (scanf("%s", s) == 1) {
		int n = strlen(s), ret;
		for (int i = 0; i < n; ++ i) t[i] = s[n - i -1];
		get_fail(t, n);
		for (int i = 0, j = -1; i < n; ++ i) {
			while (j >= 0 && t[j + 1] != s[i]) j = fail[j];
			if (t[j + 1] == s[i]) j ++;
			ret = j;
		}
		for (int i = 0; i < n; ++ i) putchar(s[i]);
		for (int i = ret + 1; i < n; ++ i) putchar(t[i]);
		puts("");
	}
	return 0;
}
