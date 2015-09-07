#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 4000 + 10;

vector<int> S;
int A[MAXN], B[MAXN], C[MAXN], D[MAXN], N;

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) scanf("%d%d%d%d", A + i, B + i, C + i, D + i);
		S.clear();
		for (int i = 0; i < N; ++ i)
			for (int j = 0; j < N; ++ j)
				S.push_back(A[i] + B[j]);
		sort(S.begin(), S.end());
		long long ret = 0;
		for (int i = 0; i < N; ++ i) {
			for (int j = 0; j < N; ++ j) {
				int x = -(C[i] + D[j]);
				int a = lower_bound(S.begin(), S.end(), x) - S.begin();
				int b = upper_bound(S.begin(), S.end(), x) - S.begin();
				ret += b - a;
			}
		}
		printf("%lld\n", ret);
		if (T) puts("");
	}
	return 0;
}
