#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 1000 + 10;

int N, A[MAXN];

bool check() {
	stack <int> S;
	while (!S.empty()) S.pop();
	for (int cr = 1, ci = 0; cr <= N; cr ++) {
		S.push(cr);
		while (!S.empty() && S.top() == A[ci]) {
			S.pop(); ci ++;
			if (ci >= N) break;
		}
	}
	return S.empty();
}

int main() {
	while (scanf("%d", &N) == 1 && N) {
		while (scanf("%d", &A[0]) == 1 && A[0]) {
			for (int i = 1; i < N; ++ i) scanf("%d", &A[i]);
			if (check()) puts("Yes");
			else puts("No");
		}
		puts("");
	}
	return 0;
}
