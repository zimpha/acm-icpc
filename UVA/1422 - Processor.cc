#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 10000 + 10;

struct Node {
	int r, d, w;
	bool operator < (const Node &rhs) const {
		return d > rhs.d;
	}
	void scan() {scanf("%d%d%d", &r, &d, &w);}
};

Node work[MAXN];
int N, MAXT;

bool cmp(const Node &a, const Node &b) {
	return a.r < b.r;
}

bool check(int lim) {
	priority_queue<Node> Q;
	while (!Q.empty()) Q.pop();
	for (int t = 1, i = 0; t < MAXT; ++ t) {
		for (; i < N && work[i].r <= t; ++ i) Q.push(work[i]);
		int sum = lim;
		while (sum > 0 && !Q.empty()) {
			Node tmp = Q.top(); Q.pop();
			if (tmp.d <= t) return false;
			if (tmp.w > sum) tmp.w -= sum, sum = 0, Q.push(tmp);
			else sum -= tmp.w;
		}
		if (i == N && Q.empty()) return true;
	}
	return false;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N); MAXT = 0;
		for (int i = 0; i < N; ++ i) {
			work[i].scan();
			MAXT = max(MAXT, work[i].d);
		}
		sort(work, work + N, cmp);
		int left = 1, right = 100000000;
		while (left < right) {
			int mid = (left + right - 1) >> 1;
			if (check(mid)) right = mid;
			else left = mid + 1;
		}
		printf("%d\n", left);
	}
	return 0;
}
