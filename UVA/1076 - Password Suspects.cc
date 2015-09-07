#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXL = 110;
const int MAXN = 30;
const int SIZE = 1025;
const int C = 26;

LL dp[MAXL][MAXN][SIZE];
int N, M;

struct automata {
	int go[MAXL][C], val[MAXL], fail[MAXL], p;
	char st[MAXN];

	int New_Node() {
		memset(go[p], 0, sizeof(go[p]));
		val[p] = 0; return p ++;
	}

	void init() {
		p = 0; New_Node();
	}

	void insert(const char *s, int v) {
		int now = 0;
		for (int i = 0, o; s[i]; ++ i, now = go[now][o]) {
			o = s[i] - 'a';
			if (go[now][o] == 0) go[now][o] = New_Node();
		}
		val[now] |= v;
	}
	
	void get_fail() {
		queue<int> q; while (!q.empty()) q.pop();
		fail[0] = 0;
		for (int i = 0; i < C; ++ i) {
			if (go[0][i]) {
				fail[go[0][i]] = 0;
				q.push(go[0][i]);
			}
		}
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (int i = 0; i < C; ++ i) {
				int &y = go[x][i];
				if (!y) y = go[fail[x]][i];
				else {
					fail[y] = go[fail[x]][i];
					val[y] |= val[fail[y]];
					q.push(y);
				}
			}
		}
	}

	LL solve(int u, int len, int s) {
		if (dp[u][len][s] != -1) return dp[u][len][s];
		LL &ret = dp[u][len][s]; ret = 0;
		if (len == N) {
			if (s == (1 << M) - 1) ret = 1;
			else ret = 0;
			return ret;
		}
		for (int i = 0; i < C; ++ i) {
			ret += solve(go[u][i], len + 1, s | val[go[u][i]]);
		}
		return ret;
	}

	void print(int u, int len, int s) {
		if (len == N) {
			st[N] = '\0'; puts(st); return;
		}
		for (int i = 0; i < C; ++ i) {
			st[len] = 'a' + i;
			if (dp[go[u][i]][len + 1][s | val[go[u][i]]] > 0) {
				print(go[u][i], len + 1, s | val[go[u][i]]);
			}
		}
	}
};

int main() {
	int cas = 0;
	while (scanf("%d%d", &N, &M) == 2 && N) {
		automata AC; AC.init();
		for (int i = 0; i < M; ++ i) {
			char st[100]; scanf("%s", st);
			AC.insert(st, 1 << i);
		}
		AC.get_fail();
		memset(dp, -1, sizeof(dp));
		LL ret = AC.solve(0, 0, 0);
		printf("Case %d: %lld suspects\n", ++ cas, ret);
		if (ret <= 42) {
			AC.print(0, 0, 0);
		}
	}
	return 0;
}
