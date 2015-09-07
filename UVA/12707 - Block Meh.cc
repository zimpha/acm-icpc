#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 200010;
const int inf = 1e9;

struct Node {
	int s, e;
	void read() {
		scanf("%d%d", &s, &e);
	}
	bool operator < (const Node &rhs) const {
		if (e == rhs.e) return s < rhs.s;
		return e < rhs.e;
	}
};

Node P[MAXN];
int g[MAXN], dp[MAXN];
int N;

int Find(int x) {   //Find minimum index k, that g[k] >= x
	int l = 1, r = N;
	while (l < r) {
		int mid = (l + r - 1) >> 1;
		if (g[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r;
}

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) P[i].read();
		sort(P, P + N);
		int ret = 0;
		for (int i = 1; i <= N; ++ i) g[i] = inf;
		for (int i = 0; i < N; ++ i) {			
			int now = P[i].s;
			int idx = Find(now + 1);
			g[idx] = now;
			if (ret < idx) ret = idx;
		}
		printf("Case %d: %d\n", cas, ret);
	}
	return 0;
}
