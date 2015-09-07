#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 2000 + 10;

struct Node {
	int t, flag;
	bool operator < (const Node &rhs) const {
		if (t == rhs.t) return flag > rhs.flag;
		else return t < rhs.t;
	}
};

Node event[MAXN];
int N;

int main() {
	int cas = 0;
	while (scanf("%d", &N) == 1 && N != -1) {
		for (int i = 0; i < N; ++ i) {
			int a, b; scanf("%d%d", &a, &b);
			event[i << 1] = (Node){a, 1};
			event[i << 1 | 1] = (Node){b, -1};
		}
		N <<= 1; sort(event, event + N);
		int ret = 0;
		for (int i = 0, tmp = 0; i < N; ++ i) {
			tmp += event[i].flag;
			ret = max(ret, tmp);
		}
		printf("Case %d: %d\n", ++ cas, ret);
	}
	return 0;
}
