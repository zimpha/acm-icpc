#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 160;
const int SIZE = 80;
const int MAXL = 20500;
const int C = 26;

char pat[MAXN][SIZE], text[1000010];
int cnt[MAXN];

struct automata {
	int go[MAXL][C], val[MAXL], fail[MAXL], last[MAXL];
	int p, root, null;
	
	int new_node() {
		memset(go[p], null, sizeof(go[p]));
		val[p] = -1; return p ++;
	}

	void init() {
		p = 0; null = 0; root = new_node(); 
	}

	void insert(const char *s, int v) {
		int now = root;
		for (int i = 0, c; s[i]; ++ i, now = go[now][c]) {
			c = s[i] - 'a';
			if (go[now][c] == null) go[now][c] = new_node();
		}
		val[now] = v;
	}

	void get_fail() {
		queue <int> q; while (!q.empty()) q.pop();
		fail[root] = 0;
		for (int i = 0, u; i < C; ++ i) {
			if ((u = go[root][i]) != null) {
				fail[u] = last[u] = 0;
				q.push(u);
			}
		}
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (int i = 0; i < C; ++ i) {
				int &y = go[x][i];
				if (y == null) y = go[fail[x]][i];
				else {
					fail[y] = go[fail[x]][i];
					last[y] = val[fail[y]] != -1 ? fail[y] : last[fail[y]];
					q.push(y);
				}
			}
		}
	}

	void print(int x) {
		cnt[val[x]] ++;
		if (last[x]) print(last[x]);
	}

	void find(const char *s) {
		int now = root;
		for (int i = 0; s[i]; ++ i) {
			int c = s[i] - 'a';
			now = go[now][c];
			if (val[now] != -1) print(now);
			else if (last[now]) print(now);
		}
	}
}AC;

int main() {
	int n;
	while (scanf("%d", &n) == 1 && n) {
		AC.init();
		for (int i = 0; i < n; ++ i) {
			scanf("%s", pat[i]);
			AC.insert(pat[i], i);
			cnt[i] = 0;
		}
		AC.get_fail();
		scanf("%s", text);
		AC.find(text);
		int maxtime = 0;
		for (int i = 0; i < n; ++ i) maxtime = max(maxtime, cnt[i]);
		printf("%d\n", maxtime);
		for (int i = 0; i < n; ++ i) {
			if (maxtime == cnt[i]) puts(pat[i]);
		}
	}
	return 0;
}
