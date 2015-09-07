#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool check(char s1[], char s2[]) {
	int n = strlen(s1), C1[26], C2[26];
	memset(C1, 0, sizeof(C1));
	memset(C2, 0, sizeof(C2));
	for (int i = 0; i < n; ++ i) C1[s1[i] - 'A'] ++, C2[s2[i] - 'A'] ++;
	sort(C1, C1 + 26); sort(C2, C2 + 26);
	for (int i = 0; i < 26; ++ i) if (C1[i] != C2[i]) return false;
	return true;
}

int main() {
	char s1[1000], s2[1000];
	while (scanf("%s%s", s1, s2) == 2) {
		puts(check(s1, s2) ? "YES" : "NO");
	}
	return 0;
}
