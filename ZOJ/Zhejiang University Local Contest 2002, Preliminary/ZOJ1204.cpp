#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

map<int, int> mp;
vector<int> A;
int ans[30];
int N, lim;
bool flag;

void dfs(int dep, int cur, int sum)
{
	if (dep==lim)
	{
		if (mp.find(sum)!=mp.end())
		{
			flag=true;
			cout << ans[0];
			for (int i=1; i<lim; i++)
				cout << "+" << ans[i];
			cout << "=" << sum << endl;
		}
		return;
	}
	for (int i=cur; i<N; i++)
		if (sum+A[i]<=A[N-1])
		{
			ans[dep]=A[i];
			dfs(dep+1, i+1, sum+A[i]);
		}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> N;
		mp.clear(); A.clear();
		for (int x, i=0; i<N; i++)
		{
			cin >> x;
			A.push_back(x);
			mp[x]=1;
		}
		sort(A.begin(), A.end());
		flag=false;
		for (lim=2; lim<N; lim++)
			dfs(0, 0, 0);
		if (!flag) puts("Can't find any equations.");
		puts("");
	}
	return 0;
}
