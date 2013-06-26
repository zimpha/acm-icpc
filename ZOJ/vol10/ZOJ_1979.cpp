#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAXN 5005

using std::cin;
using std::cout;
using std::endl;

struct edge
{
    int link;
    edge *next;
};

edge *head[MAXN];
bool instack[MAXN];
int stack[MAXN],oud[MAXN],col[MAXN];
int dfn[MAXN],low[MAXN],ans[MAXN];
int n,m,cnt,top,num;

void tarjan(int u)
{
    int v;
    cnt++;
    low[u]=dfn[u]=cnt;
    instack[u]=true;
    stack[++top]=u;
    for (edge *e=head[u];e;e=e->next)
    {
        v=e->link;
        if (!dfn[v])
        {
            tarjan(v);
            if (low[v]<low[u])
                low[u]=low[v];
        }
        else
            if (instack[v]&&dfn[v]<low[u])
                low[u]=dfn[v];
    }
    if (dfn[u]==low[u])
    {
        num++;
        do
        {
            v=stack[top--];
            instack[v]=false;
            col[v]=num;
        }while (u!=v);
    }
}

int main()
{
    int u,v,i,j;
    edge *p;
    while ((cin>>n)&&n)
    {
        cin>>m;
        for (i=1;i<=n;i++)
        {
            instack[i]=0;
            head[i]=NULL;
        }
        for (i=0;i<m;i++)
        {
            cin>>u>>v;
            p=new(edge);
            p->link=v;
            p->next=head[u];
            head[u]=p;
        }
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        top=num=cnt=0;
        for (i=1;i<=n;i++)
            if (!dfn[i])
            {
                tarjan(i);
            }
        memset(oud,0,sizeof(oud));
        for (u=1;u<=n;u++)
        {
            for (edge *e=head[u];e;e=e->next)
            {
                v=e->link;
                if (col[u]!=col[v]) oud[col[u]]++;
            }
        }
        memset(instack,0,sizeof(instack));
        for (i=1;i<=num;i++)
            if (oud[i]==0) instack[i]=1;
        for (cnt=0,i=1;i<=n;i++)
            if (instack[col[i]])
                    ans[++cnt]=i;
        for (i=1;i<=cnt;i++)
            if (i==cnt) cout<<ans[i];
            else cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
