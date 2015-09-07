#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool check(char s[]) {
	int cnt[26]; memset(cnt, 0, sizeof(cnt));
	for (int i = 0; s[i]; ++ i) cnt[s[i] - 'a'] ++;
	int ret = 0;
	for (int i = 0; i < 26; ++ i) ret += (cnt[i] & 1);
	return ret < 2;
}

int solve(char s[], int l, int r) {
	if (l >= r) return 0;
	int p1 = r, p2 = l;
	for (int i = l; i <= r; ++ i)
		for (int j = r; j > i; -- j) {
			if (s[i] != s[j]) continue;
			if (i - l + r - j < p1 - l + r - p2) p1 = i, p2 = j;
		}
	for (int i = p1; i > l; -- i) swap(s[i], s[i - 1]);
	for (int i = p2; i < r; ++ i) swap(s[i], s[i + 1]);
	return p1 - l + r - p2 + solve(s, l + 1, r - 1);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		char st[1000];
		scanf("%s", st);
		if (check(st)) printf("%d\n", solve(st, 0, strlen(st) - 1));
			else puts("Impossible");
	}
	return 0;
}
