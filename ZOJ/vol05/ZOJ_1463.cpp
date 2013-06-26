#include <cstdio>
#include <cstring>

const int MAXN=105;
const int inf=1000000;

int f[MAXN][MAXN];
int p[MAXN][MAXN];
char s[MAXN];
int n;

void init()
{
	memset(s,0,sizeof(s));
	scanf("%s", s+1);
	n=strlen(s+1);
}

void dp()
{
	memset(p,0,sizeof(p));
	memset(f,0,sizeof(f));
	for (int i=n; i>0; i--)
		for (int j=i; j<=n; j++)
		{
			f[i][j]=inf;
			// s[i] and s[j] match
			if (i<n&&j>1&&(s[i]=='('&&s[j]==')'||s[i]=='['&&s[j]==']'))
			{
				if (f[i+1][j-1]<f[i][j])
				{
					f[i][j]=f[i+1][j-1];
					p[i][j]=-1;
				}
			}
			// s[i] is left bracket
			if (s[i]=='('||s[i]=='[')
			{
				if (f[i+1][j]+1<f[i][j])
				{
					f[i][j]=f[i+1][j]+1;
					p[i][j]=-2;
				}
			}
			// s[j] is right bracket
			if (s[j]==')'||s[j]==']')
			{
				if (f[i][j-1]+1<f[i][j])
				{
					f[i][j]=f[i][j-1]+1;
					p[i][j]=-3;
				}
			}
			// split s[i..j]
			for (int k=i-1; k<=j; k++)
			{
				if (f[i][k]+f[k+1][j]<f[i][j])
				{
					f[i][j]=f[i][k]+f[k+1][j];
					p[i][j]=k;
				}
			}
		}
}

char opp(char c)
{
	switch (c)
	{
		case '(': return ')';
		case ')': return '(';
		case '[': return ']';
		case ']': return '[';
	}
}

void print(int i, int j)
{
	if (i>j) return;
	if (p[i][j]==-1)
	{
		putchar(s[i]);
		print(i+1,j-1);
		putchar(s[j]);
	}
	else if (p[i][j]==-2)
	{
		putchar(s[i]);
		print(i+1,j);
		putchar(opp(s[i]));
	}
	else if (p[i][j]==-3)
	{
		putchar(opp(s[j]));
		print(i,j-1);
		putchar(s[j]);
	}
	else
	{
		print(i,p[i][j]);
		print(p[i][j]+1,j);
	}
}

int main()
{
	int test;
	scanf("%d\n", &test);
	while (test--)
	{
		init();
		dp();
		print(1,n);
		printf("\n");
		if (test) puts("");
	}
	return 0;
}
