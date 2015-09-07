#include <cstdio>

int main()
{
	int test;
	scanf("%d",&test);
	while (test--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for (int k=1;k<=m;k++)
		{
			for (int i=1;i<=n;i++)
			{
				for (int j=0;j<i;j++)
					printf("%d",i);
				printf("\n");
			}
			for (int i=n-1;i>0;i--)
			{
				for (int j=0;j<i;j++)
					printf("%d",i);
				printf("\n");
			}
			if (k<m) printf("\n");
		}
		if (test) printf("\n");
	}
	return 0;
}
