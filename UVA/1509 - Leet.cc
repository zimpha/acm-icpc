#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 300;

char st[MAXN], leet[MAXN];
bool vis[MAXN], flag;
int mp[MAXN][2];
int K, N, M;

void dfs(int a, int b) {
	if (M - b < N - a) return;
	if (M - b > K * (N - a)) return;
	if (flag) return;
	if (a == N && M == b) {flag = true; return;}
	if (vis[(int)st[a]]) {
		int l = mp[(int)st[a]][0], r = mp[(int)st[a]][1], i;
		for (i = l; i < r; ++ i) if (leet[i] != leet[b + i - l]) break;
		if (i == r) dfs(a + 1, b + r - l);
	} else {
		for (int i = 1; i <= K; ++ i) {
			vis[(int)st[a]] = 1;
			mp[(int)st[a]][0] = b;
			mp[(int)st[a]][1] = b + i;
			dfs(a + 1, b + i);
			vis[(int)st[a]] = 0;
		}
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%s%s", &K, st, leet);
		N = strlen(st); M = strlen(leet);
		memset(vis, 0, sizeof(vis)); flag = false;
		dfs(0, 0);
		if (flag) puts("1");
		else puts("0");
	}
	return 0;
}
