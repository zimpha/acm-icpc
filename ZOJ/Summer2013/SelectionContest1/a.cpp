#include <cstdio>
#include <cstring>

int calc(int n)
{
	int ret=0;
	for (int i=5; ; i*=5)
		if (n/i==0) break;
		else ret+=n/i;
	return ret;
}

int main()
{
	int n;
	while (scanf("%d", &n)==1)
	{
		int left=1, right=1000000000, ans=-1;
		while (left<=right)
		{
			int mid=(left+right)>>1;
			int zero=calc(mid);
			if (zero==n) ans=mid;
			if (zero>=n) right=mid-1;
			else left=mid+1;
		}
		if (ans==-1) puts("No solution");
		else printf("%d\n", ans);
	}
	return 0;
}
