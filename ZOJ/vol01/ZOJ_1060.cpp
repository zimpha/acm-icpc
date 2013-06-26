#include <cstdio>
#include <cstring>

const int MAXN=30;

struct node
{
    int v;
    node *next;
};

node *head[MAXN];
int que[MAXN];
int deg[MAXN];
int n,m;

int Topology()
{
    int h=0,t=0,tag=1;
    int d[MAXN];
    memcpy(d,deg,sizeof(deg));
    for (int i=0; i<n; i++)
	if (d[i]==0) que[t++]=i;
    while (h<t)
    {
	if (t-h!=1) tag=0;
	int u=que[h++];
	for (node *p=head[u]; p; p=p->next)
	{
	    int v=p->v; d[v]--;
	    if (d[v]==0) que[t++]=v;
	}
    }
    if (t!=n) tag=-1;
    return tag;
}

void addedge(int u,int v)
{
    node *p=new(node); deg[v]++;
    p->v=v; p->next=head[u]; head[u]=p;
}

int main()
{
    while (scanf("%d%d",&n,&m)==2&&n)
    {
	bool flag=false;
	memset(head,0,sizeof(head));
	memset(deg,0,sizeof(deg));
	for (int i=1; i<=m; i++)
	{
	    char u,v;
	    getchar();
	    scanf("%c<%c",&u,&v);
	    if (flag) continue;
	    addedge(u-'A',v-'A');
	    int tmp=Topology();
	    if (tmp==-1)
	    {
		printf("Inconsistency found after %d relations.\n",i);
		flag=true;
	    }
	    else if (tmp==1)
	    {
		printf("Sorted sequence determined after %d relations: ",i);
		for (int j=0; j<n; j++)
		    printf("%c",que[j]+'A');
		printf(".\n");
		flag=true;
	    }
	}
	if (!flag) printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
