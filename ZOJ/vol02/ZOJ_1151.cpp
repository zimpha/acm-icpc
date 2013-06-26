#include <cctype>
#include <cstdio>
#include <cstring>

char str[100000];

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		int n, m=0;
		char c;
		scanf("%d\n", &n);
		while ((c=getchar()))
		{
			if (isalpha(c)) str[m++]=c;
			else
			{
				while (m--) putchar(str[m]);
				putchar(c); m=0;
				if (c=='\n') n--;
			}
			if (!n) break;
		}
		if (test) puts("");
	}
	return 0;
}
