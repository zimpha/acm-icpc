#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;

int A[MAXN], N;

int main() {
	while (scanf("%d", &N) == 1 && N) {
		for (int i = 0; i < N; ++ i) scanf("%d", A + i);
		int ret = 0;
		for (int g = 1; g <= 100; ++ g) {
			for (int i = 0, last = 0; i < N; ++ i)
				if (A[i] % g == 0) {
					if (!last) last = A[i] / g;
					else last = __gcd(last, A[i] / g);
					if (last == 1) {
						ret ++; break;
					}
				}
				else last = 0;
		}
		printf("%d\n", ret);
	}
	return 0;
}
