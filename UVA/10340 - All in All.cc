#include <cstdio>
#include <cstring>
char s1[100000], s2[100000];

bool check(char s1[], char s2[]) {
	int n = strlen(s1), m = strlen(s2);
	if (n > m) return false;
	for (int i = 0, j = 0; i < n && j < m; ) {
		if (s1[i] == s2[j]) i ++, j ++;
		else j ++;
		if (i == n) return true;
		if (j == m) return false;
	}
	return true;
}

int main() {
	while (scanf("%s%s", s1, s2) == 2) {
		puts(check(s1, s2) ? "Yes" : "No");
	}
	return 0;
}
