#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int inf=1e9;

struct node {
	int u, v, w;
};

vector<node> edge;
vector<int> d, e, f;
int n;

int getf(int x) {
	return (x==f[x]) ? x : (f[x]=getf(f[x]));
}

int Boruvka(int n, int m) {
	int ret=0;
	while (1) {
		int cross_edge=0;
		for (int i=1; i<=n; i++) d[i]=inf;
		for (int i=0; i<m; i++) {
			int u=getf(edge[i].u);
			int v=getf(edge[i].v);
			int w=edge[i].w;
			if (u==v) continue;
			cross_edge++;
			if (w<d[u]||(w==d[u]&&i<e[u])) d[u]=w, e[u]=i;
			if (w<d[v]||(w==d[v]&&i<e[v])) d[v]=w, e[v]=i;
		}
		if (cross_edge==0) break;
		for (int i=1; i<=n; i++)
			if (d[i]!=inf) {
				int u=getf(edge[e[i]].u);
				int v=getf(edge[e[i]].v);
				int w=edge[e[i]].w;
				if (u==v) continue;
				ret+=w; f[u]=v;
			}
	}
	return ret;
}

int main() {
	bool first=true;
	while (scanf("%d", &n)==1) {
		if (!first) puts("");
		f.resize(n+1); d.resize(n+1); e.resize(n+1);
		for (int i=1; i<=n; i++) f[i]=i;
		int precost=0, nowcost=0;
		for (int u, v, w, i=0; i<n-1; i++) {
			scanf("%d%d%d", &u, &v, &w);
			precost+=w;
		}
		int k, m; 
		scanf("%d", &k); edge.resize(k);
		for (int i=0; i<k; i++) scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
		scanf("%d", &m); edge.resize(k+m);
		for (int i=k; i<m+k; i++) scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
		nowcost=Boruvka(n ,m+k);
		printf("%d\n%d\n", precost, nowcost);
		first=false;
	}
	return 0;
}
