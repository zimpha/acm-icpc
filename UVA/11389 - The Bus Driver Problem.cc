#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 10;

int morning[MAXN], afternoon[MAXN];

int main() {
	int n, d, r;
	while (scanf("%d%d%d", &n, &d, &r) == 3 && n) {
		for (int i = 0; i < n; ++ i) scanf("%d", &morning[i]);
		for (int i = 0; i < n; ++ i) scanf("%d", &afternoon[i]);
		sort(morning, morning + n);
		sort(afternoon, afternoon + n);
		int ret = 0;
		for (int i = 0; i < n; ++ i) {
			int c = afternoon[n - i -1] + morning[i];
			if (c > d) ret += c - d;
		}
		printf("%d\n", ret * r);
	}
	return 0;
}
