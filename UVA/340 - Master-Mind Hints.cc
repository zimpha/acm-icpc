#include <cstdio>
#include <cstring>

const int MAXN=1005;

int s[MAXN],g[MAXN];
int tmp[MAXN];
int n;

int main()
{
    int cas=0;
    while (scanf("%d",&n)&&n)
    {
	for (int i=0; i<n; i++) scanf("%d",s+i);
	printf("Game %d:\n",++cas);
	while (1)
	{
	    for (int i=0; i<n; i++) scanf("%d",g+i);
	    if (!g[0]) break;
	    int ans1=0,ans2=0;
	    memcpy(tmp,s,sizeof(s));
	    for (int i=0; i<n; i++)
		if (tmp[i]==g[i])
		{
		    ans1++;
		    tmp[i]=g[i]=0;
		}
	    for (int i=0; i<n; i++)
		if (tmp[i])
		{
		    for (int j=0; j<n; j++)
			if (tmp[i]==g[j])
			{
			    ans2++;
			    tmp[i]=g[j]=0;
			    break;
			}
		}
	    printf("    (%d,%d)\n",ans1,ans2);
	}
    }
    return 0;
}
