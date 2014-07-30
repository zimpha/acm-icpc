#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 200000;

int G[MAXN], M, N, T;

bool find(int &a, int &b, int N) {
	if (N <= 0) return false;
	a = 0, b = M - 1;
	while (a <= b) {
		int ret = G[a] + G[b];
		if (ret == N) return true;
		else if (ret > N) b --;
		else a ++;
	}
	return false;
}

int main() {
	for (M = 1; M * (M + 1) / 2 <= 123456789; ++ M) {
		G[M - 1] = M * (M + 1) / 2;
	}
	scanf("%d", &T); M --;
	while (T --) {
		scanf("%d", &N);
		int a, b, t = lower_bound(G, G + M, N) - G;
		if (G[t] == N) printf("%d\n", t + 1);
		else {
			if (find(a, b, N)) {
				printf("%d %d\n", a + 1, b + 1);
			}
			else {
				for (int c = M - 1; c >= 0; -- c) {
					if (find(a, b, N - G[c])) {
						printf("%d %d %d\n", a + 1, b + 1, c + 1);
						break;
					}
				}
			}
		}
	}
	return 0;
}
