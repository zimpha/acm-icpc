#include <map>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN=1005;
const int inf=1000000;

struct node
{
	int v;
	node *next;
};

map<string, int>word;
node *head[MAXN];
bool vis[MAXN];
int dis[MAXN];
int n, cnt;
int s, t;

void addedge(int u, int v)
{
	node *p=new(node);
	p->v=v; p->next=head[u]; head[u]=p;
}

void spfa(int s)
{
	queue<int>q;
	while(!q.empty()) q.pop();
	for (int i=1; i<=cnt; i++)
		dis[i]=inf, vis[i]=0;
	vis[s]=1; dis[s]=0; q.push(s);
	while (!q.empty())
	{
		int u=q.front(); q.pop();
		vis[u]=true;
		for (node *p=head[u]; p; p=p->next)
		{
			int v=p->v;
			if (dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				if (!vis[v])
				{
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}
}

int main()
{
	while (scanf("%d", &n)==1)
	{
		string s1, tmp, s2;
		word.clear(); cnt=0;
		memset(head, 0, sizeof(head));
		for (int i=0; i<n; i++)
		{
			cin >> s1 >> tmp >> s2;
			if (!word[s1]) word[s1]=++cnt;
			if (!word[s2]) word[s2]=++cnt;
			int u=word[s1], v=word[s2]; 
			addedge(u, v);
		}
		cin >> s1 >> s2;
		if (!word[s1]) word[s1]=++cnt;
		if (!word[s2]) word[s2]=++cnt;
		s=word[s1]; t=word[s2];
		spfa(s);
		if (dis[t]==inf) printf("-1\n");
		else printf("%d\n", dis[t]);
	}
	return 0;
}
