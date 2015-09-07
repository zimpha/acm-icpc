#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 10;

int A[MAXN], B[MAXN], N;

int main() {
	while (scanf("%d", &N) == 1 && N) {
		for (int i = 0; i < N; ++ i) scanf("%d", &A[i]);
		for (int i = 0; i < N; ++ i) scanf("%d", &B[i]);
		sort(A, A + N); sort(B, B + N);
		int l1 = 0, l2 = 0, r1 = N - 1, r2 = N - 1, ret = 0;
		while (l1 <= r1 && l2 <= r2) {
			if (A[r1] > B[r2]) r1 --, r2 --, ret ++;
			else if (A[r1] < B[r2]) l1 ++, r2 --, ret --;
			else {
				if (A[l1] == B[l2]) {
					if (A[l1] < B[r2]) l1 ++, r2 --, ret --;
					else l1 ++, l2 ++;
				} else {
					if (A[l1] > B[l2]) l1 ++, l2 ++, ret ++;
					else r2 --, l1 ++, ret --;
				}
			}
		}
		printf("%d\n", ret * 200);
	}
	return 0;
}
