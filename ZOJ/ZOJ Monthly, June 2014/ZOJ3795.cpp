#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

struct node {
	int v;
	node *next;
};

node *head[MAXN],  *G[MAXN];
int low[MAXN], dfn[MAXN], col[MAXN];
int stack[MAXN];
bool instack[MAXN];
int N, M, cnt, top;

void addedge_head(int u, int v) {
	node *p = new(node);
	p->v = v;
	p->next = head[u];
	head[u] = p;
}

void addedge_G(int u, int v) {
	node *p = new(node);
	p->v = v;
	p->next = G[u];
	G[u] = p;
}

void tarjan(int u) {
	low[u] = dfn[u] = ++cnt;
	instack[u] = true;
	stack[++top] = u;
	for (node *e = head[u]; e; e = e->next) {
		int v = e->v;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (instack[v]) low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		int v;
		M++;
		do {
			v = stack[top--];
			instack[v] = false;
			col[v] = M;
		}
		while (u != v);
	}
}

void shrink() {
	memset(G, 0, sizeof(G));
	memset(low, 0, sizeof(low));
	for (int u = 1; u <= N; u++) {
		low[col[u]] ++;
		for (node *e = head[u]; e; e = e->next) {
			int v = e->v;
			if (col[u] != col[v]) addedge_G(col[u], col[v]);
		}
	}
}

void dfs(int u) {
	if (instack[u])return;
	instack[u] = true;
	for (node *e = G[u]; e; e = e->next) {
		int v = e->v;
		dfs(v);
		if (dfn[u] < dfn[v])dfn[u] = dfn[v];
	}
	dfn[u] += low[u];
}

void solve() {
	memset(instack, 0, sizeof(instack));
	memset(dfn, 0, sizeof(dfn));
	int ret = 0;
	for (int i = 1; i <= M; i++) {
		dfs(i);
		if (dfn[i] > ret)ret = dfn[i];
	}
	printf("%d\n", ret);
}

int main() {
	while (scanf("%d %d", &N, &M) == 2) {
		memset(head, 0, sizeof(head));
		while (M--) {
			int a, b;
			scanf("%d%d", &a, &b);
			addedge_head(a, b);
		}
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		memset(col, 0, sizeof(col));
		memset(instack, 0, sizeof(instack));
		cnt = M = top = 0;
		for (int u = 1; u <= N; u++)
			if (!dfn[u]) tarjan(u);
		shrink();
		solve();
	}
	return 0;
}

