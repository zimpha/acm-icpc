#include <cstdio>
#include <cstring>
#define N 100010

int f[N],v[N];

void UFsets()
{
    int i;
    for (i=1;i<N;i++)
        f[i]=i;
}

int find(int x)
{
    if (x!=f[x]) f[x]=find(f[x]);
    return f[x];
}

int main()
{
    int x,y,flag,i;
    int test=0;
    while (scanf("%d%d",&x,&y)!=EOF)
    {
        test++;
        if (x==-1) return 0;
        flag=1;
        UFsets();
        memset(v,0,sizeof(v));
        while (x)
        {
            v[x]=v[y]=1;
            x=find(x); y=find(y);
            if (x==y) flag=0;
            else f[x]=y;
            scanf("%d%d",&x,&y);
        }
        for (i=1;i<N;i++)
            if (v[i])
            {
                x=find(i);
                break;
            }
        for (i=1;i<N;i++)
            if (v[i])
            {
                y=find(i);
                if (x!=y) { flag=0; break; }
            }
        if (flag) printf("Case %d is a tree.\n",test);
        else printf("Case %d is not a tree.\n",test);
    }
    return 0;
}
