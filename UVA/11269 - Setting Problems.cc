#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 30;

struct Node {
	int a, b;
};

Node prob[MAXN];
int N;

bool cmp(const Node &a, const Node &b) {
	return a.a + max(a.b, b.a) + b.b < b.a + max(b.b, a.a) + a.b;
}

int main() {
	while (scanf("%d", &N) == 1) {
		for (int i = 0; i < N; ++ i) scanf("%d", &prob[i].a);
		for (int i = 0; i < N; ++ i) scanf("%d", &prob[i].b);
		sort(prob, prob + N, cmp);
		int ret = 0;
		for (int i = 0, t1 = 0; i < N; ++ i) {
			t1 += prob[i].a;
			if (t1 >= ret) ret = t1;
			ret += prob[i].b;
		}
		printf("%d\n", ret);
	}
	return 0;
}
