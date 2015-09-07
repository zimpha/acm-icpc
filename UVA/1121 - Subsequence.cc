#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 100010;
const int inf = 100000000;

int A[MAXN];

int main() {
	int n, s;
	while (scanf("%d%d", &n, &s) == 2) {
		for (int i = 0; i < n; ++ i) {
			scanf("%d", A + i);
		}
		int ret = inf;
		for (int i = 0, j = 0, sum = 0; i < n; ++ i) {
			while (j < n && sum < s) sum += A[j], j ++;
			if (sum >= s) ret = min(ret, j - i);
			sum -= A[i];
		}
		if (ret == inf) ret = 0;
		printf("%d\n", ret);
	}
	return 0;
}
