#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAXN=5005;
const int SIZE=1000005;

bool diff[SIZE];
int S[MAXN];
int N, K, M;

int main()
{
	freopen("bed1.in", "r", stdin);
	freopen("bed1.out", "w", stdout);
	scanf("%d", &N);
	M=0;
	for (int i=0; i<N; i++)
	{
		scanf("%d", &S[i]);
		if (S[i]>M) M=S[i];
	}
	memset(diff, 0, sizeof(diff));
	for (int i=0; i<N; i++)
		for (int j=i+1; j<N; j++)
			diff[abs(S[i]-S[j])]=true;
	K=N;
	while (K<=M)
	{
		bool flag=true;
		for (int i=K; i<=M&&flag; i+=K)
			if (diff[i]) flag=false;
		if (flag) break;
		K++;
	}
	printf("%d\n", K);
	fclose(stdin); fclose(stdout);
	return 0;
}
