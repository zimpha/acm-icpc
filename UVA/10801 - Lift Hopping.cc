#include <queue>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>

const int MAXN=5;
const int MAXFLOOR=100;
const int inf=1000000000;

bool g[MAXN][MAXFLOOR];
bool vis[MAXFLOOR];
int dis[MAXFLOOR];
int t[MAXN];
int n,k;

void spfa()
{
    std::queue<int>q;
    while (!q.empty()) q.pop();
    for (int i=0; i<MAXFLOOR; i++)
    {
	dis[i]=inf; 
	vis[i]=false;
    }
    q.push(0); dis[0]=0; vis[0]=1;
    while (!q.empty())
    {
	int u=q.front(); q.pop();
	for (int i=0; i<5; i++)
	    if (g[i][u])
		for (int v=0; v<MAXFLOOR; v++)
		    if (g[i][v])
		    {
			int tmp=dis[u]+t[i]*abs(v-u)+60;
			if (dis[v]>tmp)
			{
			    dis[v]=tmp;
			    if (!vis[v])
			    {
				vis[v]=true;
				q.push(v);
			    }
			}
		    }
	vis[u]=false;
    }
}

int main()
{
    while (scanf("%d%d",&n,&k)==2)
    {
	for (int i=0; i<n; i++) scanf("%d",t+i);
	getchar();
	memset(g,0,sizeof(g));
	for (int i=0; i<n; i++)
	{
	    char s[300];
	    gets(s);
	    for (int j=0; j<strlen(s); j++)
		if (isdigit(s[j]))
		{
		    int x;
		    sscanf(&s[j],"%d",&x);
		    while (isdigit(s[j])) j++;
		    g[i][x]=true;
		}
	}
	spfa();
	if (k==0) dis[k]=60;
	if (dis[k]==inf) printf("IMPOSSIBLE\n");
	else printf("%d\n",dis[k]-60);
    }
    return 0;
}
