#include <cstdio>
#include <cstdlib>

const int MAXN=50;

int h[MAXN];
int n;

int main()
{
    int cas=0;
    while (scanf("%d",&n)==1&&n)
    {
	int sum=0;
	for (int i=0; i<n; i++) 
	{
	    scanf("%d",h+i);
	    sum+=h[i];
	}
	int ave=sum/n;
	sum=0;
	for (int i=0; i<n; i++)
	    sum+=abs(ave-h[i]);
	printf("Set #%d\n",++cas);
	printf("The minimum number of moves is %d.\n\n",sum/2);
    }
    return 0;
}
