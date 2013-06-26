#include <cstdio>
#include <cstring>

const int fact[10]={1,1,2,6,24,120,720,5040,40320,362880};

int main()
{
	int n;
	while (scanf("%d", &n)==1&&n>=0)
	{
		if (n==0) puts("NO");
		else
		{
			for (int i=9; i>=0; i--)
				if (n>=fact[i]) n-=fact[i];
			if (n==0) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
