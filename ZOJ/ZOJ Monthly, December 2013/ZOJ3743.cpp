#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;
const int MAXM = 1005;
const double inf = 1e30;

struct node {
	int x, y;
};

node S[MAXN], L[MAXM];
double map[MAXN][MAXN];
int N, M;

double dis(node a, node b) {return hypot(a.x - b.x, a.y - b.y);}

int cross(node a, node b, node c) {
	return ((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x));
}

bool check(node a, node b) {
	for (int i = 1; i <= M; ++ i)
		if (cross(a, b, L[i]) <= 0) return false;
	return true;
}

int main() {
	while (scanf("%d%d", &N, &M) == 2) {
		for (int i = 1; i <= N; ++ i) scanf("%d%d", &S[i].x, &S[i].y);
		for (int i = 1; i <= M; ++ i) scanf("%d%d", &L[i].x, &L[i].y);
		for (int i = 1; i <= N; ++ i)
			for (int j = 1; j <= N; ++ j) {
				map[i][j] = inf;
				if (check(S[i], S[j])) map[i][j] = dis(S[i], S[j]);
			}
		double ans = inf;
		for (int k = 1; k <= N; ++ k)
			for (int i = 1; i <= N; ++ i)
				for (int j = 1; j <= N; ++ j)
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
		for (int i = 1; i <= N; ++ i) ans = min(ans, map[i][i]);
		printf("%.12f\n", ans);
	}
	return 0;
}
