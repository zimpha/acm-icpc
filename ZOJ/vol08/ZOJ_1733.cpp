#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=1005;

char s1[MAXN], s2[MAXN];
int f[MAXN][MAXN];
int n, m;

int main()
{
	while (scanf("%s%s", s1+1, s2+1)==2)
	{
		n=strlen(s1+1);
		m=strlen(s2+1);
		memset(f,0,sizeof(f));
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
			{
				int tmp=std::max(f[i-1][j],f[i][j-1]);
				if (s1[i]==s2[j]) tmp=std::max(f[i-1][j-1]+1,tmp);
				f[i][j]=tmp;
			}
		printf("%d\n", f[n][m]);
	}
	return 0;
}
