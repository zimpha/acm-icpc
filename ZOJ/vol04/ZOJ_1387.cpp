#include <cstdio>
#include <cstring>

const int MAXN=10005;
const char *morse[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

int pow[MAXN], hash[MAXN];
int len[MAXN], val[MAXN];
int dp[MAXN];
int n, m;

int main()
{
	int test;
	pow[0]=1;
	for (int i=1; i<MAXN; i++)
		pow[i]=pow[i-1]*2;
	scanf("%d", &test);
	while (test--)
	{
		char st[MAXN];
		getchar();
		scanf("%s", st+1);
		n=strlen(st+1);
		hash[0]=0;
		for (int i=1; i<=n; i++)
			hash[i]=2*hash[i-1]+((st[i]=='-')?0:1);
		scanf("%d", &m);
		for (int i=1; i<=m; i++)
		{
			getchar();
			scanf("%s", st);
			len[i]=0; val[i]=0;
			for (int j=0; j<strlen(st); j++)
			{
				int t=st[j]-'A';
				for (int k=0; k<strlen(morse[t]); k++)
				{
					len[i]++;
					val[i]=val[i]*2+((morse[t][k]=='-')?0:1);
				}
			}
		}
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				if (i>=len[j])
				{
					int tmp=hash[i]-hash[i-len[j]]*pow[len[j]];
					if (tmp==val[j]) dp[i]+=dp[i-len[j]];
				}
		printf("%d\n", dp[n]);
	}
	return 0;
}

