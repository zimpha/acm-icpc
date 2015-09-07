#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAXN = 10;

int c[3], ans[MAXN * MAXN];
int A[MAXN], ss;
int N, M, ret;

inline bool check(int n) {
	for (int i = 1; i < n; ++ i)
		if (A[i] & ss) return false;
	return true;
}

inline void change(int x, int y) {
	if (y == M) A[x - 1] ^= c[0] >> 1, A[x] ^= c[1] >> 1, A[x + 1] ^= c[2] >> 1;
	else A[x - 1] ^= c[0] << (M - y - 1), A[x] ^= c[1] << (M - y - 1), A[x + 1] ^= c[2] << (M - y - 1);
}

bool dfs(int dep, int x, int y) {
	if (check(N + 1)) {
		for (int i = 0; i < dep; ++ i) {
			if (i) putchar(' ');
			printf("%d", ans[i]);
		}
		puts(""); return true;
	}
	if (x > N) return false;
	if (y > M) {
		if (!check(x)) return false;
		if (dfs(dep, x + 1, 1)) return true;
		return false;
	}
	if (dfs(dep, x, y + 1)) return true;
	change(x, y); ans[dep] = (x - 1) * M + y;
	if (dfs(dep + 1, x, y + 1)) return true;
	change(x, y);
	return false;
}

int main() {
	int cas = 0;
	while (scanf("%d%d", &N, &M) == 2 && N) {
		for (int i = 0; i < 3; ++ i) {
			char st[10]; scanf("%s", st);
			c[i] = 0;
			for (int j = 0; j < 3; ++ j) c[i] = c[i] * 2 + (st[j] == '*');
		}
		ss = (1 << M) - 1;
		for (int i = 1; i <= N; ++ i) A[i] = ss;
		printf("Case #%d\n", ++ cas);
		if (!dfs(0, 1, 1)) puts("Impossible.");
	}
	return 0;
}
