#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const double eps = 1e-5;
const double PI = acos(-1.0);
const int MAXN = 10000 + 10;

double A[MAXN];
int N, F;

bool check(double lim) {
	int ret = 0;
	for (int i = 0; i < N; ++ i) ret += floor(A[i] / lim);
	return ret >= F + 1;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &N, &F);
		double left = 0, right = 0;
		for (int i = 0; i < N; ++ i) {
			scanf("%lf", &A[i]);
			A[i] = A[i] * A[i] * PI;
			right = max(right, A[i]);
		}
		while (fabs(left - right) > eps) {
			double mid = (left + right) / 2;
			if (check(mid)) left = mid;
			else right = mid;
		}
		printf("%.5lf\n", left);
	}
	return 0;
}
