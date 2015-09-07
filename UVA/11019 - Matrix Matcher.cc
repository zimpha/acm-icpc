#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXL = 10010;
const int MAXN = 1010;
const int C = 26;

char text[MAXN][MAXN], pat[MAXN][MAXN];
int cnt[MAXN][MAXN];
int n, m, x, y;

struct automata {
	int go[MAXL][C], fail[MAXL], last[MAXL];
	vector <int> val[MAXL];
	int p, ans;

	int new_node() {
		memset(go[p], 0, sizeof(go[p])); val[p].clear();
		return p ++;
	}

	void init() {
		memset(go[0], 0, sizeof(go[0])); val[0].clear();
		p = 1;
	}

	void insert(const char *s, int v) {
		int now = 0;
		for (int i = 0, c; s[i]; ++ i, now = go[now][c]) {
			c = s[i] - 'a';
			if (go[now][c] == 0) go[now][c] = new_node();
		}
		val[now].push_back(v);
	}

	void get_fail() {
		queue <int> q; while (!q.empty()) q.pop();
		for (int i = 0, u; i < C; ++ i) {
			if ((u = go[0][i])) {
				fail[u] = last[u] = 0;
				q.push(u);
			}
		}
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (int i = 0; i < C; ++ i) {
				int &y = go[x][i];
				if (!y) {
					y = go[fail[x]][i];
				} else {
					fail[y] = go[fail[x]][i];
					last[y] = val[fail[y]].size() ? fail[y] : last[fail[y]];
					q.push(y);
				}
			}
		}
	}

	void print(int pi, int pj, int x) {
		for (int i = 0; i < (int)val[x].size(); ++ i) {
			int line = val[x][i];
			if (pi >= line) cnt[pi - line][pj] ++;
		}
		if (last[x]) print(pi, pj, last[x]);	
	}

	void solve(const char s[][MAXN], int n, int m) {
		int now = 0;
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < m; ++ j) {
				int c = s[i][j] - 'a';
				now = go[now][c];
				if (j + 1 < y) continue;
				if (val[now].size()) {
					print(i, j, now);
				} else if (last[now]) {
					print(i, j, last[now]);
				}
			}
		}
		this->ans = 0;
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < m; ++ j) {
				if (cnt[i][j] == x) {
					this->ans ++;
				}
			}
		}
	}
}AC;

int main() {
	int T; scanf("%d", &T);	
	while (T --) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++ i) {
			scanf("%s", text[i]);
		}
		scanf("%d%d", &x, &y);
		for (int i = 0; i < x; ++ i) {
			scanf("%s", pat[i]);
		}
		memset(cnt, 0, sizeof(cnt));
		AC.init();
		for (int i = 0; i < x; ++ i) {
			AC.insert(pat[i], i);
		}
		AC.get_fail();
		AC.solve(text, n, m);
		printf("%d\n", AC.ans);
	}
	return 0;
}
