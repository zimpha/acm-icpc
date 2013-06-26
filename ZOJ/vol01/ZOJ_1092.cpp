#include <cstdio>
#include <cstring>

const int MAXN=35;

typedef char str[MAXN];

double dis[MAXN][MAXN];
str name[MAXN];
int n, m;

int get(str s)
{
	for (int i=0; i<n; i++)
		if (!strcmp(s,name[i])) return i;
}

int main()
{
	int cas=0;
	while (scanf("%d", &n)==1&&n)
	{
		for (int i=0; i<n; i++)
			scanf("%s", name[i]);
		memset(dis,0,sizeof(dis));
		scanf("%d", &m);
		while (m--)
		{
			str s1, s2;
			double r;
			scanf("%s %lf %s", s1, &r, s2);
			dis[get(s1)][get(s2)]=r;
		}
		for (int k=0; k<n; k++)
			for (int i=0; i<n; i++)
				for (int j=0; j<n; j++)
					if (dis[i][j]<dis[i][k]*dis[k][j])
						dis[i][j]=dis[i][k]*dis[k][j];
		int flag=false;
		for (int i=0; i<n; i++)
			if (dis[i][i]>1.00) flag=true;
		if (flag) printf("Case %d: Yes\n", ++cas);
		else printf("Case %d: No\n", ++cas);
	}
	return 0;
}
