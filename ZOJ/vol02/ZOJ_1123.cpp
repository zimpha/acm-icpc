#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int SIZE=20;

typedef struct node{int x, y;}node;

node p[SIZE][SIZE];
node p1, p2, p3;
int num[SIZE];

int cross(node a, node b)
{
	return (a.x*b.y-a.y*b.x);
}

int main()
{
	puts("Program 4 by team X");
	while (scanf("%d%d%d%d%d%d", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y)==6)
	{
		int area=abs(cross(p1, p2)+cross(p2, p3)+cross(p3, p1));
		int n=0, m, l=9;
		for (int i=9; i>=-9; i--)
		{
			node a, b;
			int ret, tmp;
			m=0;
			for (int j=-9; j<=9; j++)
			{
				ret=0;
				a.x=p1.x-j; a.y=p1.y-i; b.x=p2.x-j; b.y=p2.y-i;
				tmp=abs(cross(a, b)); ret+=tmp;
				if (!tmp) continue;
				a.x=p1.x-j; a.y=p1.y-i; b.x=p3.x-j; b.y=p3.y-i;
				tmp=abs(cross(a, b)); ret+=tmp;
				if (!tmp) continue;
				a.x=p3.x-j; a.y=p3.y-i; b.x=p2.x-j; b.y=p2.y-i;
				tmp=abs(cross(a, b)); ret+=tmp;
				if (!tmp) continue;
				if (ret!=area) continue;
				m++; if (j<l) l=j;
				p[n][m].x=j; p[n][m].y=i;
			}
			num[n++]=m;
		}
		for (int i=0; i<n; i++)
		{
			if (!num[i]) continue;
			for (int j=l; j<p[i][1].x; j++) printf("         ");
			for (int j=1; j<=num[i]; j++)
				printf("(%2d,%3d)%c", p[i][j].x, p[i][j].y, (j==num[i])?'\n':' ');
		}
		puts("");
	}
	puts("End of program 4 by team X");
	return 0;
}
