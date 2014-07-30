#include <queue>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAXN=505;
const int MAXM = 600000;
const int inf = 1000000000;

struct Edge {
	int v, flow;
	Edge *next, *pre;
} pool[MAXM], *cnt;

Edge *head[MAXN];
int level[MAXN], Q[MAXN];
int pos[MAXN], val[MAXN];
int N, S, T, P;

void addedge(int u, int v, LL cap) {
	Edge *pu = cnt ++, *pv = cnt ++;
	pu->v = v; pu->flow = cap; pu->next = head[u];
	pv->v = u; pv->flow = 0; pv->next = head[v];
	head[u] = pu; head[u]->pre = pv;
	head[v] = pv; head[v]->pre = pu;
}

int gcd(int a, int b) {
	if (!b) return a;
	else return gcd(b, a % b);
}

bool check(int a, int b) {
	if (((a ^ b) & 1) == 0) return false;
	if (gcd(a ^ b, P) == 1) return true;
	else return false;
}

bool dinic_bfs() {
	memset(level, -1, sizeof(level));
	level[S] = 0; Q[0] = S;
	for (int h = 0, t = 1; h < t; ++ h) {
		int u = Q[h], v;
		for (Edge *p = head[u]; p; p = p->next) 
			if (level[v = p->v] == -1 && p->flow >0) {
				level[v] = level[u] + 1;
				Q[t ++] = v;
			}
	}
	return (level[T] != -1);
}

int dinic_dfs(int u, int low) {
	if (u == T) return low;
	int ret = 0, tmp, v;
	for (Edge *p = head[u]; p && ret < low; p = p->next) 
		if (level[v = p->v] == level[u] + 1 && p->flow > 0) {
			tmp = dinic_dfs(v, min(low - ret, p->flow));
			if (tmp) {
				ret += tmp, p->flow -= tmp, p->pre->flow += tmp;
			}
		}
	if (!ret) level[u] = -1; return ret;
}

LL dinic() {
	LL maxflow = 0, t;
	while (dinic_bfs()) {
		while ((t = dinic_dfs(S, inf))) maxflow += t;
	}
	return maxflow;
}

int main() {
	while (scanf("%d%d", &N, &P) == 2) {
		LL sum = 0;
		memset(head, 0, sizeof(head)); cnt = pool;
		S = 0; T = N + 1;
		for (int i = 1; i <= N; ++ i) {
			int x, y; scanf("%d%d", &x, &y);
			pos[i] = x ^ y; val[i] = x & y;
			sum += val[i];
			if (pos[i] & 1) addedge(S, i, val[i]);
			else addedge(i, T, val[i]);
		}
		for (int i = 1; i <= N; ++ i)
			for (int j = i + 1; j <= N; ++ j) {
				if (check(pos[i], pos[j])) {
					if (pos[i] & 1) addedge(i, j, inf);
					else addedge(j, i, inf);
				}
			}
		printf("%lld\n", sum - dinic());
	}
	return 0;
}
