#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;

double X[MAXN], V[MAXN];
int N;

double distance(double t) {
	double Min = 1e5, Max = -1e5;
	for (int i = 0; i < N; ++ i) {
		double now = X[i] + V[i] * t;
		Min = min(Min, now); Max = max(Max, now);
	}
	return Max - Min;
}

int main() {
	while (scanf("%d", &N) == 1 && N) {
		for (int i = 0; i < N; ++ i) scanf("%lf%lf", X + i, V + i);
		double left = 0.0, right = 2e5;
		for (int _ = 0; _ < 100; ++ _) {
			double mid1 = left + (right - left) / 3;
			double mid2 = right - (right - left) / 3;
			if (distance(mid1) < distance(mid2)) right = mid2;
			else left = mid1;
		}
		printf("%.10f\n", distance(left));
	}
	return 0;
}
