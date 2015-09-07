#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 10000 + 10;

typedef pair <int, int> PII;

vector <PII> A[MAXN];
int R[MAXN];

int main() {
	int N, M;
	while (scanf("%d%d", &N, &M) == 2) {
		for (int i = 1; i <= M; ++ i) A[i].clear();
		for (int i = 1; i <= N; ++ i) {
			int K; scanf("%d", &K);
			for (int j = 0; j < K; ++ j) scanf("%d", &R[j]);
			for (int j = 0, x; j < K; ++ j) {
				scanf("%d", &x);
				A[R[j]].push_back(make_pair(i, x));
			}
		}
		printf("%d %d\n", M, N);
		for (int i = 1; i <= M; ++ i) {
			printf("%d", (int)A[i].size());
			for (int j = 0; j < (int)A[i].size(); ++ j) {
				printf(" %d", A[i][j].first);
			}
			puts("");
			for (int j = 0; j < (int)A[i].size(); ++ j) {
				if (j) putchar(' ');
				printf("%d", A[i][j].second);
			}
			puts("");
		}
	}
	return 0;
}
