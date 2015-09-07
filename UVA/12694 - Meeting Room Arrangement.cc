#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int T,n;
int s[30],t[30];
vector<int> E[20];
int f[20];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		n = 0;
		for(int i = 0;i <= 10;i++) E[i].clear();
		while(true)
		{
			scanf("%d%d",s+n,t+n);
			if (s[n] == 0 && t[n] == 0) break;
			E[s[n]].push_back(t[n]);
			n++;
		}
		memset(f,0,sizeof(f));
		for(int i = 0;i <= 10;i++)
		{
			if (i) f[i] = max(f[i],f[i-1]);
			for(int j = E[i].size()-1;j >= 0;j--)
				f[E[i][j]] = max(f[E[i][j]],f[i]+1);
		}
		printf("%d\n",f[10]);
	}
	return 0;
}
