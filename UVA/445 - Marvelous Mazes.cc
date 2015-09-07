#include <cstdio>
#include <cstring>
#define SIZE 135

int main()
{
	int times=0;
	char st;
	while (scanf("%c",&st)!=EOF)
	{
		if (st=='b')
		{
			for (int j=0;j<times;j++)
				printf(" ");
			times=0;
		}
		else if (st>='A'&&st<='Z')
		{
			for (int j=0;j<times;j++)
				printf("%c",st);
			times=0;
		}
		else if (st>='0'&&st<='9')
		{
			times+=st-'0';
		}
		else if (st=='*') 
		{
			for (int j=0;j<times;j++)
				printf("*");
			times=0;;
		}
		else
		{		
			times=0;
			printf("\n");
		}
	}
	return 0;
}
