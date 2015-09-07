#include <queue>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXL = 500;
const int MAXN = 200;
const int C = 62;

double prob[C];

inline int idx(char c) {
	if (islower(c)) return c - 'a';
	else if (isupper(c)) return c - 'A' + 26;
	else return c - '0' + 52;
}

struct automata {
	int go[MAXL][C], fail[MAXL], p;
	bool vis[MAXL][MAXN], exist[MAXL];
	double dp[MAXL][MAXN];
	
	int new_node() {
		fill(go[p], go[p] + C, 0);
		return p ++;
	}

	void init() {
		fill(exist, exist + MAXL, 0);
		memset(vis, 0, sizeof(vis));
		fill(go[0], go[0] + C, 0);
		p = 1;
	}

	void insert(const char *s) {
		int now = 0;
		for (int i = 0, c; s[i]; ++ i, now = go[now][c]) {
			c = idx(s[i]);
			if (go[now][c] == 0) go[now][c] = new_node();
		}
		exist[now] = true;
	}

	void get_fail() {
		queue <int> q; while (!q.empty()) q.pop();
		fail[0] = 0;
		for (int i = 0; i < C; ++ i) {
			if (go[0][i]) fail[go[0][i]] = 0, q.push(go[0][i]);
		}
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (int i = 0; i < C; ++ i) {
				int &y = go[x][i];
				if (y == 0) y = go[fail[x]][i];
				else {
					fail[y] = go[fail[x]][i];
					exist[y] |= exist[fail[y]];
					q.push(y);
				}
			}
		}
	}

	double solve(int u, int L) {
		if (L == 0) return 1.0;
		if (vis[u][L]) return dp[u][L];
		vis[u][L] = true;
		double &ans = dp[u][L];
		ans = 0.0;
		for (int i = 0; i < C; ++ i) {
			if (!exist[go[u][i]]) ans += prob[i] * solve(go[u][i], L - 1);
		}
		return ans;
	}
}AC;

int main() {
	int T, n; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		AC.init();
		char st[100];
		scanf("%d", &n);
		while (n --) {
			scanf("%s", st);
			AC.insert(st);
		}
		AC.get_fail();
		memset(prob, 0, sizeof(prob));
		scanf("%d", &n);
		for (int i = 0; i < n; ++ i) {
			getchar();
			char c = getchar();
			scanf("%lf", &prob[idx(c)]);
		}
		scanf("%d", &n);
		printf("Case #%d: %.6f\n", cas, AC.solve(0, n));
	}
	return 0;
}
