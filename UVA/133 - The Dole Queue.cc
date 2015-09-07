#include <cstdio>
#include <cstring>

const int MAXN=25;

int que[MAXN];

int main()
{
    int n,m,k;
    while (scanf("%d%d%d",&n,&k,&m)==3&&n)
    {
	memset(que,0,sizeof(que));
	for (int i=1; i<=n; i++)
	    que[i]=i;
	int head=1, tail=n;
	int sum=0, count;
	while (sum<n)
	{
	    count=0;
	    while (1)
	    {
		if (head>n) head=1;
		if (que[head]) count++;
		if (count==k) break;
		head++;
	    }
	    count=0;
	    while (1)
	    {
		if (tail<1) tail=n;
		if (que[tail]) count++;
		if (count==m) break;
		tail--;
	    }
	    if (que[head]==que[tail])
	    {
		printf("%3d",que[head]);
		sum++;
	    }
	    else
	    {
		printf("%3d%3d",que[head],que[tail]);
		sum+=2;
	    }
	    if (sum<n) printf(",");
	    que[head]=que[tail]=0;
	}
	printf("\n");
    }
    return 0;
}
