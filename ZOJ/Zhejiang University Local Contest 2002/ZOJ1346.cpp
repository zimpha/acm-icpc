#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=20;
const int SIZE=1<<17;

bool g[MAXN][MAXN];
int deg[MAXN];
int dp[SIZE];
int N, M;

int dfs(int s)
{
	if (dp[s]!=-1) return dp[s];
	if (s==(1<<N)-1) return dp[s]=1;
	dp[s]=0;
	for (int i=0; i<N; i++)
		if ((s&(1<<i))==0&&deg[i]==0)
		{
			for (int j=0; j<N; j++)
				if (g[i][j]) deg[j]--;
			dfs(s|(1<<i));
			dp[s]+=dp[s|(1<<i)];
			for (int j=0; j<N; j++)
				if (g[i][j]) deg[j]++;
		}
	return dp[s];
}

int main()
{
	while (cin >> M)
	{
		N=0;
		memset(deg, 0, sizeof(deg));
		memset(dp, -1, sizeof(dp));
		memset(g, 0, sizeof(g));
		map<string, int> mp; mp.clear();
		while (M--)
		{
			string s1, s2;
			int u, v;
			cin >> s1 >> s2;
			if (mp.find(s1)==mp.end()) mp[s1]=N++;
			if (mp.find(s2)==mp.end()) mp[s2]=N++;
			u=mp[s1], v=mp[s2];
			g[u][v]=true; deg[v]++;
		}
		dfs(0); printf("%d\n", dp[0]);
	}
	return 0;
}
