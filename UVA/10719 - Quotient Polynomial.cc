#include <cstdio>
#include <cstring>

const int MAXN=10005;

int p[MAXN],q[MAXN];
int n,k;

int main()
{
    while (scanf("%d",&k)==1)
    {
	n=0;
	memset(p,0,sizeof(p));
	memset(q,0,sizeof(q));
	while (1)
	{
	    scanf("%d",p+n);
	    n++;
	    char c=getchar();
	    if (c=='\n') break;
	}
	for (int i=0; i<n; i++)
	{
	    q[i]=p[i];
	    p[i+1]-=q[i]*(-k);
	}
	printf("q(x):");
	for (int i=0; i<n-1; i++)
	    printf(" %d",q[i]);
	printf("\nr = %d\n\n",p[n-1]);
    }
    return 0;
}
