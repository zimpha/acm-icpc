#include <cstdio>
#include <cstring>

const int MAXN=1005;
const int SIZE=25;

typedef char string[SIZE];

string word[MAXN];
int n;

int lcs(string a, string b)
{
	int len=0;
	while (*a&&*b)
	{
		if (*a==*b) len++;
		else break;
		a++; b++;
	}
	return len;
}

int main()
{
	int test;
	scanf("%d\n\n", &test);
	while (test--)
	{
	n=0;
	while (gets(word[n])&&word[n][0]!='\0')
		n++;
	for (int i=0; i<n; i++)
	{
		printf("%s ", word[i]);
		int ret=0;
		for (int j=0; j<n; j++)
			if (i!=j&&lcs(word[i],word[j])>ret)
				ret=lcs(word[i],word[j]);
		for (int j=0; j<=ret&&j<strlen(word[i]); j++)
			putchar(word[i][j]);
		puts("");
	}
	if (test) puts("");
	}
	return 0;
}
