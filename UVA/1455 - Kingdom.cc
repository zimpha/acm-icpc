#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;
const int MAXN = 100000 + 10;
const int MAXC = 1000000 + 10;

struct Node {
	int cnt, sum;
};

struct Sets {
	int fa, size, y1, y2;
};

Node C[MAXC];
Sets P[MAXN];
int x[MAXN], y[MAXN];
int N, M;

int Find(int x) {
	if (x != P[x].fa) P[x].fa = Find(P[x].fa);
	return P[x].fa;
}

void Update(int idx, int cnt, int sum) {
	for (int i = idx; i < MAXC; i += i & -i) {
		C[i].cnt += cnt; C[i].sum += sum;
	}
}

Node Query(int idx) {
	Node ret; ret.cnt = ret.sum = 0;
	for (int i = idx; i; i -= i & -i) {
		ret.cnt += C[i].cnt; ret.sum += C[i].sum;
	}
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) {
			scanf("%d%d", &x[i], &y[i]);
			x[i] ++; y[i] ++;
			P[i].fa = i; P[i].size = 1;
			P[i].y1 = P[i].y2 = y[i];
		}
		scanf("%d", &M);
		memset(C, 0, sizeof(C));
		while (M --) {
			char st[10];
			int A, B;
			double C;
			scanf("%s", st);
			if (st[0] == 'r') {
				scanf("%d%d", &A, &B);
				A = Find(A); B = Find(B);
				if (A != B) {
					P[A].fa = B;
					if (P[A].y1 != P[A].y2) {
						Update(P[A].y1, -1, -P[A].size);
						Update(P[A].y2, 1, P[A].size);
					}
					if (P[B].y1 != P[B].y2) {
						Update(P[B].y1, -1, -P[B].size);
						Update(P[B].y2, 1, P[B].size);
					}
					P[B].y1 = min(P[B].y1, P[A].y1); P[B].y2 = max(P[B].y2, P[A].y2);
					P[B].size += P[A].size;
					if (P[B].y1 != P[B].y2) {
						Update(P[B].y1, 1, P[B].size);
						Update(P[B].y2, -1, -P[B].size);
					}
				}
			} else {
				scanf("%lf", &C); A = C;
				Node ret = Query(A + 1);
				printf("%d %d\n", ret.cnt, ret.sum);
			}
		}
	}
	return 0;
}
