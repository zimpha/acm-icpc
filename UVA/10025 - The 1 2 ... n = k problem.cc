#include <cstdio>
#include <cmath>

int get(int k)
{
    int l=1,r=sqrt(k*2)+2;
    while (l<=r)
    {
	int m=(l+r)/2;
	if (m*(m+1)/2>=k) r=m-1;
	else l=m+1;
    }
    return r+1;
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
	int k;
	scanf("%d",&k);
	if (k<0) k=-k;
	int n=get(k);
	while ((n*(n+1)/2-k)%2) n++;
	printf("%d\n",n);
	if (test) printf("\n");
    }
    return 0;
}
