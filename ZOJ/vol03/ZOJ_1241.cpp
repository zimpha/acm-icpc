#include <cmath>
#include <cstdio>

int main()
{
	int a, b, c;
	int cas=0;
	while (scanf("%d%d%d", &a, &b, &c)==3&&a)
	{
		printf("Triangle #%d\n", ++cas);
		if (a==-1)
		{
			if (c*c<=b*b) puts("Impossible.");
			else printf("a = %.3f\n", sqrt((double)c*c-b*b));
		}
		if (b==-1)
		{
			if (c*c<=a*a) puts("Impossible.");
			else printf("b = %.3f\n", sqrt((double)c*c-a*a));
		}
		if (c==-1)
		{
			printf("c = %.3f\n", sqrt((double)a*a+b*b));
		}
		puts("");
	}
	return 0;
}
