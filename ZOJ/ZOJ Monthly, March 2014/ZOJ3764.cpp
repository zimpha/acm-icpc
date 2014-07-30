#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long LL;

struct Node {
	int u, v, w;
	Node() {}
	Node(int u, int v, int w) : u(u), v(v), w(w) {}
	bool operator < (const Node &rhs) const {
		return w > rhs.w;
	}
};

int main() {
	int N, M, K;
	while (scanf("%d%d%d", &N, &M, &K) == 3) {
		vector<Node> e;
		for (int i = 0; i < M; ++ i) {
			int a, b ,c; scanf("%d%d%d", &a, &b, &c);
			e.push_back(Node(a - 1, b - 1, c));
		}
		sort(e.begin(), e.end());
		LL ret = 1LL<<60LL;
		for (int mask = 0; mask < (1 << (N - 2)); ++ mask) {
			int now = mask << 1 | 1;
			LL sum = 0;
			for (int i = 0, s = K; i < M; ++ i) {
				if (now & (1 << e[i].v)) swap(e[i].u, e[i].v);
				if ((now & (1 << e[i].u)) && !(now & (1 << e[i].v))) {
					if (s == 0) sum += e[i].w;
					else s --;
				}
			}
			if (sum < ret) ret = sum;
		}
		printf("%lld\n", ret);
	}
	return 0;
}
