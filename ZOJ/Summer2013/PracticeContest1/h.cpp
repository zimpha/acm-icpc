#include <cstdio>
#include <cstring>

const int MAXN=55;
const int MAXM=2550;

char word[MAXN];
char str[MAXM];
int n, m;

bool check(int x)
{
	int len=strlen(word);
	int i=x, j=0;
	while (1)
	{
		if (i>=m||j>=len) return true;
		if (str[i]==word[j]) i++, j++;
		else return false;
	}
	return true;
}

void cover(int x)
{
	int len=strlen(word);
	for (int i=0; i<len; i++)
		str[x+i]=word[i];
	if (x+len>m) str[x+len]='\0';
	m=strlen(str);
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		scanf("%s", str);
		m=strlen(str);
		int x=0;
		for (int i=1; i<n; i++)
		{
			scanf("%s", word);
			for (int j=x; j<=m; j++)
			{
				if (check(j))
				{
					cover(j);
					x=j;
					break;
				}
			}
		}
		printf("%d\n", m);
	}
	return 0;
}
