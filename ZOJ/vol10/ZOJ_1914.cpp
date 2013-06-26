#include <cstdio>
#include <cmath>
#include <algorithm>

const int MAXN=505;
const int MAXM=130000;

struct node
{
    int u,v,w;
};

node e[MAXM];
int f[MAXN],x[MAXN],y[MAXN];
int n,s,m;

bool cmp(node a,node b)
{
    return (a.w<b.w);
}

void initial()
{
    for (int i=0; i<=n; i++)
	f[i]=i;
}

int find(int x)
{
    if (x!=f[x]) f[x]=find(f[x]);
    return f[x];
}

void Union(int x,int y)
{
    x=find(x); y=find(y);
    if (x==y) return;
    f[x]=y; n--;
}

int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
	scanf("%d%d",&s,&n);
	m=0; initial();
	for (int i=1; i<=n; i++)
	{
	    scanf("%d%d",x+i,y+i);
	    for (int j=1; j<i; j++)
	    {
		e[m].u=i; e[m].v=j;
		e[m].w=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
		m++;
	    }
	}
	std::sort(e,e+m,cmp);
	double ans;
	for (int i=0; i<m; i++)
	{
	    Union(e[i].u,e[i].v);
	    if (n==s) 
	    {
		ans=e[i].w;
		break;
	    }
	}
	printf("%.2f\n",sqrt(ans));
    }
    return 0;
}
