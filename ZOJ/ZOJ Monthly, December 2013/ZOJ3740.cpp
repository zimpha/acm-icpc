#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 3000 + 10;

int F[MAXN], G[MAXN], A[MAXN];
int N;

inline bool check(int x) {return x >= 1 && x <= N;}

int main() {
	while (scanf("%d", &N) == 1) {
		for (int i = 1; i <= N; ++ i) scanf("%d", &A[i]);
		F[0] = 0;
		for (int i = 1; i <= N; ++ i) F[i] = F[i - 1] + check(A[i]);
		int ret = F[N];
		memset(G, 0, sizeof(G));
		for (int d = -2 * N; d <= 2 * N; ++ d) {
			int sum = 0;
			for (int i = N; i > 0; -- i) {
				sum += check(A[i] + d);
				G[i] = max(G[i], sum);
				ret = max(ret, G[i] + F[i - 1]);
			}
		}
		for (int d = -2* N; d <= 2 * N; ++ d) {
			int sum = check(A[N] + d);
			int tmp = G[N] - sum;
			for (int i = N - 1; i > 0; -- i) {
				sum += check(A[i] + d);
				ret = max(ret, F[i - 1] + sum + tmp);
				tmp = max(tmp, G[i] - sum);
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
