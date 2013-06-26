#include <cstdio>

const int MAXN=31300;

int f[MAXN];
int n;

int digit(int n)
{
	int s=0;
	while (n)
	{
		s++;
		n/=10;
	}
	return s;
}

int get(int bit, int n)
{
	while (bit--)
	{
		n/=10;
	}
	return (n%10);
}

int main()
{
	int test;
	scanf("%d",&test);
	f[0]=0;
	for (int i=1; i<MAXN; i++)
		f[i]=f[i-1]+digit(i);
	while (test--)
	{
		scanf("%d",&n);
		int m;
		for (int i=1; i<MAXN; i++)
			if (n>f[i]) n-=f[i];
			else {m=i; break; }
		for (int i=1; i<=m; i++)
			if (n<=f[i])
			{
				n=f[i]-n;
				m=i;
				break;
			}
		printf("%d\n",get(n,m));
	}
	return 0;
}
