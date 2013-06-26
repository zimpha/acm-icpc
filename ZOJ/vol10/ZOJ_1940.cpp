#include <queue>
#include <cstdio>
#include <cstring>

const int MAXN=35;
const int dx[6]={1,-1,0,0,0,0};
const int dy[6]={0,0,1,-1,0,0};
const int dz[6]={0,0,0,0,1,-1};

struct node
{
    int x,y,z;
    int step;
};

char map[MAXN][MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN];
node st, en;
int l, r, c;

int bfs()
{
    std::queue<node>q;
    while (!q.empty()) q.pop();
    memset(vis,0,sizeof(vis));
    st.step=0; q.push(st);
    vis[st.x][st.y][st.z]=1;
    while (!q.empty())
    {
	node now=q.front(); q.pop();
	if (now.x==en.x&&now.y==en.y&&now.z==en.z) return now.step;
	for (int i=0; i<8; i++)
	{
	    int x=now.x+dx[i];
	    int y=now.y+dy[i];
	    int z=now.z+dz[i];
	    if (x<1||x>l||y<1||y>r||z<1||z>c) continue;
	    node tmp;
	    tmp.x=x; tmp.y=y; tmp.z=z; tmp.step=now.step+1;
	    if (!vis[x][y][z]&&map[x][y][z]!='#')
	    {
		vis[x][y][z]=1;
		q.push(tmp);
	    }
	}
    }
    return -1;
}

int main()
{
    while (scanf("%d%d%d",&l,&r,&c)==3&&l)
    {
	for (int i=1; i<=l; i++)
	{
	    for (int j=1; j<=r; j++)
	    {
		getchar();
		for (int k=1; k<=c; k++)
		{
		    map[i][j][k]=getchar();
		    if (map[i][j][k]=='S') st.x=i, st.y=j, st.z=k;
		    if (map[i][j][k]=='E') en.x=i, en.y=j, en.z=k;
		}
	    }
	    getchar();
	}
	int ans=bfs();
	if (ans==-1) printf("Trapped!\n");
	else printf("Escaped in %d minute(s).\n",ans);
    }
    return 0;
}
