#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=100005;

struct node
{
	string s;
	int m;
};

bool hash[MAXN];
queue<node>q;
int n, m;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d%d", &n, &m);
		while (!q.empty()) q.pop();
		memset(hash, 0, sizeof(hash));
		node now, tmp;
		for (int i=1; i<10; i+=2)
		{
			now.s=(char)(i+'0');
			now.m=i%n;
			q.push(now);
			hash[i%n]=true;
		}
		string ans="-1";
		while (!q.empty())
		{
			now=q.front(); q.pop();
			if (now.m==m)
			{
				ans=now.s;
				break;
			}
			for (int i=1; i<10; i+=2)
			{
				tmp.s=now.s+(char)(i+'0');
				tmp.m=(now.m*10+i)%n;
				if (!hash[tmp.m])
				{
					hash[tmp.m]=true;
					q.push(tmp);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
