#include <cstdio>
#include <cstring>

const int MAXN=55;

typedef char str[MAXN];

str word[MAXN];
int ans[MAXN];
int n;

bool prefix(str a, str b)
{
	if (strlen(a)>strlen(b)) return false;
	int len=strlen(a);
	for (int i=0; i<len; i++)
		if (a[i]!=b[i]) return false;
	return true;
}

bool check(int cur, int len)
{
	str pre;
	for (int i=0; i<=len; i++)
		pre[i]=word[cur][i];
	pre[++len]='\0';
	for (int i=0; i<n; i++)
		if (cur!=i&&prefix(pre,word[i])) return false;
	return true;
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		for (int i=0; i<n; i++)
			scanf("%s", word[i]);
		for (int i=0; i<n; i++)
		{
			int m=strlen(word[i]);
			for (int j=0; j<m; j++)
				if (check(i,j))
				{
					ans[i]=j;
					break;
				}
		}
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<=ans[i]; j++)
				putchar(word[i][j]);
			if (i==n-1) putchar('\n');
			else putchar(' ');
		}
	}
	return 0;
}
