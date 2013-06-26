#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=1005;

int tian[MAXN], king[MAXN];
int n;

int main()
{
	while (scanf("%d", &n)==1&&n)
	{
		for (int i=0; i<n; i++)
			scanf("%d", tian+i);
		std::sort(tian,tian+n);
		for (int i=0; i<n; i++)
			scanf("%d", king+i);
		std::sort(king,king+n);
		int h1, h2, t1, t2;
		int ret=0;
		h1=h2=0; t1=t2=n-1;
		while (h1<=t1)
		{
			if (tian[t1]>king[t2])
			{
				t1--; t2--;
				ret+=200;
			}
			else if (tian[h1]>king[h2])
			{
				h1++; h2++;
				ret+=200;
			}
			else
			{
				if (tian[h1]<king[t2]) ret-=200;
				h1++; t2--;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
