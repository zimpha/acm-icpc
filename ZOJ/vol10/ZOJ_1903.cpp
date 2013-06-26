#include <iostream>
#include <cstring>
#define MAXN 20
#define size 1<<15

using namespace std;

int f[size],p[MAXN];
int dis[MAXN][MAXN];
int n,m,state,sum;

int main()
{
    while (1)
    {
	cin >> n >> m;
	if (n==0) break;
	for (int i=0; i<=n; i++) 
	    p[i]=1<<i;
	state=sum=0;
	memset(dis,1,sizeof(dis));
	for (int i=0; i<m; i++)
	{
	    int u,v,w;
	    cin >> u >> v >> w;
	    if (w<dis[u][v])
	    {
		dis[u][v]=dis[v][u]=w;
	    }
	    sum+=w;
	    state^=p[u-1];
	    state^=p[v-1];
	}
	for (int k=1; k<=n; k++)
	    for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
		    if (dis[i][j]>dis[i][k]+dis[k][j])
			dis[i][j]=dis[i][k]+dis[k][j];
	memset(f,1,sizeof(f));
	f[0]=0;
	for (int s=1; s<=state; s++)
	    for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
		    if ((s&p[i-1])&&(s&p[j-1])&&(f[s]>f[s-p[i-1]-p[j-1]]+dis[i][j]))
			f[s]=f[s-p[i-1]-p[j-1]]+dis[i][j];
	cout << sum+f[state] <<endl;
    }
    return 0;
}
