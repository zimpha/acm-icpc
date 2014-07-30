#include <cctype>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int sum[] = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
int cost[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int cnt[36];

bool cmp(int a, int b) {
	return (a > b);
}

int solve(int n) {
	for (int i = 0, s = 0; ; ++ i) {
		if (s < n && s + sum[i] >= n) return i;
		s += sum[i];
	}
	return -1;
}

int main() {
	int T; scanf("%d\n", &T);
	while (T --) {
		char buf[200];
		gets(buf);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0, x; buf[i]; ++ i) {
			if (buf[i] == ' ') continue;
			if (isdigit(buf[i])) x = buf[i] - '0';
			else x = buf[i] - 'A' + 10;
			cnt[x] ++;
		}
		sort(cnt, cnt + 36, cmp);
		int ret = 0;
		for (int i = 0; i < 36; ++ i) {
			if (cnt[i] == 0) break;
			int idx = solve(i + 1);
			ret += cnt[i] * cost[idx];
		}
		printf("%d\n", ret);
	}
	return 0;
}
