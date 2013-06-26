#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=1005;

struct node
{
	int x, y;
};

node p[MAXN];
int n;

bool cmp(node a, node b)
{
	if (a.x==b.x) return (a.y<b.y);
	else return (a.x<b.x);
}

bool find(node a)
{
	int l=0, r=n-1;
	while (l<=r)
	{
		int m=(l+r)>>1;
		node t;
		t.x=a.x-p[m].x;
		t.y=a.y-p[m].y;
		if (t.x==0&&t.y==0) return true;
		if (t.x<0||(t.x==0&&t.y<0)) r=m-1;
		else l=m+1;
	}
	return false;
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
	while (scanf("%d", &n)==1&&n)
	{
		for (int i=0; i<n; i++)
			scanf("%d%d", &p[i].x, &p[i].y);
		int ret=0;
		std::sort(p,p+n,cmp);
		for (int i=0; i<n; i++)
			for (int j=i+1; j<n; j++)
			{
				node p1, p2;
				p1.x=p[i].x+p[j].x+p[i].y-p[j].y;
				p1.y=p[i].y+p[j].y-p[i].x+p[j].x;
				p2.x=p[i].x+p[j].x-p[i].y+p[j].y;
				p2.y=p[i].y+p[j].y+p[i].x-p[j].x;
				if ((p1.x&1)||(p1.y&1)||(p2.x&1)||(p2.y&1)) continue;
				p1.x>>=1; p1.y>>=1;
				p2.x>>=1; p2.y>>=1;
				if (find(p1)&&find(p2)) ret++;
			}
		printf("%d\n", ret/2);
	}
	if (test) puts("");
	}
	return 0;
}
