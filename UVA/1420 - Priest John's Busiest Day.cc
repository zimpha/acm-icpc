#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

struct Wedding {
	int s, m, e, mt;
	bool operator < (const Wedding &rhs) const {
		return m < rhs.m || (m == rhs.m && s < rhs.s);
	}
};

Wedding A[MAXN];
int N;

bool solve() {
	for (int i = 0, t = 0; i < N; ++ i) {
		if (t > A[i].e - A[i].mt) return false;
		if (t >= A[i].s) t += A[i].mt;
		else t = A[i].m;
	}
	return true;
}

int main() {
	while (scanf("%d", &N) == 1 && N) {
		for (int i = 0; i < N; ++ i) {
			scanf("%d%d", &A[i].s, &A[i].e);
			A[i].mt = (A[i].e - A[i].s) / 2 + 1;
			A[i].m = A[i].s + A[i].mt;
		}
		sort(A, A + N);
		if (solve()) puts("YES");
		else puts("NO");
	}
	return 0;
}
