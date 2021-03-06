#include<cstdio>
#include<algorithm>
#include <vector>

using namespace std;

int n;
int a[100];
vector<long long> s[100];
long long h[100];

int main()
{
	while(scanf("%d",&n) == 1)
	{
		for(int i = 0;i < n;i++)
		{
			scanf("%d",a+i);
			s[i].clear();
			h[i] = 1;
		}
		s[n].clear();
		h[n] = 1;
		for(int i = 0;i < n;i++)
		{
			s[a[i]].push_back(0);
		}
		for(int i = n-1;i > 0;i--) if (s[i].size())
		{
			sort(s[i].begin(),s[i].end());
			int tot = s[i].size();
			for(int j = 0;j < tot;j++)
			{
				if (s[i][j] < h[i+1]) s[i][j] = h[i+1];
			}
			h[i] = s[i][tot-1];
			for(int j = 0;j < tot;j+= 2)
			{
				s[i-1].push_back(s[i][j] + s[i][j+1]);
			}
		}
		printf("%lld\n",s[0][0]);
	}
	return 0;
}
