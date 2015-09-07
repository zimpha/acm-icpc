#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 200010;

char s[MAXN];
int d[MAXN * 2];

void manacher(const char *s, int u[], int n) {
	for (int i = 0; i < 2 * n; ++ i) u[i] = 1;
	for (int i = 1, x = 0; i < n *2 -1; ++ i) {
		u[i] = max(x + u[x] - i, 1 - i % 2);
		if (x + x >= i) u[i] = min(u[i], u[x + x - i]);
		int a = (i - 1 - u[i]) >> 1, b = (i + 1 + u[i]) >> 1;
		while (a >= 0 && b < n && s[a] == s[b]) {
			a--, b++, u[i] += 2;
		}
		if (i + u[i] > x + u[x]) x = i;
	}
}

bool check(int u[], int n) {
	for (int i = 0; i < n - 1; ++ i) {
		if (d[i] + d[n + i] == n) return true;
	}
	return false;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%s", s);
		int n = strlen(s);
		manacher(s, d, n);
		int maxlen = 0;
		for (int i = 0; i < n + n -1; ++ i) {
			maxlen = max(maxlen, d[i]);
		}
		if (check(d, n)) puts("alindrome");
		else if (maxlen == n) puts("palindrome");
		else puts("simple");
	}
	return 0;
}

