#include <queue>
#include <cstring>
#include <iostream>

using namespace std;
      
const int MAXN=8;
const int  dir[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};

struct point
{
    int row,col;
    int step;
};

bool map[MAXN][MAXN];
		     
int bfs(point s,point e,int step)
{
    queue<point>que;
    point p;
    int i,x=0,y=0;
    while (1)
    {
	if (s.row==e.row&&s.col==e.col) return s.step;
	for (i=0; i<8; i++)
	{
	    x=s.row+dir[i][0];
	    y=s.col+dir[i][1];
	    if (x<0||x>=8||y<0||y>=8) continue;
	    if (!map[x][y])
	    {
		p.row=x; p.col=y;
		map[x][y]=1;
		p.step=s.step+1;
		que.push(p);
	    }
	}
	s=que.front();
	que.pop();
    }
}

int main()
{
    point start,end;
    char c1[3],c2[3];
    while (cin >> c1 >> c2)
    {
	start.col=c1[0]-'a';
	end.col=c2[0]-'a';
	start.row=c1[1]-'1';
	end.row=c2[1]-'1';
	start.step=0;
	memset(map,0,sizeof(map));
	cout<<"To get from "<<c1<<" to "<<c2<<" takes "<<bfs(start,end,0)<<" knight moves."<<endl;
    }
    return 0;
}
