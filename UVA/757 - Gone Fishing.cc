#include <cstdio>
#include <cstring>

const int MAXN=30;

int d[MAXN], f[MAXN], t[MAXN];
int time[MAXN];
int maxfish;
int n, h;

bool check(int *a, int *b)
{
	a++; b++;
	for (int i=1; i<=n; i++)
	{
		if (*a>*b) return true;
		if (*a<*b) return false;
	}
	return false;
}

void solve(int h, int upper)
{
	int tmp[MAXN], rest[MAXN];
	memset(tmp,0,sizeof(tmp));
	memcpy(rest,f,sizeof(f));
	for (int i=1; i<upper; i++)
		h-=t[i];
	if (h<=0) return;
	int fish=0;
	while (h--)
	{
		int pool, max=-1;
		for (int i=1; i<=upper; i++)
			if (max<rest[i])
			{
				max=rest[i];
				pool=i;
			}
		rest[pool]-=d[pool];
		if (rest[pool]<0) rest[pool]=0;
		tmp[pool]++; fish+=max;
	}
	if (fish>maxfish||(fish==maxfish&&check(tmp,time)))
	{
		maxfish=fish;
		memcpy(time,tmp,sizeof(tmp));
	}
}

int main()
{
	int test=0;
	while (scanf("%d", &n)==1&&n)
	{
		if (test++) printf("\n");
		scanf("%d", &h);
		h=h*60/5;
		for (int i=1; i<=n; i++) scanf("%d", f+i);
		for (int i=1; i<=n; i++) scanf("%d", d+i);
		for (int i=1; i<n; i++) scanf("%d", t+i);
		maxfish=0;
		memset(time,0,sizeof(time));
		for (int i=1; i<=n; i++)
			solve(h, i);
		for (int i=1; i<=n; i++)
			if (i==1) printf("%d", time[i]*5);
			else printf(", %d", time[i]*5);
		printf("\nNumber of fish expected: %d\n", maxfish);
	}
	return 0;
}
