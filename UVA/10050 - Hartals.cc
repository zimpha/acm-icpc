#include <cstdio>
#include <cstring>

const int MAXN=3655;

bool hash[MAXN];

int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
	int n,p,ans=0;
	scanf("%d%d",&n,&p);
	memset(hash,0,sizeof(hash));
	while (p--)
	{
	    int x;
	    scanf("%d",&x);
	    for (int i=x; i<=n; i+=x)
		if (!hash[i])
		{
		    if (((i+1)%7)&&(i%7)) ans++;
		    hash[i]=true;
		}
	}
	printf("%d\n",ans);
    }
    return 0;
}
