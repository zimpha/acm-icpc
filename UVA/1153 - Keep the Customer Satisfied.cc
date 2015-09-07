#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 800000 + 10;

struct Job {
	int q, d;
	bool operator < (const Job &rhs) const {
		return d < rhs.d;
	}
};

Job A[MAXN];
int N;

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) scanf("%d%d", &A[i].q, &A[i].d);
		sort(A, A + N);
		priority_queue<int> Q;
		while (!Q.empty()) Q.pop();
		int ret = 0;
		for (int i = 0, sum = 0; i < N; ++ i) {
			if (sum + A[i].q > A[i].d) {
				if ((!Q.empty() && sum - Q.top() + A[i].q <= A[i].d)) {
					if (Q.top() > A[i].q) {
						sum -= Q.top(); Q.pop();
						Q.push(A[i].q); sum += A[i].q;
					}
				}
				ret ++;
			} else Q.push(A[i].q), sum += A[i].q;
		}
		printf("%d\n", N - ret);
		if (T) puts("");
	}
	return 0;
}
