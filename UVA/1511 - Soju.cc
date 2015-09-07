#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 200000 + 10;
const int inf = 1e9;

struct Node {
	int x, y, t;
	void scan(int tt) {
		scanf("%d%d", &x, &y);
		t = tt;
	}
	bool operator < (const Node &rhs) const {
		return y < rhs.y;
	}
};

Node P[MAXN];

int main() {
	int T, N, M; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) P[i].scan(0);
		scanf("%d", &M);
		for (int i = 0; i < M; ++ i) P[i + N].scan(1);
		N += M;
		sort(P, P + N);

		int mx, ret = inf;
		mx = -inf;
		for (int i = 0; i < N; ++ i) {
			if (P[i].t) ret = min(ret, P[i].x + P[i].y - mx);
			else mx = max(mx, P[i].x + P[i].y);
		}
		mx = -inf;
		for (int i = N - 1; i >= 0; -- i) {
			if (P[i].t) ret = min(ret, P[i].x - P[i].y - mx);
			else mx = max(mx, P[i].x - P[i].y);
		}
		printf("%d\n", ret);
	}
	return 0;
}
