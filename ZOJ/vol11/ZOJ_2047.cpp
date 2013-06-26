#include <cstdio>
#include <cstring>

const int SIZE=15;

char now[SIZE], pre[SIZE];

int lcs(char *a, char *b)
{
	int l;
	if (strlen(a)>strlen(b)) l=strlen(b);
	else l=strlen(a);
	for (int i=0; i<l; i++)
		if (a[i]!=b[i]) return i;
	return l;
}

int main()
{
	int test;
	scanf("%d\n\n", &test);
	while (test--)
	{
		int space;
		memset(pre, 0, sizeof(pre));
		while (gets(now)&&strlen(now))
		{
			if (now[0]==pre[0])
			{
				int len=lcs(now, pre);
				if (len<space) space=len;
				for (int i=1; i<=space; i++) putchar(' ');
				puts(now); space++;
			}
			else 
			{
				space=1;
				puts(now);
			}
			strcpy(pre, now);
		}
		if (test) puts("");
	}
	return 0;
}
