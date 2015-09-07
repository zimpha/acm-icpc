#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN = 10000;
const int SIZE = 200;;

char file[MAXN][SIZE];

void check(char src[], char s1[], char s2[]) {
	int n = strlen(src), m = strlen(s1), l, r;
	for (l = 0; l < n; ++ l) {
		if (s1[l] == '*') break;
		if (src[l] != s1[l]) return;
	}
	for (r = n - 1; r >=0; -- r) {
		if (s1[m - (n - r)] == '*') break;
		if (src[r] != s1[m - (n - r)]) return;
	}
	if (l > r + 1) return;
	printf("mv %s ", src);
	for (int i = 0; s2[i]; ++ i) {
		if (s2[i] == '*') {
			for (int j = l; j <= r; ++ j) putchar(src[j]);
		}
		else putchar(s2[i]);
	}
	puts("");
}

int main() {
	int n = 0;
	while (scanf("%s", file[n]) == 1) {
		while (strcmp(file[n], "end") != 0) {
			n ++; scanf("%s", file[n]);
		}
		char st[SIZE];
		while (scanf("%s", st) == 1 && strcmp(st, "end") !=0) {
			char s1[SIZE], s2[SIZE];
			scanf("%s%s", s1, s2);
			printf("rename %s %s\n", s1, s2);
			for (int i = 0; i < n; ++ i) {
				check(file[i], s1, s2);
			}
		}
		n = 0;
		puts("");
	}
}
