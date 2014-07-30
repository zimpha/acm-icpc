#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int N, M; scanf("%d%d", &N, &M);
		while (N --) {
			int x; scanf("%d", &x);
			M -= x;
		}
		if (M >= 0) puts("Safe");
		else puts("Warning");
	}
	return 0;
}
