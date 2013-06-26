#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=10;
const int SIZE=100005;

queue<string>q;
bool vis[SIZE];
string str;
int n;

int tonum(string str)
{
	int ret=0;
	for (int i=0; i<n; i++)
		ret=ret*10+str[i]-'0';
	return ret;
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		cin >> str;
		n=str.size();
		memset(vis, 0, sizeof(vis));
		while (!q.empty()) q.pop();
		vis[tonum(str)]=true;
		q.push(str);
		while (!q.empty())
		{
			string now, tmp;
			now=q.front(); q.pop();
			for (int i=0; i<n; i++)
				for (int j=i+1; j<n; j++)
				{
					tmp=now;
					if (tmp[i]=='0'||tmp[j]=='0') continue;
					tmp[i]--; tmp[j]--;
					swap(tmp[i], tmp[j]);
					int abc=tonum(tmp);
					if (!vis[abc])
					{
						vis[abc]=true;
						q.push(tmp);
					}
				}
		}
		int ans;
		for (int i=1; i<SIZE; i++)
			if (vis[i]) ans=i;
		printf("%d\n" , ans);
/*
		while (1)
		{
			string max, tmp;
			max=str;
			for (int i=0; i<n; i++)
				for (int j=0; j<n; j++)
				{
					tmp=str;
					if (i==j||tmp[i]=='0'||tmp[j]=='0') continue;
					tmp[i]--; tmp[j]--;
					swap(tmp[i], tmp[j]);
					if (tmp>max) max=tmp;
				}
			if (max<=str) break;
			else str=max;
		}
		cout << str << endl;
	*/
	}
	return 0;
}
