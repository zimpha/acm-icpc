#include <stdio.h>
#include <string.h>
#define MAXN 50010

int head[MAXN],next[MAXN*2],link[MAXN*2];
int vis[MAXN];
int dep[MAXN],f[MAXN][20];
int n,m;
int u,v,tmp;
int aa,bb,cc;

void dfs(int u)
{
    int now;
    now=head[u];
    while (now>0)
    {
          if (!vis[link[now]])
          {
              vis[link[now]]=1;
              f[link[now]][0]=u;
              dep[link[now]]=dep[u]+1;
              dfs(link[now]);
          }
          now=next[now];
    }
}

void build()
{
    int i,j;
    for (j=1;1<<j<=n;j++)
        for (i=0;i<n;i++)
            if (f[i][j-1]>=0)
                f[i][j]=f[f[i][j-1]][j-1];
}

int lca(int u,int v)
{
    int i, log;
    if (dep[u]<dep[v])
        i=u, u=v, v=i;
    for (log=1;1<<log<=n;log++);
    for (i=log;i>=0;i--)
        if (dep[u]-(1<<i)>=dep[v])
            u=f[u][i];
    if (u==v) return u;
    for (i=log;i>=0;i--)
        if (f[u][i]!=-1&&f[u][i]!=f[v][i])
            u=f[u][i],v=f[v][i];
    return f[u][0];
}

void addedge(int u, int v)
{
     next[++m]=head[u];
     head[u]=m;
     link[m]=v;
}

int main()
{
int i,test=0;
    while (scanf("%d",&n)!=EOF)
    {
		if (test++) printf("\n");
        m=0;
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        memset(f,-1,sizeof(f));
        for (i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
        }
        dep[0]=0; vis[0]=1;
        dfs(0);
        build();
        scanf("%d",&m);
		printf("Case %d:\n",test);
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&tmp);
            aa=lca(u,v);
            bb=lca(u,tmp);
            cc=lca(v,tmp);
            if ((bb==tmp||cc==tmp)&&lca(aa,tmp)==aa) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
