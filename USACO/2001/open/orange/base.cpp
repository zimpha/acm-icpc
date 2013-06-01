#include <cstdio>
#include <cstring>

const int MAXN=50;

int num[MAXN];
int s, t, bs, bt;

void tonum(int n, int base)
{
	memset(num, 0, sizeof(num));
	while (n)
	{
		num[0]++;
		num[num[0]]=n%base;
		n/=base;
	}
}

bool check()
{
	for (int i=1; i<=num[0]/2; i++)
		if (num[i]!=num[num[0]-i+1]) return false;
	return true;
}

int main()
{
	freopen("base.in", "r", stdin);
	freopen("base.out", "w", stdout);
	
	scanf("%d%d%d%d", &s, &t, &bs, &bt);
	int ret=0;
	for (int i=s; i<=t; i++)
	{
		int res=i*i;
		int sum=0;
		for (int j=bs; j<=bt; j++)
		{
			tonum(res, j);
			if (check()) sum++;
		}
		if (sum==1) ret++;
	}
	printf("%d\n", ret);

	fclose(stdin); fclose(stdout);
	return 0;
}
