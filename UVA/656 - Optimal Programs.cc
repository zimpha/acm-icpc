#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
using namespace std;
const int N = 15;
const char tr[5][10] = {"ADD", "DIV", "DUP", "MUL", "SUB"};
int n, x[N], y[N];

struct State {
	stack<int>s;
	int path[N];
	int pathn;
}p;

queue<State>Q;

void init() {
	for (int i = 0; i < n; i ++)
		scanf("%d", &x[i]);
	for (int j = 0; j < n; j ++)
		scanf("%d", &y[j]);
}

State tra(int way, State p) {
	State q = p;
	if (way == 0) {
		int a = q.s.top(); q.s.pop();
		int b = q.s.top(); q.s.pop();
		q.s.push(a + b);
	}
	if (way == 4) {
		int a = q.s.top(); q.s.pop();
		int b = q.s.top(); q.s.pop();
		q.s.push(b - a);
	}
	if (way == 3) {
		int a = q.s.top(); q.s.pop();
		int b = q.s.top(); q.s.pop();
		q.s.push(a * b);
	}
	if (way == 1) {
		int a = q.s.top(); q.s.pop();
		int b = q.s.top(); q.s.pop();
		q.s.push(b / a);
	}
	if (way == 2) {
		int a = q.s.top();
		q.s.push(a);
	}
	q.path[q.pathn++] = way;
	return q;
}

bool judge(State p) {
	for (int i = 1; i < n; i ++) {
		State q; q.pathn = 0; q.s.push(x[i]); memset(q.path, 0, sizeof(q.path));
		for (int j = 0; j < p.pathn; j++) {
			if ((p.path[j] == 1 && q.s.top() == 0) || q.s.top() > 30000 || q.s.top() < -30000 ) return false;
			q = tra(p.path[j], q);
		}
		if (q.s.top() != y[i]) return false;
	}
	return true;
}

bool bfs() {
	while(!Q.empty()) Q.pop();
	while(!p.s.empty()) p.s.pop();
	p.s.push(x[0]); p.pathn = 0; memset(p.path, 0, sizeof(p.path));
	Q.push(p);
	while (!Q.empty()) {
		p = Q.front(); Q.pop();
		if (p.s.size() == 1 && p.s.top() == y[0]) {
			if (judge(p)) return true;
		}
		for (int i = 0; i < 5; i ++) {
			int t = p.s.size() - (10 - p.pathn);
			if (i == 2 && t > 1) continue;
			if (p.s.size() == 1 && i != 2) continue;
			if (i == 1 && p.s.top() == 0) continue;
			if(p.pathn >= 10) continue;
			State q = tra(i, p);
			if(q.s.top() >= -30000 && q.s.top() <= 30000)
				Q.push(q);
		}
	}
	return false;
}

void solve() {
	if (bfs()) {
		if (p.pathn == 0) printf("Empty sequence\n");
		else {
			for (int i = 0; i < p.pathn - 1; i ++)
				printf("%s ", tr[p.path[i]]);
			printf("%s\n", tr[p.path[p.pathn - 1]]);
		}
	}
	else printf("Impossible\n");
	printf("\n");
}

int main() {
	int cas = 0;
	while (~scanf("%d", &n) && n) {
		init();
		printf("Program %d\n", ++cas);
		solve();
	}
	return 0;
}
