#include <cstdio>
#include <cstring>

typedef unsigned long long ULL;

int N, B;

bool check(ULL N) {
	if (N < 2) return false;
	if (N == 2) return true;
	if (N % 2 == 0) return false;
	for (ULL i = 3; i * i <= N; i += 2)
		if (N % i == 0) return false;
	return true;
}

int main() {
	while (scanf("%d%d", &B, &N) == 2) {
		ULL M = 0;
		while (N --) M = M * B + 1;
		if (check(M)) puts("YES");
		else puts("NO");
	}
	return 0;
}
