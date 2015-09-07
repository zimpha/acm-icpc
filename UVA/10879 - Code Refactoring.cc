#include <cstdio>

int main()
{
    int test;
    scanf("%d",&test);
    for (int cas=1; cas<=test; cas++)
    {
	int k,count=0;
	scanf("%d",&k);
	printf("Case #%d: %d",cas,k);
	for (int i=2; i<k; i++)
	    if (k%i==0)
	    {
		printf(" = %d * %d",i,k/i);
		count++;
		if (count==2) break;
	    }
	printf("\n");
    }
    return 0;
}
