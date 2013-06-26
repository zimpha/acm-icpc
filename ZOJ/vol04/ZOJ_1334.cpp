#include <cstdio>
#include <cstring>

char a[10];
int n, m;

int main()
{
	while (scanf("%s", a)==1)
	{
		scanf("%d%d", &n, &m);
		int tmp=0;
		for (int i=0; a[i]; i++)
		{
			int x=0;
			if (a[i]>='0'&&a[i]<='9') x=a[i]-'0';
			else x=a[i]-'A'+10;
			tmp=tmp*n+x;
		}
		n=0;
		while (tmp)
		{
			a[n++]=tmp%m;
			tmp/=m;
		}
		if (n>7) puts("  ERROR");
		else
		{
			for (int i=1; i<=7-n; i++) putchar(' ');
			for (int i=n-1; i>=0; i--)
				if (a[i]<10) putchar(a[i]+'0');
				else putchar(a[i]+'A'-10);
			puts("");
		}
	}
	return 0;
}
