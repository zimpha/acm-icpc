#include <cstring>
#include <cstdio>
#define SIZE 105

int main()
{
	char a[SIZE][SIZE];
	int n=0,m=0;
	for (int i=0;i<SIZE;i++)
		memset(a[i],' ',sizeof(a[i]));
	while (gets(a[n]))
	{
		if (m<strlen(a[n])) m=strlen(a[n]);
		n++;
	}
	for (int i=0;i<m;i++)
	{
		for (int j=n-1;j>=0;j--)
		{
			if (i>=strlen(a[j])) printf(" ");
			else printf("%c",a[j][i]);
		}
		printf("\n");
	}
	return 0;
}
