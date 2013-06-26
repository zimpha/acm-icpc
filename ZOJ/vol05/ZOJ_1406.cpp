#include <cstdio>
#include <cstdlib>
#define MAXN 30
#define MAXM 1000

typedef struct
{
    int u,v,w;
}node;

int f[MAXN];
node edge[MAXM];
int n,m,ans;

int cmp(void const *a,void const *b)
{
    return ((*(node *)a).w-(*(node *)b).w);
}

int find(int x)
{
    if (x!=f[x]) f[x]=find(f[x]);
    return f[x];
}

int main()
{
    int i,u,v,k,j,w;
    char tmp;
    while (scanf("%d",&n)==1&&n)
    {
        m=0;
        for (i=1;i<=n;i++) f[i]=i;
        for (i=1;i<n;i++)
        {
            scanf("\n%c%d",&tmp,&k);
            u=tmp-'A'+1;
            for (j=0;j<k;j++)
            {
                scanf(" %c%d",&tmp,&w);
                v=tmp-'A'+1;
                edge[m].u=u; edge[m].v=v;
                edge[m].w=w; m++;
            }
        }
        qsort(edge,m,sizeof(edge[0]),cmp);
        ans=0;
        for (i=0;i<m;i++)
        {
            u=find(edge[i].u); v=find(edge[i].v);
            if (u!=v)
            {
                ans+=edge[i].w;
                f[u]=v;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

