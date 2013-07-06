#include <set>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 1000000

bool vis[MAXN];
vector<set<int> > group;
vector<int> cow[MAXN];
queue<int> q;
int N, G;

int main()
{
	freopen("invite.in", "r", stdin);
	freopen("invite.out", "w", stdout);
	scanf("%d%d", &N, &G);
	for (int i=0; i<G; i++)
	{
		int S, x;
		set<int> tmp;
		tmp.clear();
		scanf("%d", &S);
		for (int j=0; j<S; j++)
		{
			scanf("%d", &x);
			tmp.insert(--x);
			cow[x].push_back(i);
		}
		group.push_back(tmp);
	}
	int ret=0;
	while (!q.empty()) q.pop();
	memset(vis, 0, sizeof(vis));
	vis[0]=true; q.push(0);
	while (!q.empty())
	{
		int now=q.front(); q.pop();
		ret++;
		for (int i=0; i<cow[now].size(); i++)
		{
			int x=cow[now][i];
			group[x].erase(now);
			if (group[x].size()==1)
			{
				int y=*(group[x].begin());
				if (!vis[y])
				{
					vis[y]=true;
					q.push(y);
				}
			}
		}
	}
	printf("%d\n", ret);
	fclose(stdin); fclose(stdout);
	return 0;
}
