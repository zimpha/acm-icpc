#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
	int N, cas = 0;
	while (scanf("%d", &N) == 1 && N) {
		long long ret = 0;
		int cnt = 0;
		for (int i = 2; (long long)i * i <= N; ++ i) {
			if (N % i == 0) {
				int tmp = 1;
				while (N % i == 0) {
					N /= i;
					tmp *= i;
				}
				ret += (long long)tmp;
				cnt ++;
			}
		}
		if (N > 1) ret += N, cnt ++;
		if (cnt == 1) ret += 1;
		if (cnt == 0) ret = 2;
		printf("Case %d: %lld\n", ++ cas, ret);
	}
	return 0;
}
