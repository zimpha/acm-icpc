#include <queue>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAXN=505;
const int inf=1000000000;
const int SIZE=10000;

struct node {
   int v, cap, flow;
   node *next, *pre;
};

queue<int> q;
node *head[MAXN], *work[MAXN];
int lev[MAXN];
int N, M, S, T;

void addedge(int u, int v, int cap) {
   node *pu = new(node), *pv = new(node);
   pu->v = v; pu->cap = cap; pu->flow = 0; pu->next = head[u];
   pv->v = u; pv->cap = 0; pv->flow = 0; pv->next = head[v];
   head[u] = pu; head[u]->pre = pv;
   head[v] = pv; head[v]->pre = pu;
}

bool dinic_bfs() {
   while (!q.empty()) q.pop();
   memset(lev, -1, sizeof(lev));
   lev[S] = 0; q.push(S);
   while (!q.empty()) {
      int u = q.front(); q.pop();
      for (node *e = head[u]; e; e = e->next) {
         int v = e->v;
         if (lev[v] == -1 && e->cap > e->flow) {
            lev[v] = lev[u] + 1;
            q.push(v);
         }
      }
   }
   return (lev[T] >= 0);
}

int dinic_dfs(int u, int low) {
   if (u == T) return low;
   for (node *e = work[u]; e; e = e->next) {
      int v = e->v; work[u] = e;
      if (lev[v] == lev[u] + 1 && e->cap > e->flow) {
         int tmp = dinic_dfs(v, min(low, e->cap - e->flow));
         if (tmp) {
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
    int tests;
    scanf("%d", &tests);
    while (tests --) {
		int sum = 0;
		scanf("%d %d %d %d", &N, &M, &S, &T);
      	memset(head, 0, sizeof(head));
      	for (int i = 0; i < M; ++ i) {
         	int u, v, w;
         	scanf("%d%d%d", &u, &v, &w);
         	sum += w;
			addedge(u, v, w * SIZE + 1);
			addedge(v, u, w * SIZE + 1);
		}
		int maxflow = dinic();
		int edges = maxflow % SIZE;
		maxflow /= SIZE;
		if (edges == 0) printf("Inf\n");
		else printf("%.2f\n", 1.0 * (sum - maxflow) / edges);
   	}
   	return 0;
}
