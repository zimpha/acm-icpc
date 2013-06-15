#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int SIZE=3000;
const int MAXG=105;
const int inf=10000000;

struct node
{
	int T, F, H;
};

node garb[MAXG];
bool dp[MAXG][SIZE];
int D, G, T;

bool cmp(node a, node b)
{
	return (a.T<b.T);
}

int main()
{
	freopen("well.in", "r", stdin);
	freopen("well.out", "w", stdout);
	scanf("%d%d", &D, &G); T=10;
	for (int i=0; i<G; i++)
	{
		scanf("%d%d%d", &garb[i].T, &garb[i].F, &garb[i].H);
		T+=garb[i].F;
	}
	sort(garb, garb+G, cmp);
	memset(dp, 0, sizeof(dp));
	dp[0][10]=1;
	for (int i=0; i<G; i++)
		for (int j=D-1; j>=0; j--)
			for (int k=T; k>=garb[i].T; k--)
			{
				if (!dp[j][k]) continue;
				if (j+garb[i].H>=D)
				{
					printf("%d\n", garb[i].T);
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				dp[j+garb[i].H][k]=true;
				dp[j][k+garb[i].F]=true;
			}
	while (!dp[0][T]) T--;
	printf("%d\n", T);
	fclose(stdin); fclose(stdout);
	return 0;
}
