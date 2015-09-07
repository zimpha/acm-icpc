#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXL = 500010;
const int MAXN = 26;

bool exist[MAXL];
int vis[MAXL];
int go[MAXL][MAXN], fail[MAXL];
int dp[MAXL], pre[MAXL];
int n, cnt, s;

int new_node() {
	memset(go[cnt], 0, sizeof(go[cnt]));
	exist[cnt] = false; return cnt ++;
}

void init() {
	memset(go[0], 0, sizeof(go[0])); exist[0]= false;
	cnt = 1; 
}

void Insert(const char *s) {
	int now = 0;
	for (int i = 0, o; s[i]; ++ i, now = go[now][o]) {
		o = s[i] - 'A';
		if (go[now][o] == 0) go[now][o] = new_node();
	}
	exist[now] = true;
}

void build() {
	queue <int> q; while (!q.empty()) q.pop();
	for (int i = 0; i < n; ++ i) {
		if (go[0][i]) {
			fail[go[0][i]] = 0;
			q.push(go[0][i]);
		}
	}
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < n; ++ i) {
			int &y = go[x][i];
			if (!y) y = go[fail[x]][i];
			else {
				fail[y] = go[fail[x]][i];
				exist[y] |= exist[fail[y]];
				q.push(y);
			}
		}
	}
}

int solve(int now) {
	if (vis[now] == 1) return -1;
	if (vis[now] == 2) return dp[now];
	vis[now] = 1; dp[now] = 0;
	for (int i = n - 1; i >= 0; -- i) {
		if (!exist[go[now][i]]) {
			int res = solve(go[now][i]);
			if (res == -1) return -1;
			if (res + 1 > dp[now]) {
				dp[now] = res + 1;
				pre[now] = i;
			}
		}
	}
	vis[now] = 2; 
	return dp[now];
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &n, &s);
		init();
		char st[100];
		for (int i = 0; i < s; ++ i) {
			scanf("%s", st);
			Insert(st);
		}
		build();
		memset(vis, 0, sizeof(vis));
		memset(pre, -1, sizeof (pre));
		memset(dp, 0, sizeof(dp));
		int ret = solve(0);
		if (ret == -1 || ret == 0) {
			puts("No");
		} else {
			for (int i = 0, now = 0; i < ret; ++ i) {
				putchar(pre[now] + 'A');
				now = go[now][pre[now]];
			}
			puts("");
		}
	}
	return 0;
}
