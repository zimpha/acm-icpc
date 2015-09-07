#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

struct node {
	int s, b;
	node () {}
	node (int s, int b) : s(s), b(b) {}
	bool operator < (const node &oth) const {
		return (s > oth.s);
	}
};

int A[MAXN][MAXN];

void merge(int *A, int *B, int *C, int n) {
	priority_queue <node> Q;
	for (int i = 0; i < n; ++ i) {
		Q.push(node(A[i] + B[0], 0));
	}
	for (int i = 0; i < n; ++ i) {
		node tmp = Q.top(); Q.pop();
		C[i] = tmp.s;
		int b = tmp.b;
		if (b + 1 < n) Q.push(node(tmp.s - B[b] + B[b + 1], b + 1));
	}
}

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < n; ++ j) {
				scanf("%d", &A[i][j]);
			}
			sort(A[i], A[i] + n);
		}
		for (int i = 1; i < n; ++ i) {
			merge(A[0], A[i], A[0], n);
		}
		for (int i = 0; i < n; ++ i) {
			printf("%d%c", A[0][i], (i == n - 1) ? '\n' : ' ');
		}
	}
	return 0;
}
