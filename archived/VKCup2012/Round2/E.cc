#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
static const int MAXL = 1e6 + 10, C = 26;

int go[MAXL][C], fail[MAXL], val[MAXL], suff[MAXL];
int st[MAXL], ed[MAXL], cnt[MAXL], sz;
vector<int> G[MAXL];

int NewNode() {
	memset(go[sz], 0, sizeof(go[sz]));
	cnt[sz] = 0; G[sz].clear();
	return sz ++;
}
void init() {sz = 0; NewNode();}
int ins(const char *s) {
	int p = 0;
	for (int i = 0, o; s[i]; ++ i, p = go[p][o]) {
		o = s[i] - 'a';
		if (!go[p][o]) go[p][o] = NewNode();
	}
	val[p] = 1; return p;
}
void build() {
	queue<int> Q;
	for (int o = 0; o < C; ++ o) if (go[0][o]) {
		Q.push(go[0][o]); fail[go[0][o]] = 0;
	}
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		G[fail[u]].push_back(u);
		suff[u] = val[suff[u]] ? fail[u] : suff[fail[u]];
		val[u] |= val[suff[u]];
		for (int o = 0; o < 26; ++ o) {
			int x = go[fail[u]][o], &v = go[u][o];
			if (v) fail[v] = x, Q.push(v);
			else v = x;
		}
	}
}
void dfs(int u) {
	st[u] = sz ++;
	for (auto &v : G[u]) dfs(v);
	ed[u] = sz ++;
}

int pos[MAXL];
char s[MAXL];

int u[MAXL << 1];
void add(int x, int v) {
	for (; x < sz; x += ~x & x + 1) u[x] += v;
}
int get(int x) {
	int r = 0;
	for (; x >= 0; x -= ~x & x + 1) r += u[x];
	return r;
}

void fix(int x, int v) {
	if ((v == -1 && cnt[x] == 1) || (v == 1 && cnt[x] == 0)) {
		add(st[x], v); add(ed[x], -v); cnt[x] += v;
	}
}

int main() {
	int n, m; scanf("%d%d", &m, &n);
	init();
	for (int i = 0; i < n; ++ i) {
		scanf("%s", s);	
		pos[i] = ins(s);
	}
	build(); sz = 0; dfs(0);
	for (int i = 0; i < n; ++ i) fix(pos[i], 1);
	for (int _ = 0; _ < m; ++ _) {
		char op;
		while ((op = getc(stdin)) == ' ' || op == '\n');
		if (op == '+') {
			int x; scanf("%d", &x);
			fix(pos[x - 1], 1);
		}
		else if (op == '-') {
			int x; scanf("%d", &x);
			fix(pos[x - 1], -1);
		}
		else {
			scanf("%s", s);
			int p = 0;
			LL ret = 0;
			for (int i = 0; s[i]; ++ i) {
				p = go[p][s[i] - 'a'];
				ret += get(st[p]);
			}
			printf("%lld\n", ret);
		}
	}
	return 0;
}
