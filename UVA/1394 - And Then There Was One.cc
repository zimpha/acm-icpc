#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
	int n, m, k;
	while (scanf("%d%d%d", &n, &k, &m) == 3 && n) {
		int t = 0;
		for (int i = 2; i <= n; ++ i) {
			t = (t + k) % i;
		}
		t = (m - k + 1 + t) % n;
		if (t <= 0) t += n;
		printf("%d\n", t);
	}
	return 0;
}
