#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

struct Node {
	int x, t;
	Node () {}
	Node (int x, int t) : x(x), t(t) {}
	bool operator < (const Node &oth) const {
		return x < oth.x || (x == oth.x && t > oth.t);
	}
};

Node A[MAXN << 1];

void Update(int x, int a, int w, int &L, int &R) {
	if (a == 0) {
		if (x <= 0 || x >= w) R = L - 1;
	} else if (a > 0) {
		L = max(L, -x * 2520 / a);
		R = min(R, (w - x) * 2520 / a);
	} else {
		L = max(L, (w - x) * 2520 / a);
		R = min(R, -x * 2520 / a);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int w, h, n, m = 0;
		scanf("%d%d%d", &w, &h, &n);
		for (int i = 0; i < n; ++ i) {
			int x, y, a, b;
			scanf("%d%d%d%d", &x, &y, &a, &b);
			int L = 0, R = 1e9;
			Update(x, a, w, L, R);
			Update(y, b, h, L, R);
			if (R > L) {
				A[m ++] = Node(L, 0);
				A[m ++] = Node(R, 1);
			}
		}
		sort(A, A + m);
		int ret = 0, cnt = 0;
		for (int i = 0; i < m; ++ i) {
			if (A[i].t == 0) ret = max(ret, ++ cnt);
			else cnt --;
		}
		printf("%d\n", ret);
	}
	return 0;
}	
