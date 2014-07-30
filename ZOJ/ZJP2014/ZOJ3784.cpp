#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXL = 100000 + 10, C = 26;

class automata {
public:
	int go[MAXL][C], val[MAXL], fail[MAXL], last[MAXL], sz;
	int NewNode() {
		memset(go[sz], 0, sizeof(go[sz]));
		val[sz] = 0; return sz ++;
	}
	void init() {
		sz = 0; NewNode();
	}
	void insert(const char *s) {
		int now = 0;
		for (int i = 0, c; s[i]; ++ i, now = go[now][c]) {
			c = s[i] - 'a';
			if (!go[now][c]) go[now][c] = NewNode();
		}
		val[now] = 1;
	}
	void build(int M = C) {
		queue<int> q;
		fail[0] = 0; last[0] = 0;
		for (int i = 0, u; i < M; ++ i) {
			if ((u = go[0][i])) {
				q.push(u); last[u] = 0;
			}
		}
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (int i = 0; i < M; ++ i) {
				int &y = go[x][i];;
				if (!y) y = go[fail[x]][i];
				else {
					fail[y] = go[fail[x]][i];
					last[y] = val[fail[y]] ? fail[y] : last[fail[y]];
					val[y] |= val[last[y]];
					q.push(y);
				}
			}
		}
	}
} AC;

int low[MAXL], dfn[MAXL], stk[MAXL], sccid[MAXL];
int scc_cnt, tid, top, N, M;
bool vis[MAXL];

void dfs(int x) {
	low[x] = dfn[x] = ++ tid;
	stk[top ++] = x; vis[x] = true;
	for (int i = 0; i < M; ++ i) {
		int y = AC.go[x][i];
		if (AC.val[y]) continue;
		if (!dfn[y]) {
			dfs(y);
			low[x] = min(low[x], low[y]);
		}
		else if (vis[y]) low[x] = min(low[x], dfn[y]);
	}
	if (dfn[x] == low[x]) {
		for (; ; ) {
			int y = stk[-- top];
			vis[y] = false;
			sccid[y] = scc_cnt;
			if (x == y) break;
		}
		scc_cnt ++;
	}
}

void find_scc() {
	tid = scc_cnt = top = 0;
	memset(vis, 0, sizeof(vis));
	memset(dfn, 0, sizeof(dfn));
	memset(sccid, -1, sizeof(sccid));
	for (int i = 0; i < AC.sz; ++ i)
		if (!AC.val[i] && !dfn[i]) dfs(i);
}

int cnt1[MAXL], cnt2[MAXL];
int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &N, &M);
		AC.init();
		for (int i = 0; i < N; ++ i) {
			char s[2000]; scanf("%s", s);
			AC.insert(s);
		}
		AC.build(M);
		find_scc();
		fill(cnt1, cnt1 + scc_cnt, 0);
		fill(cnt2, cnt2 + scc_cnt, 0);
		for (int i = 0; i < AC.sz; ++ i) {
			if (AC.val[i]) continue;
			cnt1[sccid[i]] ++;
			for (int j = 0; j < M; ++ j) {
				int y = AC.go[i][j];
				if (!AC.val[y] && sccid[i] == sccid[y]) cnt2[sccid[i]] ++;
			}
		}
		bool flag = false;
		for (int i = 0; i < scc_cnt; ++ i) flag |= (cnt1[i] && cnt2[i] > cnt1[i]);
		if (flag) puts("Yes");
		else puts("No");
	}
	return 0;
}
