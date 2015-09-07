#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 30000 + 10;

priority_queue <int> maxQ;
priority_queue <int, vector<int>, greater<int> > minQ;
int A[MAXN], u[MAXN];
int N, M;

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &M, &N);
		for (int i = 1; i <= M; ++ i) scanf("%d", &A[i]);
		for (int i = 1; i <= N; ++ i) scanf("%d", &u[i]);
		while (!maxQ.empty()) maxQ.pop();
		while (!minQ.empty()) minQ.pop();
		for (int i = 1, j = 1; j <= M; ++ j) {
			if (!maxQ.empty() && A[j] < maxQ.top()) maxQ.push(A[j]);
			else minQ.push(A[j]);
			while (i <= N && u[i] == j) {
				while ((int)maxQ.size() < i) {
					maxQ.push(minQ.top());
					minQ.pop();
				}
				while ((int)maxQ.size() > i) {
					minQ.push(maxQ.top());
					maxQ.pop();
				}
				printf("%d\n", maxQ.top());
				i ++;
			}
		}
		if (T) puts("");
	}
	return 0;
}
