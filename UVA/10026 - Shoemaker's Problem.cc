#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 10;

struct Node {
	int id, time, fine;
	bool operator < (const Node &rhs) const {
		return fine * rhs.time > time * rhs.fine;
	}
};

Node A[MAXN];
int N;

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		for (int i = 1; i <= N; ++ i) scanf("%d%d", &A[i].time, &A[i].fine), A[i].id = i;
		sort(A + 1, A + 1 + N);
		for (int i = 1; i <= N; ++ i) {
			if (i > 1) putchar(' ');
			printf("%d", A[i].id);
		}
		puts("");
		if (T) puts("");
	}
	return 0;
}
