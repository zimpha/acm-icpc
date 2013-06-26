#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;
using std::queue;
using std::string;
const int MAXN=5005;

struct node
{
	string res;
	int rem;
};

queue<node> que;
bool vis[MAXN];
int pre[MAXN];
bool dig[10];
int n, m;

int main()
{
	while (scanf("%d%d", &n, &m)==2)
	{
		memset(dig,0,sizeof(dig));
		memset(vis,0,sizeof(vis));
		while (m--)
		{
			int x;
			scanf("%d", &x);
			dig[x]=true;
		}
		if (n==0) printf("%d\n", 0);
		else
		{
			node now, tmp;
			while (!que.empty()) que.pop();
			for (int i=1; i<10; i++)
				if (dig[i])
				{
					now.res=(char)('0'+i);
					now.rem=i%n;
					vis[now.rem]=true;
					que.push(now);
				}
			while (!que.empty())
			{
				now=que.front(); que.pop();
				if (now.rem==0) break;
				for (int i=0; i<10; i++)
					if (dig[i])
					{
						tmp.res=now.res+(char)('0'+i);
						tmp.rem=(now.rem*10+i)%n;
						if (!vis[tmp.rem])
						{
							que.push(tmp);
							vis[tmp.rem]=true;
						}
					}
			}
			if (now.rem==0) cout << now.res << endl;
			else puts("0");
		}
	}
	return 0;
}
