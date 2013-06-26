#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define MAXN 205
#define MAXM 40000

using namespace std;

struct node
{
    int u,v,w;
};

int x[MAXN],y[MAXN];
node e[MAXM];
int f[MAXN];
int n,m;

int dis(int i,int j)
{
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

bool cmp(node a,node b)
{
    return (a.w<b.w);
}

int find(int x)
{
    if (x!=f[x]) f[x]=find(f[x]);
    return f[x];
}

int main()
{
    int test=0;

    while (cin>>n)
    {
        if (!n) break;
        cout<<"Scenario #"<<++test<<endl;
        for (int i=0;i<n;i++)
            cin>>x[i]>>y[i];
        m=0;
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
            e[m++]=(node){i,j,dis(i,j)};
        sort(e,e+m,cmp);

        int i;
        for (i=0;i<n;i++) f[i]=i;
        for (i=0;i<m;i++)
        {
            int u=find(e[i].u);
            int v=find(e[i].v);
            if (u!=v) f[u]=v;
            if (find(0)==find(1)) break;
        }
        cout<<"Frog Distance = ";
        printf("%.3f\n",sqrt(e[i].w));
        cout<<endl;
    }
    return 0;
}
