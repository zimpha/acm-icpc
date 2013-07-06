#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 100001

map<int, int> Count;
int B[MAXN];
int N, K, M;

int main()
{
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	scanf("%d%d", &N, &K);
	Count.clear();
	for (int i=0; i<N; i++)
		scanf("%d", B+i);
	int ret=0, cnt=0;
	for (int i=0, j=0; i<N; i++)
	{
		int &ci=Count[B[i]];
		if (ci==0) cnt++;
		ci++;
		for ( ; cnt>K+1; j++)
		{
			int &cj=Count[B[j]];
			cj--;
			if (cj==0) cnt--;
		}
		if (ci>ret) ret=ci;
	}
	printf("%d\n", ret);
	fclose(stdin); fclose(stdout);
	return 0;
}
