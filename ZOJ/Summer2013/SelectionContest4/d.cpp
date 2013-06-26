#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int SIZE=150;
const int inf=10000000;

int coin[SIZE];

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		long long C;
		scanf("%lld", &C);
		int res=0;
		for (int i=0; i<=SIZE; i++) coin[i]=inf;
		coin[0]=0;
		for (int i=1; i<=SIZE; i++)
			coin[i]=min(coin[i-1]+1, coin[i]);
		for (int i=10; i<=SIZE; i++)
			coin[i]=min(coin[i-10]+1, coin[i]);
		for (int i=25; i<=SIZE; i++)
			coin[i]=min(coin[i-25]+1, coin[i]);
		while (C)
		{
			int a=C%100;
			C/=100;
			res+=coin[a];
		}
		printf("%d\n", res);
	}
	return 0;
}
