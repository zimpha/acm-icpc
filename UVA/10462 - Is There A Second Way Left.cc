#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN=100+10;
const int MAXM=200+10;
const int inf=1e9;

struct node {
	int u, v, w;
	bool mark;
	bool operator < (const node &x) const {
		return w<x.w;
	}
};

node edge[MAXM];
vector<pair<int, int> > G[MAXN];
bool vis[MAXN];
int bot[MAXN][MAXN], f[MAXN];
int n, m;

int getf(int x) {
	return (x==f[x]) ? (x) : (f[x]=getf(f[x]));
}

int kruskal() {
	int ret=0, cnt=0;
	sort(edge, edge+m);
	for (int i=0; i<n; i++) f[i]=i;
	for (int i=0; i<m&&cnt<n-1; i++) {
		int u=getf(edge[i].u), v=getf(edge[i].v);
		if (u==v) continue; f[u]=v; cnt++;
		edge[i].mark=true; ret+=edge[i].w;
	}
	if (cnt!=n-1) return inf;
	else return ret;
}

void dfs(int id, int x, int v) {
	vis[x]=1; bot[id][x]=v;
	for (int y, i=0; i<(int)G[x].size(); i++)
		if (!vis[y=G[x][i].first]) {
			dfs(id, y, max(v, G[x][i].second));
		}
}

void solve() {
	int ret=kruskal();
	if (ret==inf) {
		puts("No way");
		return;
	}
	for (int i=0; i<n; i++) G[i].clear();
	for (int i=0; i<m; i++) if (edge[i].mark) {
		int u=edge[i].u, v=edge[i].v, w=edge[i].w;
		G[u].push_back(make_pair(v, w));
		G[v].push_back(make_pair(u, w));
	}
	int ans=inf;
	memset(bot, -1, sizeof(bot));
	for (int i=0; i<m; i++) if (!edge[i].mark) {
		int u=edge[i].u, v=edge[i].v, w=edge[i].w;
		if (bot[u][v]==-1) {
			memset(vis, 0, sizeof(vis));
			dfs(u, u, -1);
		}
		int tmp=ret-bot[u][v]+w;
		if (tmp<ans) ans=tmp;
	}
	if (ans==inf) puts("No second way");
	else printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	for (int cas=1; cas<=T; cas++) {
		scanf("%d%d", &n, &m);
		for (int i=0; i<m; i++) {
			scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
			edge[i].u--; edge[i].v--;
			edge[i].mark=false;
		}
		printf("Case #%d : ", cas);
		solve();
	}
}
