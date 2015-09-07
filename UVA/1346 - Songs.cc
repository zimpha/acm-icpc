#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;

struct Node {
	int id;
	double f, l;
	bool operator < (const Node &rhs) const {
		return l * rhs.f < f * rhs.l;
	}
};

Node A[MAXN];
int N;

int main() {
	while (scanf("%d", &N) == 1) {
		for (int i = 0; i < N; ++ i) scanf("%d%lf%lf", &A[i].id, &A[i].l, &A[i].f);
		sort(A, A + N);
		scanf("%d", &N);
		printf("%d\n", A[N - 1].id);
	}
	return 0;
}
