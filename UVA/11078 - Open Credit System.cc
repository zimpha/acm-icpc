#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 100000000;

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int MaxAi, n;
		scanf("%d", &n);
		scanf("%d", &MaxAi);
		int ret = -inf;
		for (int i = 1, x; i < n; ++ i) {
			scanf("%d", &x);
			ret = max(ret, MaxAi - x);
			MaxAi = max(MaxAi, x);
		}
		printf("%d\n", ret);
	}
	return 0;
}
