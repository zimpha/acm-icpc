#include <cstdio>

const int MAXN=55;

int train[MAXN];
int n;

int main()
{
    int cas;
    scanf("%d",&cas);
    while (cas--)
    {
	int ans=0;
	scanf("%d",&n);
	for (int i=0; i<n; i++)
	{
	    scanf("%d",train+i);
	    for (int j=0; j<i; j++)
		if (train[i]<train[j]) ans++;
	}
	printf("Optimal train swapping takes %d swaps.\n",ans);
    }
    return 0;
}
