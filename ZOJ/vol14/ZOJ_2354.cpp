#include <cstdio>
#include <cstring>

const int MAXN=35;

int floor[MAXN];
int ans[MAXN];
int tmp[MAXN];
int n, m, cnt;

bool check(int limit)
{
	int curtime=0;
	int curpos, pos=1;
	bool flag=false;
	cnt=0;
	for (int i=1; i<=n; i++)
	{
		if ((floor[i]-pos)*20+curtime>limit)
		{
			if (flag) curtime+=10;
			if ((floor[i]-pos)*4+curtime>limit) return false;
			for (curpos=floor[i]; (curpos-pos)*4+(curpos-floor[i])*20+curtime<=limit; curpos++);
			curpos--;
			curtime+=(curpos-pos)*4;
			pos=curpos; flag=true;
			tmp[++cnt]=pos;
		}
	}
	return true;
}

int main()
{
	while (scanf("%d", &n)==1&&n)
	{
		for (int i=1; i<=n; i++)
			scanf("%d", floor+i);
		int st=(floor[1]-1)*4;
		int ed=(floor[n]-1)*20;
		int ret;
		while (st<=ed)
		{
			int mid=(st+ed)>>1;
			if (check(mid)) 
			{
				ed=mid-1; m=cnt; ret=mid;
				memcpy(ans,tmp,sizeof(tmp));
			}
			else st=mid+1;
		}
		printf("%d\n%d", ret, m);
		for (int i=1; i<=m; i++)
			printf(" %d", ans[i]);
		puts("");
	}
	return 0;
}
