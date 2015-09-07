#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1010;

struct Node {
	int B, J;
	bool operator < (Node o) const {
		return J > o.J;
	}
};

Node sol[MAXN];

int main() {
	int N, cas = 0; 
	while (scanf("%d", &N) == 1 && N) {
		for (int i = 0; i < N; ++ i) {
			scanf("%d%d", &sol[i].B, &sol[i].J);
		}
		sort(sol, sol + N);
		int SB = 0, ret = 0;
		for (int i = 0; i < N; ++ i) {
			SB += sol[i].B;
			ret = max(ret, SB + sol[i].J);
		}
		printf("Case %d: %d\n", ++ cas, ret);
	}
	return 0;
}
