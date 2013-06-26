#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 21

using namespace std;

int f[1<<MAXN];
int x[MAXN];
int n;

int state(int s,int x)
{
    int j,k;
    for (k=x;k<MAXN;k+=x)
        s&=~(1<<k);
    for (j=2;j<MAXN;j++)
    {
        if (s&(1<<j))
        {
            for (k=x;k<=j-2;k+=x)
                if (!(s&(1<<(j-k))))
                {
                    s&=~(1<<j);
                    break;
                }
        }
    }
    return s;
}

int dfs(int s)
{
    int i,tmp;
    if (f[s]!=-1) return f[s];
    for (i=0;i<n;i++)
    {
        if (s&(1<<x[i]))
        {
            tmp=state(s,x[i]);
            if (!dfs(tmp)) return f[s]=1;
        }
    }
    return f[s]=0;
}

int main()
{
    int test;
    int s,i,j;

    memset(f,-1,sizeof(f));
    f[0]=0;
    scanf("%d",&test);
    for (j=1;j<=test;j++)
    {
        printf("Scenario #%d:\n",j);
        scanf("%d",&n);
        for (s=i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
            s|=1<<x[i];
        }
        sort(x,x+n);
        if (!dfs(s)) printf("There is no winning move.\n");
        else
        {
            printf("The winning moves are:");
            for (i=0;i<n;i++)
                if (!dfs(state(s,x[i]))) printf(" %d",x[i]);
            printf(".\n");
        }
        printf("\n");
    }
    return 0;
}
