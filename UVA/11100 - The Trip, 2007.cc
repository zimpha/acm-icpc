#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 10000 + 10;

int A[MAXN];
int N, M;

int main() {
	int cas = 0;
	while (scanf("%d", &N) == 1 && N) {
		for (int i = 0; i < N; ++ i) scanf("%d", &A[i]);
		if (cas ++) puts("");
		sort(A, A + N);
		int ret = 1, cnt = 1;
		for (int i = 1; i < N; ++ i) {
			if (A[i] == A[i - 1]) cnt ++;
			else ret = max(ret, cnt), cnt = 1;
		}
		ret = max(ret, cnt);
		printf("%d\n", ret);
		for (int i = 0; i < ret; ++ i) {
			printf("%d", A[i]);
			for (int j = i + ret; j < N; j += ret) printf(" %d", A[j]);
			puts("");
		}
	}
	return 0;
}
