#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=85;
const int SIZE=730;
const int delta=360;

int low[MAXN][MAXN], upp[MAXN][MAXN];
bool hash[MAXN][MAXN][SIZE];
bool np[MAXN][MAXN];
char expr[MAXN];
int n;

int main()
{
	freopen("cowfix.in", "r", stdin);
	freopen("cowfix.out", "w", stdout);
	scanf("%s", expr+1);
	n=strlen(expr+1);
	memset(hash, 0, sizeof(hash));
	memset(low, 0, sizeof(low));
	memset(upp, 0, sizeof(upp));
	memset(np, 0, sizeof(np));

	for (int i=1; i<=n; i++)
		if (expr[i]>='0'&&expr[i]<='9')
		{
			np[i][i]=hash[i][i][delta+expr[i]-'0']=true;
			low[i][i]=upp[i][i]=expr[i]-'0';
		}
	for (int k=3; k<=n; k++)
		for (int i=1; i<=n-k+1; i++)
			if (k&1)
			{
				int opt=0, right=i+k-1, ret;;
				for (int j=i; j<=right; j++)
					if (expr[j]=='-'||expr[j]=='+') opt++;
				if (k-opt==opt+1)
				{
					for (int j=i; j<=right; j++)
						if (expr[j]=='-'||expr[j]=='+')
						{
							//Infix
							if (np[i][j-1]&&np[j+1][right])
							{
								np[i][right]=true;
								for (int p1=low[i][j-1]; p1<=upp[i][j-1]; p1++)
								{
									if (!hash[i][j-1][p1+delta]) continue;
									for (int p2=low[j+1][right]; p2<=upp[j+1][right]; p2++)
									{
										if (!hash[j+1][right][p2+delta]) continue;
										if (expr[j]=='+') ret=p1+p2;
										else ret=p1-p2;
										hash[i][right][ret+delta]=true;
										low[i][right]=min(low[i][right], ret);
										upp[i][right]=max(upp[i][right], ret);
									}
								}
							}
							//Postfix
							if (j==right)
							{
								for (int m=i; m<j; m++)
								{
									if (!(np[i][m]&&np[m+1][j-1])) continue;
									np[i][right]=true;
									for (int p1=low[i][m]; p1<=upp[i][m]; p1++)
									{
										if (!hash[i][m][p1+delta]) continue;
										for (int p2=low[m+1][j-1]; p2<=upp[m+1][j-1]; p2++)
										{
											if (!hash[m+1][j-1][p2+delta]) continue;
											if (expr[j]=='+') ret=p1+p2;
											else ret=p1-p2;
											hash[i][right][ret+delta]=true;
											low[i][right]=min(low[i][right], ret);
											upp[i][right]=max(upp[i][right], ret);
										}
									}
								}
							}
							//Prefix
							if (j==i)
							{
								for (int m=j+1; m<=right; m++)
								{
									if (!(np[j+1][m]&&np[m+1][right])) continue;
									np[i][right]=true;
									for (int p1=low[j+1][m]; p1<=upp[j+1][m]; p1++)
									{
										if (!hash[j+1][m][p1+delta]) continue;
										for (int p2=low[m+1][right]; p2<=upp[m+1][right]; p2++)
										{
											if (!hash[m+1][right][p2+delta]) continue;
											if (expr[j]=='+') ret=p1+p2;
											else ret=p1-p2;
											hash[i][right][ret+delta]=true;
											low[i][right]=min(low[i][right], ret);
											upp[i][right]=max(upp[i][right], ret);
										}
									}
								}
							}
						}
				}
			}
	int ans=0;
	for (int i=low[1][n]; i<=upp[1][n]; i++)
		if (hash[1][n][i+delta]) ans++;
	printf("%d\n", ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
