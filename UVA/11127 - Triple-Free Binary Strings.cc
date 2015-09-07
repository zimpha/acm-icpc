#include <cstdio>
#include <cstring>

char st[40];
int n;

inline bool check(int state, int len) {
	int m = (1 << len) - 1;
	int s = state & m;
	state = (state & (~m)) >> len;
	int ss = state & m;
	state = (state & (~m)) >> len;
	if (s == ss && ss == state) return true;
	else return false;
}

int dfs(int state, int len) {
	for (int i = 0, s = state; i <= len - 3; ++ i) {
		if ((len - i) % 3 == 0 && check(s, (len - i) / 3)) return 0;
		s = (s & (~1)) >> 1;
	}
	if (len == n) return 1;
	if (st[len] == '0') return dfs(state, len + 1);
	else if (st[len] == '1') return dfs(state ^ (1 << len), len + 1);
	else return dfs(state, len + 1) + dfs(state ^ (1 << len), len + 1);
}

int main() {
	int cas = 0;
	while (scanf("%d", &n) == 1 && n) {
		scanf("%s", st);
		printf("Case %d: %d\n", ++ cas, dfs(0, 0));
	}
	return 0;
}
