#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 10;

struct Node {
	double dis;
	int p1, p2;
	Node () {}
	Node (double a, int b, int c) : dis(a), p1(b), p2(c) {}
	bool operator < (const Node &rhs) const {
		return dis < rhs.dis;
	}
};

int x[MAXN], y[MAXN], z[MAXN], p[MAXN];
int N0[MAXN], N1[MAXN];
Node R[MAXN * MAXN];
int N, M;

double dist(int i, int j) {
	return sqrt((double)(x[i] - x[j]) * (x[i] - x[j]) + (double)(y[i] - y[j]) * (y[i] - y[j]) + (double)(z[i] - z[j]) * (z[i] - z[j]));
}

int main() {
	while (scanf("%d", &N) == 1) {
		for (int i = 0; i < N; ++ i) {
			scanf("%d%d%d%d", x + i, y + i, z + i, p + i);
			N0[i] = 1, N1[i] = 0;
		}
		M = 0;
		for (int i = 0; i < N; ++ i) {
			for (int j = i + 1; j < N; ++ j) {
				R[M ++] = Node(dist(i, j), i, j);
			}
		}
		sort(R, R + M);
		int cnt = 0, tmp = 0;
		double ret = 0;
		for (int i = 0; i < M; ++ i) {
			int a = R[i].p1, b = R[i].p2;
			if (p[a] == p[b]) {
				if (N1[a] - 1 == N0[a]) tmp --;
				if (N1[b] - 1 == N0[b]) tmp --;
				N0[a] ++, N0[b] ++;
			}
			else {
				if (N1[a] == N0[a]) tmp ++;
				if (N1[b] == N0[b]) tmp ++;
				N1[a] ++, N1[b] ++;
			}
			if (i + 1 < M && R[i].dis == R[i + 1].dis) continue;
			if (tmp > cnt) ret = R[i].dis, cnt = tmp;
		}
		printf("%d\n%.5f\n", cnt, ret);
	}
	return 0;
}
