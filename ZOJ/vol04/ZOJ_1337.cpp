#include <cmath>
#include <cstdio>
#include <cstring>

const int MAXN=55;

int num[MAXN];
int n;

int gcd(int a, int b)
{
	if (b==0) return a;
	else return gcd(b, a%b);
}

int main()
{
	while (scanf("%d", &n)==1&&n)
	{
		int m=0;
		for (int i=0; i<n; i++)
		{
			scanf("%d", num+i);
			for (int j=0; j<i; j++)
				if (gcd(num[i],num[j])==1) m++;
		}
		n=n*(n-1)/2;
		if (m==0) puts("No estimate for this data set.");
		else printf("%.6f\n", sqrt(6.0*n/m)+0.00000005);
	}
	return 0;
}
