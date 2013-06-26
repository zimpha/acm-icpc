#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=1005;

int h[MAXN], l[MAXN], r[MAXN];
bool map[MAXN][MAXN];
int n, m;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d%d", &n, &m);
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
			{
				char ch[5];
				scanf("%s", ch);
				if (ch[0]=='F') map[i][j]=1;
				else map[i][j]=0;
			}
		int ret=0;
		for (int i=1; i<=m; i++)
		{
			h[i]=0;
			l[i]=1;
			r[i]=m;
		}
		for (int i=1; i<=n; i++)
		{
			int lmax=1;
			for (int j=1; j<=m; j++)
				if (map[i][j])
				{
					h[j]++;
					if (l[j]<lmax) l[j]=lmax;
				}
				else
				{
					h[j]=0;
					l[j]=1;
					r[j]=m;
					lmax=j+1;
				}
			int rmin=m;
			for (int j=m; j>0; j--)
				if (map[i][j])
				{
					if (r[j]>rmin) r[j]=rmin;
					ret=std::max(ret,(r[j]-l[j]+1)*h[j]);
				}
				else rmin=j-1;
		}
		printf("%d\n", ret*3);
	}
	return 0;
}
