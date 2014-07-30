#include <cstdio>
#include <cstring>
#include <cstdlib>

int main()
{
	int A, B, N;
	while (scanf("%d%d%d", &A, &B, &N)==3)
	{
		if (B==N)
		{
			puts("fill B");
			puts("success");
			continue;
		}
		if (A==N)
		{
			puts("fill A");
			puts("pour A B");
			puts("success");
			continue;
		}
		int tmp=0;
		while (tmp!=N)
		{
			puts("fill A"); puts("pour A B");
			tmp+=A;
			if (tmp>B)
			{
				tmp-=B;
				puts("empty B"); puts("pour A B");
			}
		}
		puts("success");
	}
	return 0;
}
