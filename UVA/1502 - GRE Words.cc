#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXL = 400000;
const int MAXN = 20010;
const int C = 26;

char words[MAXL];
int dp[MAXN], pos[MAXN];

struct automata {
	int go[MAXL][C], fail[MAXL], idx[MAXL], p;
	bool val[MAXL];
	int New_Node() {
		memset(go[p], 0, sizeof(go[p]));
		val[p] = 0; return p ++;
	}
	void init() {
		p = 0; New_Node();
	}
	void insert(int i) {
		for (int now = 0, o; words[i]; ++ i, now = go[now][o]) {
			o = words[i] - 'a';
			if (go[now][o] == 0) go[now][o] = New_Node();
		}
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
					q.push(y);
				}
			}
		}
	}
	void solve(int t) {
		int now = 0, ret = 0, tmp;
		for (int i = pos[t]; i < pos[t + 1]; ++ i) {
			int o = words[i] - 'a';
			tmp = now = go[now][o];
			while (tmp) {
				if (val[tmp]) ret = max(ret, dp[idx[tmp]]);
				tmp = fail[tmp];
			}
		}
		dp[t] += ret;
		val[now] = 1;
		idx[now] = t;
	}
}AC;

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		int N; scanf("%d", &N);
		AC.init(); pos[0] = 0;
		for (int i = 0; i < N; ++ i) {
			scanf("%s%d", words + pos[i], dp + i);
			pos[i + 1] = pos[i] + strlen(words + pos[i]);
			AC.insert(pos[i]);
		}
		AC.get_fail();
		int ret = 0;
		for (int i = 0; i < N; ++ i) {
			if (dp[i] > 0) {
				AC.solve(i);
				ret = max(ret, dp[i]);
			}
		}
		printf("Case #%d: %d\n", cas, ret);
	}
	return 0;
}
