#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN=200+10;
const int inf=1e9;

int map[MAXN][MAXN], dis[MAXN], ver[MAXN];
bool vis[MAXN];
int n, m;

int stoer_wagner(int n) {
	int i, j, ret=inf;
	for (i=0; i<n; i++) ver[i]=i;
	while (n>1) {
		int t=1, s=0;
		for (i=1; i<n; i++) {
			dis[ver[i]]=map[ver[0]][ver[i]];			
			if (dis[ver[i]]>dis[ver[t]]) t=i;
		}
		memset(vis, 0, sizeof(vis)); vis[0]=true;
		for (i=1; i<n; i++) {
			if (i==n-1) {
				ret=min(ret, dis[ver[t]]);
				for (j=0; j<n; j++) {
					map[ver[s]][ver[j]]+=map[ver[j]][ver[t]];
					map[ver[j]][ver[s]]+=map[ver[j]][ver[t]];
				}
				ver[t]=ver[--n];
			}
			vis[ver[t]]=true; s=t; t=-1;
			for (j=1; j<n; j++)
				if (!vis[ver[j]]) {
					dis[ver[j]]+=map[ver[s]][ver[j]];
					if (t==-1||dis[ver[t]]<dis[ver[j]]) t=j;
				}
		}
	}
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	for (int cas=1; cas<=T; cas++) {
		scanf("%d%d", &n, &m);
		memset(map, 0, sizeof(map));
		for (int u, v, w, i=0; i<m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			u--; v--;
			map[u][v]+=w; map[v][u]+=w;
		}
		printf("Case #%d: %d\n", cas, stoer_wagner(n));
	}
	return 0;
}
