#include <queue>
#include <cstdio>
#include <cstring>

const int SIZE=30;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

struct node
{
    int x,y;
    int col,dir;
    int time;
};

bool vis[SIZE][SIZE][5][4];
char map[SIZE][SIZE];
node st,en;
int n,m;

int bfs()
{
    std::queue<node>q;
    while (!q.empty()) q.pop();
    memset(vis,0,sizeof(vis));
    st.time=st.col=st.dir=0;
    q.push(st); vis[st.x][st.y][0][0]=1;
    while (!q.empty())
    {
	node tmp,now=q.front(); q.pop();
	if (now.x==en.x&&now.y==en.y&&now.col==0) return now.time;
	//Move Forword
	tmp.x=now.x+dx[now.dir]; tmp.y=now.y+dy[now.dir];
	tmp.col=(now.col+1)%5; tmp.dir=now.dir;
	tmp.time=now.time+1;
	if (tmp.x>0&&tmp.x<=n&&tmp.y>0&&tmp.y<=m&&!vis[tmp.x][tmp.y][tmp.col][tmp.dir]&&map[tmp.x][tmp.y]!='#')
	{
	    vis[tmp.x][tmp.y][tmp.col][tmp.dir]=1;
	    q.push(tmp);
	}
	//Turn Right
	tmp=now; tmp.dir=(tmp.dir+1)%4;
	tmp.time++;
	if (!vis[tmp.x][tmp.y][tmp.col][tmp.dir]&&(map[tmp.x][tmp.y]!='#'))
	{
	    vis[tmp.x][tmp.y][tmp.col][tmp.dir]=1;
	    q.push(tmp);
	}
	//Turn Left
	tmp=now; tmp.dir=(tmp.dir+3)%4;
	tmp.time++;
	if (!vis[tmp.x][tmp.y][tmp.col][tmp.dir]&&(map[tmp.x][tmp.y]!='#')) 
	{
	    vis[tmp.x][tmp.y][tmp.col][tmp.dir]=1;
	    q.push(tmp);
	}
    }
    return -1;
}

int main()
{
    int cas=0;
    while (scanf("%d%d",&n,&m)==2&&n)
    {
	if (cas) printf("\n");
	for (int i=1; i<=n; i++)
	{
	    getchar();
	    for (int j=1; j<=m; j++)
	    {
		map[i][j]=getchar();
		if (map[i][j]=='S') st.x=i, st.y=j;
		if (map[i][j]=='T') en.x=i, en.y=j;
	    }
	}
	int ans=bfs();
	printf("Case #%d\n",++cas);
	if (ans==-1) printf("destination not reachable\n");
	else printf("minimum time = %d sec\n",ans);
    }
    return 0;
}
