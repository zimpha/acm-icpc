#include <cstdio>
#include <cstring>

const int MAXN=10000;

struct node
{
    int val;
    node *l, *r;
};

int sum[MAXN];
int max,min;
node *T;

node *new_node()
{
    node *p=new(node);
    p->val=0;
    p->l=p->r=NULL;
    return p;
}

node *build(int level)
{
    node *p=new_node();
    scanf("%d",&p->val);
    if (p->val==-1) return NULL;
    p->l=build(level-1);
    p->r=build(level+1);
    if (level>max) max=level;
    if (level<min) min=level;
    return p;
}

void dfs(node *T, int level)
{
    sum[level-min]+=T->val;
    if (T->l) dfs(T->l,level-1);
    if (T->r) dfs(T->r,level+1);
}

int main()
{
    int cas=0;
    while (1)
    {
	min=max=0;
	T=build(0);
	if (T==NULL) break;
	memset(sum,0,sizeof(sum));
	dfs(T,0);
	printf("Case %d:\n",++cas);
	for (int i=0; i<=max-min; i++)
	    printf("%d%c",sum[i],(i==max-min)?'\n':' ');
	printf("\n");
    }
    return 0;
}
