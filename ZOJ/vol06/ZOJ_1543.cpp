#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=105;

int w[MAXN];
int n;

int main()
{
	while (scanf("%d", &n)==1)
	{
	for (int i=0; i<n; i++)
		scanf("%d", w+i);
	std::sort(w,w+n);
	double ret=w[n-1];
	for (int i=n-2; i>=0; i--)
		ret=2*sqrt(ret*(double)w[i]);
	printf("%.3f\n", ret);
	}
	return 0;
}
