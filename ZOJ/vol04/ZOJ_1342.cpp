#include <cstdio>
#include <cstring>

const int MAXN=27;
const int SIZE=26;

int dp[SIZE][MAXN];
char code[MAXN];
int n;

int main()
{
	memset(dp,0,sizeof(dp));
	for (int i=0; i<SIZE; i++)
		dp[i][1]=1;
	for (int i=2; i<MAXN; i++)
		for (int j=0; j<SIZE; j++)
			for (int k=j+1; k<SIZE; k++)
				dp[j][i]+=dp[k][i-1];
	while (gets(code))
	{
		bool flag=true;
		n=strlen(code);
		for (int i=0; i<n-1; i++)
			if (code[i]>=code[i+1]) flag=false;
		if (!flag) printf("0\n");
		else
		{
			int ret=0;
			for (int i=0; i<n; i++)
			{
				int digit=code[i]-'a';
				int len=n-i;
				for (int j=0; j<=digit; j++)
					ret+=dp[j][len];
			}
			printf("%d\n", ret);
		}
	}
	return 0;
}
