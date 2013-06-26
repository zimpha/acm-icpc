#include <cstdio>
#include <cstring>

const int MAXN=25;

int w[MAXN][MAXN][MAXN];
int a, b, c;

int dp(int a, int b, int c)
{
	if (a<=0||b<=0||c<=0) return 1;
	if (a>20||b>20||c>20) return dp(20,20,20);
	if (w[a][b][c]!=-1) return w[a][b][c];
	if (a<b&&b<c) w[a][b][c]=dp(a,b,c-1)+dp(a,b-1,c-1)-dp(a,b-1,c);
	else w[a][b][c]=dp(a-1,b,c)+dp(a-1,b-1,c)+dp(a-1,b,c-1)-dp(a-1,b-1,c-1);
	return w[a][b][c];
}

int main()
{
	memset(w,-1,sizeof(w));
	while (scanf("%d%d%d", &a, &b, &c))
	{
		if (a==-1&&b==-1&&c==-1) break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, dp(a,b,c));
	}
	return 0;
}
