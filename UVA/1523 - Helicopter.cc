#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
	const int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
	int w[8], p[8];
	while (1) {
		int s = 0;
		for (int i = 0; i < 8; ++ i) {
			scanf("%d", &w[i]), s += w[i];
			p[i] = i;
		}
		if (!s) break;
		double M = 1e9;
		do {
			double Mv = 0, Mh = 0;
			for (int i = 0; i < 8; ++ i) {
				Mv += w[p[i]] * dx[i];
				Mh += w[p[i]] * dy[i];
			}
			M = min(M, sqrt(Mv * Mv + Mh * Mh));
		} while (next_permutation(p, p + 8));
		printf("%.3f\n", M);
	}
	return 0;
}
