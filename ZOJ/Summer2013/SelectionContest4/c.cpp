#include <cstdio>
#include <cstring>

const int MAXN=100;

bool dp[MAXN][10][10];
char str[MAXN];
int n;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%s", str);
		n=strlen(str);
		memset(dp, 0, sizeof(dp));
		dp[0][0][0]=1;
		bool ugly=false, nice=false;
		for (int i=0; i<n; i++)
			for (int j=0; j<3; j++)
				for (int k=0; k<5; k++)
				{
					if (!dp[i][j][k]) continue;
					bool isvo=false, isco=false;
					if (strchr("AEIOU", str[i])!=NULL||str[i]=='?') isvo=true;
					if (strchr("AEIOU", str[i])==NULL||str[i]=='?') isco=true;
					if (isvo)
					{
						if (j>=2) ugly=true;
						else dp[i+1][j+1][0]=true;
					}
					if (isco)
					{
						if (k>=4) ugly=true;
						else dp[i+1][0][k+1]=true;
					}
				}
		for (int j=0; j<3; j++)
			for (int k=0; k<5; k++)
				nice|=dp[n][j][k];
		if (nice)
			if (ugly) puts("UNKNOWN");
			else puts("NICE");
		else puts("UGLY");
	}
	return 0;
}
