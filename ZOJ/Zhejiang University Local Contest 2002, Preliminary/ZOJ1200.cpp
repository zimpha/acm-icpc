#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>, greater<int> > q;
int S, W, C, K, M;

int main()
{
	while (cin >> S >> W >> C >> K >> M)
	{
		int times=9999/C+1;
		K=min(K, times);
		while (!q.empty()) q.pop();
		for (int i=1; i<=K; i++) q.push(M*i+S);
		int ret=0;
		for (int i=0; i<times; i++)
		{
			int now=q.top(); q.pop();
			ret=max(ret, now)+W;
			now+=W+2*S;
			q.push(now);
		}
		cout << S+ret << endl;
	}
	return 0;
}
