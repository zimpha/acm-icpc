#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool isPrime(int N) {
	if (N == 2) return true;
	if (N == 1 || N % 2 == 0) return false;
	for (int i = 3; i * i <= N; i += 2) {
		if (N % i == 0) return false;
	}
	return true;
}

int main() {
	int T, N; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		if (isPrime(N)) {
			if (N == 2 || N == 17) puts("Mike");
			else puts("Tom");
		}
		else {
			if (N == 1 || N == 16 || N == 34 || N == 289) puts("Tom");
			else puts("Mike");
		}
	}
	return 0;
}
