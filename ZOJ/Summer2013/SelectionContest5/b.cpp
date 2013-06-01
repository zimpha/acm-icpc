#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=105;
const int SIZE=27;

int dp[MAXN][MAXN][SIZE];
char str[MAXN];

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%s", str);
		int n=strlen(str);
		for (int i=0; i<n; i++)
			str[i]=str[i]-'A';
		memset(dp, -1, sizeof(dp));
		for (int len=0; len<=n; len++)
			for (int left=0; left+len-1<n; left++)
			{
				for (int col=0; col<=26; col++)
				{
					if (len==0) dp[left][len][col]=0;
					else if (str[left]==col) dp[left][len][col]=dp[left+1][len-1][col];
					else
					{
						int ret=MAXN*2;
						for (int i=1; i<=len; i++)
							ret=std::min(ret, 1+dp[left+1][i-1][(int)str[left]]+dp[left+i][len-i][col]);
						dp[left][len][col]=ret;
					}
				}
			}
		printf("%d\n", dp[0][n][26]);
	}
	return 0;
}
