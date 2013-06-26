#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAXL=15005;

LL sum[MAXL], dam[MAXL];
int L;

int main()
{
	while (scanf("%d", &L)==1)
	{
		memset(sum, 0, sizeof(sum));
		memset(dam, 0, sizeof(dam));
		int a, b, c;
		while (scanf("%d%d%d", &a, &b, &c)==3&&a!=-1)
		{
			if (a>b) swap(a, b);
			sum[a]+=c;
			sum[b+1]-=c;
		}
		int ansl=0, ansr=0;
		LL max=-1;
		for (int i=0; i<=L; i++)
		{
			dam[i]=((i>0)?dam[i-1]:0LL)+sum[i];
			if (dam[i]>max)
			{
				max=dam[i];
				ansl=i;
			}
		}
		for (int i=L; i>=0; i--)
			if (dam[i]==max)
			{
				ansr=i;
				break;
			}
		printf("%d %d\n", ansl, ansr);
	}
	return 0;
}
