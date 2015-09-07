#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int A[MAXN], B[MAXN], n;

bool check_queue(int n) {
	queue <int> Q;
	while (!Q.empty()) Q.pop();
	for (int i = 0; i < n; ++ i) {
		if (A[i] == 1) {
			Q.push(B[i]);
		} else {
			if (Q.empty() || Q.front() != B[i]) return false;
			Q.pop();
		}
	}
	return true;
}

bool check_stack(int n) {
	stack <int> S;
	while (!S.empty()) S.pop();
	for (int i = 0; i < n; ++ i) {
		if (A[i] == 1) {
			S.push(B[i]);
		} else {
			if (S.empty() || S.top() != B[i]) return false;
			S.pop();
		}
	}
	return true;
}

bool check_priority_queue(int n) {
	priority_queue <int> Q;
	while (!Q.empty()) Q.pop();
	for (int i = 0; i < n; ++ i) {
		if (A[i] == 1) {
			Q.push(B[i]);
		} else {
			if (Q.empty() || Q.top() != B[i]) return false;
			Q.pop();
		}
	}
	return true;
}

int main() {
	bool f1, f2, f3;
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; ++ i) {
			scanf("%d%d", A + i, B + i);
		}
		f1 = check_queue(n);
		f2 = check_stack(n);
		f3 = check_priority_queue(n);
		if (f1) {
			if (f2 || f3) puts("not sure");
			else puts("queue");
		} else {
			if (f2 && f3) puts("not sure");
			else if (f2 && !f3) puts("stack");
			else if (!f2 && f3) puts("priority queue");
			else puts("impossible");
		}
	}
	return 0;
}
