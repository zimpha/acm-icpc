#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=105;

typedef struct { int l, w, h; } rectype;

rectype rec[MAXN];
int dp[MAXN];
int n;

bool cmp(rectype a, rectype b)
{
	if (a.l==b.l) return (a.w>b.w);
	else return (a.l>b.l);
}

int main()
{
	int cas=0;
	while (scanf("%d", &n)==1&&n)
	{
		for (int i=0; i<n; i++)
		{
			scanf("%d%d%d", &rec[3*i+1].h, &rec[3*i+2].h, &rec[3*i+3].h);
			rec[3*i+1].l=std::max(rec[3*i+2].h,rec[3*i+3].h); 
			rec[3*i+1].w=std::min(rec[3*i+2].h,rec[3*i+3].h);
			rec[3*i+2].l=std::max(rec[3*i+1].h,rec[3*i+3].h); 
			rec[3*i+2].w=std::min(rec[3*i+1].h,rec[3*i+3].h);
			rec[3*i+3].l=std::max(rec[3*i+2].h,rec[3*i+1].h); 
			rec[3*i+3].w=std::min(rec[3*i+2].h,rec[3*i+1].h);
		}
		n*=3;
		std::sort(rec+1,rec+1+n,cmp);
		int ret=0;
		for (int i=1; i<=n; i++)
		{
			dp[i]=rec[i].h;
			for (int j=1; j<i; j++)
				if (rec[i].l<rec[j].l&&rec[i].w<rec[j].w&&dp[i]<dp[j]+rec[i].h)
					dp[i]=dp[j]+rec[i].h;
			ret=std::max(ret,dp[i]);
		}
		printf("Case %d: maximum height = %d\n", ++cas, ret);
	}
	return 0;
}
