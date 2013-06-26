#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define MAXN 50010

struct node
{
    char l[100];
    int p;
}a[MAXN];
int f[MAXN][16];
int n;

int cmp(node a,node b)
{
    return (strcmp(a.l,b.l)<0);
}

int get_root(int l,int r)
{
    int k;
    k=floor(log(1.0*(r-l+1))/log(2.0));
    if (a[f[l][k]].p>a[f[r-(1<<k)+1][k]].p) return f[l][k];
    else return f[r-(1<<k)+1][k];
}

void construct(int l,int r)
{
    int root;
    if (l>r) return;
    root=get_root(l,r);
    printf("(");
    construct(l,root-1);
    printf("%s/%d",a[root].l,a[root].p);
    construct(root+1,r);
    printf(")");
}

int main()
{
    int i,j;
    while (scanf("%d",&n)!=EOF&&n)
    {
        for (i=1;i<=n;i++)
            scanf("%*[ ]%[a-z]/%d",a[i].l,&a[i].p);
        std::sort(a+1,a+n+1,cmp);

        for (i=1;i<=n;i++) f[i][0]=i;

        for (j=1;(1<<j)<=n;j++)
            for (i=1;i<=n-(1<<j)+1;i++)
                if (a[f[i][j-1]].p>a[f[i+(1<<j-1)][j-1]].p) f[i][j]=f[i][j-1];
                else f[i][j]=f[i+(1<<j-1)][j-1];

        construct(1,n);
        printf("\n");
    }
}
