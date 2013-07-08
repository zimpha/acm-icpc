#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=100005;

int A[MAXN], B[MAXN];
int N, M;

int main()
{
	freopen("taxi.in", "r", stdin);
	freopen("taxi.out", "w", stdout);
	scanf("%d%d", &N, &M);
	long long ret=0;
	for (int i=0; i<N; i++)
	{
		scanf("%d%d", A+i, B+i);
		ret+=(long long)abs(A[i]-B[i]);
	}
	A[N]=M, B[N++]=0;
	sort(A, A+N);
	sort(B, B+N);
	for (int i=0; i<N; i++)
		ret+=(long long)abs(A[i]-B[i]);
	printf("%lld\n", ret);
	fclose(stdin); fclose(stdout);
	return 0;
}
