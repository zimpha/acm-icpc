#include <cstdio>
#include <cstring>

const int MAXN=55;
const int MAXM=1005;

int map[MAXN][MAXN];
int deg[MAXN];
int ans[MAXM];
int n,m,cnt;
int root;

void find(int u)
{
    for (int v=1; v<=n; v++)
	if (map[u][v]>0)
	{
	    map[u][v]--;
	    map[v][u]--;
	    find(v);
	}
    ans[cnt++]=u;
}

int main()
{
    int test;
    scanf("%d",&test);
    for (int cas=1; cas<=test; cas++)
    {
	memset(map,0,sizeof(map));
	memset(deg,0,sizeof(deg));
	n=0;
	scanf("%d",&m);
	for (int i=0; i<m; i++)
	{
	    int u, v;
	    scanf("%d%d", &u, &v);
	    if (u>n) n=u; if (v>n) n=v;
	    map[u][v]++; map[v][u]++;
	    deg[u]++; deg[v]++;
	    root=u;
	}
	bool flag=true;
	for (int i=1; i<=n; i++)
	    if (deg[i]&1) flag=false;
	cnt=0;
	if (flag) find(root);
	printf("Case #%d\n",cas);
	if (!flag) printf("some beads may be lost\n");
	else
	{
	    for (int i=0; i<cnt-1; i++)
		printf("%d %d\n",ans[i],ans[i+1]);
	}
	if (cas<test) printf("\n");
    }
    return 0;
}
