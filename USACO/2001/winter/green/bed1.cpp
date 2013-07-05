#include <cstdio>
#include <cstring>

const int MAXN=5005;
const int SIZE=1000005;

bool hash[SIZE];
int S[MAXN];
int N, K;

int main()
{
	freopen("bed1.in", "r", stdin);
	freopen("bed1.out", "w", stdout);
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &S[i]);
	K=N;
	memset(hash, 0, sizeof(hash));
	while (1)
	{
		int count=0, top=0;
		for (int i=0; i<N; i++)
		{
			if (hash[S[i]%K])
			{
				for (int j=0; j<i; j++)
					hash[S[j]%K]=0;
				break;
			}
			else
			{
				hash[S[i]%K]=1;
				count++;
			}
		}
		if (count==N) break;
		K++;
	}
	printf("%d\n", K);
	fclose(stdin); fclose(stdout);
	return 0;
}
