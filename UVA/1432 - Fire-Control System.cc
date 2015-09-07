#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 5000 + 10;
const double inf = 1e9;
const double Pi = acos(-1.0);

struct Node {
	double len, ang;
	bool operator < (const Node &rhs) const {
		return ang < rhs.ang;
	}
};

int A[MAXN * 2];
Node P[MAXN * 2];

int main() {
	int N, K, M, cas = 0;
	while (scanf("%d%d", &N, &K) == 2 && N) {
		for (int i = 0; i < N; ++ i) {
			int x, y; scanf("%d%d", &x, &y);
			A[i] = P[i].len = x * x + y * y;
			P[i].ang = atan2(y, x);
			if (P[i].ang < 0) P[i].ang += Pi * 2;
		}
		if (!K) {
			printf("Case #%d: 0.00\n", ++ cas);
			continue;
		}
		sort(A, A + N);
		sort(P, P + N);
		for (int i = 0; i < N; ++ i) {
			P[i + N] = P[i];
			P[i + N].ang += 2 * Pi;
		}
		M = unique(A, A + N) - A;
		double ret = inf;
		for (int k = 0; k < M; ++ k) {
			int R = A[k];
			for (int i = 0, j = 0, sum = 0; i < N; ++ i) {
				if (P[i].len > R) continue;
				j = max(j, i);
				while (j < i + N && sum < K) {
					if (P[j].len <= R) sum ++;
					j ++;
				}
				if (sum >= K) {
					ret = min(ret, 0.5 * R * (P[j - 1].ang - P[i].ang));
				}
				sum --;
			}
		}
		printf("Case #%d: %.2f\n", ++ cas, ret);
	}
	return 0;
}
