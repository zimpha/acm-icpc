#include <cstdio>
#include <cstring>

const int MAXN=125;
const int MAXM=7200;
const int inf=1000000;

struct node
{
    int u,v;
};

int dis[MAXN][MAXN];
node rope[MAXM];
int n,m;

int count(int l,int r)
{
    int sum=0;
    for (int i=0; i<m; i++)
	if (dis[l][r]==dis[l][rope[i].u]+1+dis[rope[i].v][r]||
	    dis[l][r]==dis[l][rope[i].v]+1+dis[rope[i].u][r])
	    sum++;
    return sum;
}

int main()
{
    int test;
    scanf("%d",&test);
    for (int cas=1; cas<=test; cas++)
    {
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++)
	    for (int j=0; j<n; j++)
		dis[i][j]=(i==j)?0:inf;
	for (int i=0; i<m; i++)
	{
	    scanf("%d%d",&rope[i].u,&rope[i].v);
	    dis[rope[i].u][rope[i].v]=1;
	    dis[rope[i].v][rope[i].u]=1;
	}
	for (int k=0; k<n; k++)
	    for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
		    if (dis[i][j]>dis[i][k]+dis[k][j])
			dis[i][j]=dis[i][k]+dis[k][j];
	int ans=0;
	for (int i=0; i<n; i++)
	    for (int j=0; j<i; j++)
	    {
		int tmp=count(i,j);
		if (tmp>ans) ans=tmp;
	    }
	printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
