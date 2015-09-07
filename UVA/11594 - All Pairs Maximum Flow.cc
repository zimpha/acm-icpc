#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN=200+10;
const int inf=1e9;

struct node {
	int v, next;
	int flow;
}edge[MAXN*MAXN<<1];

int head[MAXN], que[MAXN];
int level[MAXN];
int n, cnt;
int s, t;

inline void addedge(int u, int v, int a, int b) {
	edge[cnt].v=v; edge[cnt].flow=a; edge[cnt].next=head[u]; head[u]=cnt++;
	edge[cnt].v=u; edge[cnt].flow=b; edge[cnt].next=head[v]; head[v]=cnt++;
}

bool dinic_bfs() {
	memset(level, -1, sizeof(level));
	que[0]=s; level[s]=0;
	for (int front=0, rear=1; front<rear; front++) {
		int u=que[front], v;
		for (int now=head[u]; now!=-1; now=edge[now].next)
			if (level[v=edge[now].v]==-1&&edge[now].flow>0) {
				level[v]=level[u]+1;
				que[rear++]=v;
			}
	}
	return (level[t]!=-1);
}

int dinic_dfs(int u, int low) {
	if (u==t) return low;
	int ret=0, tmp;
	for (int v, now=head[u]; now!=-1&&ret<low; now=edge[now].next)
		if (level[v=edge[now].v]==level[u]+1&&edge[now].flow>0) {
			if (tmp=dinic_dfs(v, min(low-ret, edge[now].flow))) {
				ret+=tmp; edge[now].flow-=tmp; edge[now^1].flow+=tmp;
			}
		}
	if (!ret) level[u]=-1;
	return ret;
}

int dinic() {
	int maxflow=0, tmp;
	while (dinic_bfs()) {
		while (tmp=dinic_dfs(s, inf)) maxflow+=tmp;
	}
	return maxflow;
}

int ans[MAXN][MAXN], p[MAXN];
bool vis[MAXN];

void dfs(int u) {
	vis[u]=true;
	for (int v, now=head[u]; now!=-1; now=edge[now].next)
		if (!vis[v=edge[now].v]&&edge[now].flow>0) dfs(v);
}

void gusfield(int n) {
	int i, j, cut;
	for (i=0; i<n; i++) {
		p[i]=0;
		for (j=0; j<n; j++) ans[i][j]=inf;
	}
	for (i=1; i<n; i++) {
		for (j=0; j<n; j++) vis[j]=false;
		s=i; t=p[i]; cut=dinic();
		ans[s][t]=ans[t][s]=cut;
		dfs(i);
		for (j=i+1; j<n; j++)
			if (vis[j]&&p[i]==p[j]) p[j]=i;
		for (j=0; j<i; j++)
			ans[i][j]=ans[j][i]=min(cut, ans[p[i]][j]);
		for (j=0; j<cnt; j+=2) {
			edge[j].flow+=edge[j^1].flow;
			edge[j^1].flow=0;
		}
	}
	for (i=0; i<n; i++) {
		ans[i][i]=0;
		for (j=0; j<n; j++)
			printf("%d%c", ans[i][j], (j==n-1)?'\n':' ');
	}
}

int main() {
	int T, x; scanf("%d", &T);
	for (int cas=1; cas<=T; cas++) {
		scanf("%d", &n);
		printf("Case #%d:\n", cas);
		if (!n) continue;
		cnt=0; memset(head, -1, sizeof(head));
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++) {
				scanf("%d", &x);
				if (x) addedge(i, j, x, 0);
			}
		gusfield(n);
	}
	return 0;
}
