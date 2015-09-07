#include <cstdio>

int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
	int n,m;
	scanf("%d%d",&n,&m);
	if ((n-2)%3==0) n=(n-2)/3;
	else n=(n-2)/3+1;
	if ((m-2)%3==0) m=(m-2)/3;
	else m=(m-2)/3+1;
	printf("%d\n",n*m);
    }
    return 0;
}
