#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 505;
const double eps = 1e-10;

struct node {
	double x, y;
};

double dis[MAXN][MAXN];
node P[MAXN];
int N, top;

inline double cross(node p1,node p2, node p0) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

inline double area(node a, node b, node c) {
	return fabs(cross(a, b, c));
}

int main() {
	while (scanf("%d", &N) == 1) {
		for (int i = 0; i < N; ++ i) {
			scanf("%lf%lf", &P[i].x, &P[i].y);
			for (int j = 0; j < i; ++ j) {
				dis[i][j] = dis[j][i] = hypot(P[i].x - P[j].x, P[i].y - P[j].y);
			}
		}
		double ret = 0;
		for (int i = 0; i < N; ++ i) {
			int k = -1;
			for (int j = 0; j < N; ++ j) {
				if (i == j) continue;
				if (k == -1 || dis[i][k] < dis[i][j]) k = j;
			}
			for (int j = 0; j < N; ++ j) {
				if (j == k || i == j) continue;
				double s = area(P[i], P[j], P[k]);
				ret = max(ret, s / dis[i][j]);
				ret = max(ret, s / dis[i][k]);
				ret = max(ret, s / dis[k][j]);
			}
		}
		printf("%.8f\n", ret);
	}
	return 0;
}


