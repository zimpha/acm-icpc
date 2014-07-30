#include <queue>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
const int MOD = 1e9 + 7;

char A[MAXN];
int S1[MAXN], S2[MAXN];
int top1, top2;

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		int ret = 0;
		scanf("%s", A);
		int N = strlen(A);
		top1 = top2 = 0;
		for (int i = 0; i < N / 2; ++ i) S1[top1 ++] = i;
		for (int i = N - 1; i >= N / 2; -- i) S2[top2 ++] = i;
		while (N) {
			if (N & 1) {
				ret = ret * 2 + A[S2[-- top2]] - '0';
				assert(top1 == top2);
			}
			else {
				if (A[S1[top1 - 1]] > A[S2[top2 - 1]]) {
					ret = ret * 2 + A[S1[-- top1]] - '0';
				}
				else {
					ret = ret * 2 + A[S2[-- top2]] - '0';
				}
				if (top1 > top2) {
					S2[top2 ++] = S1[-- top1];
				}
				assert(top1 + 1 == top2);
			}
			ret %= MOD;
			N --;
		}
		printf("Case #%d: %d\n", cas, ret);
	}
	return 0;
}
