#include <stdio.h>
#include <math.h>
#define MAXN 201
#define MAXM 50001
#define MAXQ 50001

typedef struct
{
    int x,y,w,c,l;
    char s;
}cmd;

cmd opt[MAXQ];
int f[MAXN][MAXM];
int count[10];
int n,m,q;

void makeset(int n,int m)
{
    int i,j;
    for (i=0;i<=n;i++)
        for (j=0;j<=m;j++)
            f[i][j]=j;
}

int find(int r,int x)
{
    if (x!=f[r][x]) f[r][x]=find(r,f[r][x]);
    return f[r][x];
}

int max(int a,int b)
{
    if (a>b) return a;
    else return b;
}

int min(int a,int b)
{
    if (a<b) return a;
    else return b;
}

void paint(int x,int l,int r,int c)
{
    l=find(x,l);
    while (l<=r)
    {
        count[c]++;
        f[x][l]=find(x,f[x][l+1]);
        l=f[x][l];
    }
}

void Cir(int x,int y, int r,int c)
{
    int i,lower,upper;
    lower=max(0,y-r); upper=min(y+r,m-1);
    paint(x,lower,upper,c);
    for (i=1;i<=r;i++)
    {
        if (x+i>=n&&x-i<0) break;
        while ((y-lower)*(y-lower)+i*i>r*r) lower++;
        while ((y-upper)*(y-upper)+i*i>r*r) upper--;
        if (x+i<n) paint(x+i,lower,upper,c);
        if (x-i>=0) paint(x-i,lower,upper,c);
    }
}

void Dia(int x,int y,int r,int c)
{
    int i,lower,upper;
    lower=max(0,y-r); upper=min(y+r,m-1);
    paint(x,lower,upper,c);
    for (i=1;i<=r;i++)
    {
        if (x+i>=n&&x-i<0) break;
        while (y-lower+i>r) lower++;
        while (upper-y+i>r) upper--;
        if (x+i<n) paint(x+i,lower,upper,c);
        if (x-i>=0) paint(x-i,lower,upper,c);
    }
}

void Rec(int x,int y, int l,int w,int c)
{
    int i;
    for (i=x;i<n&&i<x+l;i++)
        paint(i,y,min(m-1,y+w-1),c);
}

void Tri(int x,int y, int w,int c)
{
    for (w=w/2;x<n&&w/2>=0;x++,w--)
        paint(x,max(0,y-w),min(m-1,y+w),c);
}

int main()
{
    int i;
    while (scanf("%d%d%d",&n,&m,&q)!=EOF)
    {
        memset(count,0,sizeof(count));
        makeset(n,m);
        for (i=1;i<=q;i++)
        {
            char name[10];
            scanf("%s%d%d",name,&opt[i].x,&opt[i].y);
            opt[i].s=name[0];
            switch (opt[i].s)
            {
                case 'C':scanf("%d%d",&opt[i].l,&opt[i].c); break;
                case 'D':scanf("%d%d",&opt[i].l,&opt[i].c); break;
                case 'R':scanf("%d%d%d",&opt[i].l,&opt[i].w,&opt[i].c); break;
                case 'T':scanf("%d%d",&opt[i].w,&opt[i].c); break;
            }
        }
        for (i=q;i>0;i--)
        {
            switch (opt[i].s)
            {
                case 'C':Cir(opt[i].x,opt[i].y,opt[i].l,opt[i].c); break;
                case 'D':Dia(opt[i].x,opt[i].y,opt[i].l,opt[i].c); break;
                case 'R':Rec(opt[i].x,opt[i].y,opt[i].l,opt[i].w,opt[i].c); break;
                case 'T':Tri(opt[i].x,opt[i].y,opt[i].w,opt[i].c); break;
            }
        }
        for (i=1;i<=9;i++)
            if (i==9) printf("%d\n",count[i]);
            else printf("%d ",count[i]);
    }
    return 0;
}
