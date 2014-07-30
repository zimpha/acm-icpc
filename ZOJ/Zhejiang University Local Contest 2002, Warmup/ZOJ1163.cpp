#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=505;

long long dp[MAXN][MAXN];
int N;

int main()
{
	memset(dp, 0, sizeof(dp));
	dp[1][1]=dp[2][2]=1;
	for (int i=3; i<=500; i++)
	{
		dp[i][i]=1;
		for (int j=1; j<i; j++)
			for (int k=1; k<=i-j&&k<j; k++)
				dp[i][j]+=dp[i-j][k];
	}
	while ((cin >> N)&&N)
	{
		long long ret=0;
		for (int i=1; i<N; i++)
			ret+=dp[N][i];
		cout << ret <<endl;
	}
	return 0;
}
