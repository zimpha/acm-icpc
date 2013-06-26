#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>

const int MAXN=55;

typedef long long LL;

int cx[MAXN], cy[MAXN];
int map[MAXN][MAXN];
int tele[MAXN];
int n, m, ans;

LL dis(LL x1, LL y1, LL x2, LL y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int getid(int city)
{
	LL mydis=dis(cx[city],cy[city],cx[0],cy[0]);
	LL mindis=100000000000000LL;
	int best=0;
	for (int p=0; p<n; p++)
	{
		LL tmp=dis(cx[p],cy[p],cx[0],cy[0]);
		if (mydis>tmp)
		{
			LL nowdis=dis(cx[city],cy[city],cx[p],cy[p]);
			if (nowdis<mindis)
			{
				mindis=nowdis;
				best=p;
			}
			else if (nowdis==mindis)
			{
				if (cx[p]<cx[best]||(cx[p]==cx[best]&&cy[p]<cy[best])) 
					best=p;
			}
		}
	}
	return best;
}

void build()
{
	for (int i=0; i<n; i++)
	{
		for (int j=i+1; j<n; j++)
			map[i][j]=map[j][i]=1000;
		map[i][i]=0;
	}
	for (int i=1; i<n; i++)
	{
		int j=getid(i);
		map[i][j]=map[j][i]=1;
	}
	for (int k=0; k<n; k++)
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				map[i][j]=std::min(map[i][j],map[i][k]+map[k][j]);
}

int inconv(int city)
{
	int ret=map[city][0];
	for (int i=0; i<m; i++)
		ret=std::min(ret,map[city][tele[i]]);
	return ret;
}

void search(int dep, int cur)
{
	if (dep==m)
	{
		int maxinconv=0;
		for (int i=0; i<n; i++)
			maxinconv=std::max(maxinconv,inconv(i));
		ans=std::min(ans,maxinconv);
	}
	else
	{
		for (int i=cur; i<n; i++)
		{
			tele[dep]=i;
			search(dep+1,i+1);
		}
	}
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d%d", &m, &n);
		for (int i=0; i<n; i++)
			scanf("%d", cx+i);
		scanf("%d", &n);
		for (int i=0; i<n; i++)
			scanf("%d", cy+i);
		build();
		ans=10000;
		search(0,0);
		printf("%d\n", ans);
	}
	return 0;
}
