#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<int> > Q;
int N;

int main() {
	while (scanf("%d", &N) == 1 && N) {
		while (!Q.empty()) Q.pop();
		for (int i = 0, x; i < N; ++ i) {
			scanf("%d", &x);
			Q.push(x);
		}
		long long ret = 0;
		for (int i = 1; i < N; ++ i) {
			int a = Q.top(); Q.pop();
			int b = Q.top(); Q.pop();
			ret += a + b;
			Q.push(a + b);
		}
		printf("%lld\n", ret);
	}
	return 0;
}
