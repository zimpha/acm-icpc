#include <cstdio>
#include <cstring>

const int MAXN=10005;

int f[MAXN],val[MAXN];
int n;

int find(int x)
{
    if (x!=f[x])
    {
	int tmp=f[x];
	f[x]=find(f[x]);
	val[x]^=val[tmp];
    }
    return f[x];
}

void Union(int x,int y,int d)
{
    int fx=find(x),fy=find(y);
    f[fx]=fy;
    val[fx]=val[x]^val[y]^d;
}

int Judge(int x,int y)
{
    int fx=find(x),fy=find(y);
    if (fx!=fy) return -1;
    if (val[x]==val[y]) return 1;
    else return 0;
}

int main()
{
    scanf("%d",&n);
    for (int i=0; i<=n; i++)
    {
	f[i]=i;
	val[i]=0;
    }
    int c,x,y;
    while (scanf("%d%d%d",&c,&x,&y)&&c)
    {
	switch (c)
	{
	    case 1:
		if (Judge(x,y)==0) printf("-1\n");
		else Union(x,y,0); 
		break;
	    case 2:
		if (Judge(x,y)==1) printf("-1\n");
		else Union(x,y,1);
		break;
	    case 3:
		if (Judge(x,y)==1) printf("1\n");
		else printf("0\n");
		break;
	    case 4:
		if (Judge(x,y)==0) printf("1\n");
		else printf("0\n");
		break;
	}
    }
    return 0;
}
