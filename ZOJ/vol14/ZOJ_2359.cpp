#include <cstdio>
#include <cstring>

const int MAXN=1005;

bool g[MAXN][MAXN];
int ans[MAXN];
int n,cnt;

void insert(int x,int id)
{
    for (int i=cnt+1; i>id; i--) ans[i]=ans[i-1];
    ans[id]=x; cnt++;
}

int main()
{
    while (scanf("%d",&n)==1)
    {
	for (int i=1; i<=n; i++)
	{
	    for (int j=1; j<=n; j++)
	    {
		getchar();
		char c=getchar();
		g[i][j]=(c=='1');
	    }
	}
	cnt=1; ans[1]=1;
	for (int i=2; i<=n; i++)
	{
	    if (g[i][ans[1]]) insert(i,1);
	    else
	    {
		for (int j=1; j<cnt; j++)
		    if (g[ans[j]][i]&&g[i][ans[j+1]])
		    {
			insert(i,j+1);
			break;
		    }
		if (cnt==i-1) insert(i,cnt+1);
	    }
	}
	printf("1\n%d\n",n);
	for (int i=1; i<=n; i++)
	    printf("%d%c",ans[i],(i==n)?'\n':' ');
    }
    return 0;
}
