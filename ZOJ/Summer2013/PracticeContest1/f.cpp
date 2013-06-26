#include <cstdio>
#include <cstring>

const int MAXN=2000010;

bool vis[MAXN];
double dp[MAXN];
int nr, nb;

double calc(int r, int b)
{
	int id=r*(nb+1)+b;
	if (vis[id]) return dp[id];
	vis[id]=1;
	dp[id]=(double)r/(double)(r+b)*calc(r-1,b-1);
	if (b>1) dp[id]+=(double)b/(double)(r+b)*calc(r,b-2);
	return dp[id];
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d%d", &nr, &nb);
		if (nr*(nb+1)+nb>=2000000) printf("%.15f\n", 0.0);
		else
		{
			memset(vis,0,sizeof(vis));
			for (int i=0; i<=nb; i++)
			{
				dp[i]=1;
				vis[i]=1;
			}
			for (int i=1; i<=nr; i++)
			{
				dp[i*(nb+1)]=0;
				vis[i*(nb+1)]=1;
			}
			printf("%.15f\n", calc(nr,nb));
		}
	}
	return 0;
}
