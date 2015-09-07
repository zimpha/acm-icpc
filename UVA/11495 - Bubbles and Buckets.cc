#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN = 100000 + 10;

int C[MAXN], N;

void Update(int i, int v) {
	for (; i; i -= i & -i) C[i] += v;
}

int Sum(int i) {
	int ret = 0;
	for (; i <= N; i += i & -i) ret += C[i];
	return ret;
}

int main() {
	while (scanf("%d", &N) == 1 && N) {
		for (int i = 1; i <= N; ++ i) C[i] = 0;
		int ret = 0;
		for (int i = 0; i < N; ++ i) {
			int x; scanf("%d", &x);
			ret ^= Sum(x);
			Update(x, 1);
		}
		if (ret & 1) puts("Marcelo");
		else puts("Carlos");
	}
	return 0;
}
