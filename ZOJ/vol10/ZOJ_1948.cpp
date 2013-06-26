#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXT=1005;
const int SIZE=1000005;

queue<int>team[MAXT];
queue<int>que;
bool hash[MAXT];
int id[SIZE];
int n,m;

int main()
{
    int cas=0;
    while (scanf("%d",&n)==1&&n>0)
    {
	memset(id,0,sizeof(id));
	while (!que.empty()) que.pop();
	for (int i=0; i<n; i++)
	{
	    while (!team[i].empty()) team[i].pop();
	    scanf("%d",&m);
	    for (int j=0; j<m; j++)
	    {
		int x;
		scanf("%d",&x);
		id[x]=i;
	    }
	}
	printf("Scenario #%d\n",++cas);
	char cmd[10];
	memset(hash,0,sizeof(hash));
	while (scanf("%s",cmd)&&cmd[0]!='S')
	{
	    if (cmd[0]=='E')
	    {
		int x;
		scanf("%d",&x);
		int belong=id[x];
		if (!hash[belong])
		{
		    hash[belong]=true;
		    que.push(belong);
		    team[belong].push(x);
		}
		else team[belong].push(x);
	    }
	    else if (cmd[0]=='D')
	    {
		int belong=que.front();
		int x=team[belong].front();
		printf("%d\n",x);
		team[belong].pop();
		if (team[belong].empty())
		{
		    que.pop();
		    hash[belong]=false;
		}
	    }
	}
	printf("\n");
    }
    return 0;
}
