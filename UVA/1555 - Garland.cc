#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	double A;
	int N;
	while (scanf("%d%lf", &N, &A) == 2) {
		double mx = A + 10;
		for (int i = 1; i < N; ++ i) {
			mx = min(mx, (A + i * i) / i);
		}
		printf("%.2f\n", A - 1 + mx - N * mx + N * N - 2 * N + 2);
	}
	return 0;
}
