#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 10;

struct Node {
	int out, in, cost, f;
	void read() {
		scanf("%d%d%d", &out, &in, &cost);
		f = 0;
	}
	bool operator < (const Node &rhs) const {
		return cost > rhs.cost;
	}
};

Node Doll[MAXN];
int sum[MAXN], dp[MAXN], N;

int main() {
	freopen("a.in", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; ++ i) Doll[i].read();
	sort(Doll, Doll + N);
	int ret = 0;
	for (int i = 0; i < N; ++ i) {
		int mx = 0, k = -1;
		for (int j = 0; j < N; ++ j) {
			if (Doll[j].f) continue;
			if (Doll[i].in > Doll[j].out && Doll[j].out > mx) {
				mx = Doll[j].out;
				k = j;
			}
		}
		if (k != -1) Doll[k].f = 1;
		ret += (Doll[i].in - mx) * Doll[i].cost;
	}
	printf("%d\n", ret);
	fclose(stdin);
	return 0;
}
