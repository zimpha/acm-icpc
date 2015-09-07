#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 3000 + 10;

int A[MAXN], V[MAXN], N;

int main() {
	while (scanf("%d", &N) == 1 && N) {
		for (int i = 0; i < N; ++ i) scanf("%d", &A[i]);
		for (int i = 0; i < N; ++ i) {
			int x; scanf("%d", &x);
			V[x] = i;
		}
		int ret = 0;
		for (int i = 0; i < N; ++ i) {
			int l = V[A[i]], r = V[A[i]], cnt = 1;
			for (int j = i + 1; j < N; ++ j) {
				l = min(l, V[A[j]]); r = max(r, V[A[j]]);
				cnt ++;
				if (r - l + 1 == cnt) ret ++;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
