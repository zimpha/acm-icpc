#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=805;
const int MAXC=25;
const int inf=100000000;
const double eps=1e-9;

struct node {
	double x, y;
};

struct EDGE {
	int v, flow, cap;
	EDGE *next, *pre;
};

EDGE *head[MAXN], *work[MAXN];
node P[MAXN][MAXC];
int lev[MAXN], C[MAXN];
int N, M, S, T;

void addedge(int u, int v, int cap) {
	EDGE *pu=new(EDGE), *pv=new(EDGE);
	pu->v = v; pu->flow = 0; pu->cap = cap; pu->next = head[u];
	pv->v = u; pv->flow = 0; pv->cap = 0; pv->next = head[v];
	head[u] = pu; head[u]->pre = pv;
	head[v] = pv; head[v]->pre = pu;
}

int sgn(double x) {
	if (fabs(x)<eps) return 0;
	if (x>0) return 1;
	else return -1;
}

double cross(node A, node B, node C) {
	return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
}

bool intersect(node A, node B, node C, node D) {
	if (sgn(cross(A, B, C) * cross(A, B, D)) <= 0 && sgn(cross(C, D, A) * cross(C, D, B)) < 0) return true;
	if (sgn(cross(A, B, C) * cross(A, B, D)) < 0 && sgn(cross(C, D, A) * cross(C, D, B)) <= 0) return true;
	return false;
}

bool dinic_bfs() {
	queue<int> q;
	while (!q.empty()) q.pop();
	memset(lev, -1, sizeof(lev));
	lev[S] = 1; q.push(S);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (EDGE *e = head[u]; e; e = e->next) {
			int v = e->v;
			if (lev[v] == -1&&e->cap > e->flow) {
				lev[v] = lev[u] + 1;
				q.push(v);
			}
		}
	}
	return (lev[T] != -1);
}

int dinic_dfs(int u, int low) {
	if (u == T) return low;
	for (EDGE *e = work[u]; e; e = e->next) {
		int v = e->v; work[u] = e;
		if (lev[v] == lev[u] + 1 && e->cap > e->flow) {
			int tmp = dinic_dfs(v, min(low, e->cap - e->flow));
			if (tmp > 0) {
				e->flow += tmp;
				e->pre->flow -= tmp;
				return tmp;
			}
		}
	}
	return 0;
}

int dinic() {
	int maxflow = 0;
	while (dinic_bfs()) {
		memcpy(work, head, sizeof(head));
		while (1) {
			int tmp = dinic_dfs(S, inf);
			if (tmp == 0) break;
			maxflow += tmp;
		}
	}
	return maxflow;
}

int main() {
	while (scanf("%d%d", &N, &M) == 2) {
		S = 0; T = N + M + 1;
		int ans = 0;
		memset(head, 0, sizeof(head));
		for (int x, i = 1; i <= N; ++ i) {
			scanf("%d", &x);
			addedge(i + M, T, x);
		}
		for (int x, i = 1; i <= M; ++ i) {
			scanf("%d", &x);
			addedge(S, i, x);
			ans += x;
		}
		for (int i = 1; i <= N; ++ i) {
			scanf("%d", &C[i]);
			for (int j = 1; j <= C[i]; ++ j)
				scanf("%lf%lf", &P[i][j].x, &P[i][j].y);
			P[i][0] = P[i][C[i]];
		}
		node O, X;
		O.x = O.y = 0;
		for (int i = 1; i <= M; ++ i) {
			scanf("%lf%lf", &X.x, &X.y);
			for (int j = 1; j <= N; ++ j) {
				for (int k = 0; k < C[j]; ++ k)
					if (intersect(O, X, P[j][k], P[j][k + 1])) {
						addedge(i, j + M, inf);
						break;
					}
			}
		}
		cout << ans - dinic() << endl;
	}
	return 0;
}
