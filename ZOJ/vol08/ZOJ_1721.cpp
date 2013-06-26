#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
const double inf=0x3fffffff;

struct point
{
	double x,y;
};

int n;
int s,t;
point p[500];
point e[500][2];
double map[200][200],vis[200],dis[200];

double cross(point pi,point pj,point pk)
{
	   return (pj.x-pi.x)*(pk.y-pi.y)-(pk.x-pi.x)*(pj.y-pi.y);
}

bool judge_intersect(point p1,point p2,point p3,point p4)
{
	if (cross(p3,p4,p1)*cross(p3,p4,p2)<0&&cross(p1,p2,p3)*cross(p1,p2,p4)<0) return true;
	return false;
}

bool link(point a,point b)
{
	for(int i=0;i<3*n;i++)
	{
		if(judge_intersect(e[i][0],e[i][1],a,b))
			return false;
	}
	return true;
}

double get_dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double Dijkstra(int v)
{
	memset(vis,0,sizeof(vis));
	vis[v]=1;
	for (int i=0;i<=4*n+1;i++) dis[i]=map[v][i];
	for (int num=1;num<=4*n+1;num++)
	{
		double min=inf;
		int k;
		for (int i=0;i<=4*n+1;i++)
		{
			if (!vis[i]&&dis[i]<min)
			{
				min=dis[i];
				k=i;
			}
		}
		vis[k]=1;
		for (int i=0;i<=4*n+1;i++)
			if (!vis[i]&&dis[i]>dis[k]+map[k][i])
				dis[i]=dis[k]+map[k][i];
	}
	return dis[t];
}

int main()
{
	while (scanf("%d",&n)==1 && n!=-1)
	{
		p[0].x=0; p[0].y=5;
		p[4*n+1].x=10; p[4*n+1].y=5;
		double x,y1,y2,y3,y4;
		for (int i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf%lf",&x,&y1,&y2,&y3,&y4);
			p[4*i+1].x=p[4*i+2].x=p[4*i+3].x=p[4*i+4].x=x;
			p[4*i+1].y=y1; p[4*i+2].y=y2;
			p[4*i+3].y=y3; p[4*i+4].y=y4;
			e[3*i][0].x=x; e[3*i][0].y=0;
			e[3*i][1].x=x; e[3*i][1].y=y1;
			e[3*i+1][0].x=x; e[3*i+1][0].y=y2;
			e[3*i+1][1].x=x; e[3*i+1][1].y=y3;
			e[3*i+2][0].x=x; e[3*i+2][0].y=y4;
			e[3*i+2][1].x=x; e[3*i+2][1].y=10;
		}
		for (int i=0;i<=4*n+1;i++)
			for (int j=i+1;j<=4*n+1;j++)
				if (link(p[i],p[j])) map[i][j]=map[j][i]=get_dis(p[i],p[j]);
				 else map[i][j]=inf;
		s=0;
		t=4*n+1;
		double ans=Dijkstra(s);
		printf("%.2lf\n",ans);
	}
	return 0;
}



