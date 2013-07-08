#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=40005;
const int MAXR=100005;

long long dpA[MAXN], dpB[MAXN];
long long A[MAXN], B[MAXN];
pair<int, int> route[MAXR];
int N, M, R;

int main()
{
	freopen("route.in", "r", stdin);
	freopen("route.out", "w", stdout);
	scanf("%d%d%d",&N, &M, &R);
	for (int i=0; i<N; i++)
		scanf("%lld", A+i);
	for (int i=0; i<M; i++)
		scanf("%lld", B+i);
	for (int i=0; i<R; i++)
		scanf("%d%d", &route[i].first, &route[i].second);
	sort(route, route+R);
	memcpy(dpA, A, sizeof(A));
	memcpy(dpB, B, sizeof(B));
	for (int i=R-1; i>=0; i--)
	{
		int u=route[i].first-1;
		int v=route[i].second-1;
		long long vl=A[u]+dpB[v];
		long long vr=B[v]+dpA[u];
		dpA[u]=max(dpA[u], vl);
		dpB[v]=max(dpB[v], vr);
	}
	printf("%lld\n", max(*max_element(dpA, dpA+N), *max_element(dpB, dpB+M)));
	fclose(stdin); fclose(stdout);
	return 0;
}
