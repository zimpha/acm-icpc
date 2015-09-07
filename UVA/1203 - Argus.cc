#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node {
	int x, t, id;
	node () {}
	node (int x, int t, int id) : x(x), t(t), id(id) {}
	bool operator < (const node &oth) const {
		return (x > oth.x || (x == oth.x && id > oth.id));
	}
};

int main() {
	char st[100];
	priority_queue <node> Q;
	while (!Q.empty()) Q.pop();
	while (scanf("%s", st) == 1 && st[0] != '#') {
		int x, t; scanf("%d%d", &x, &t);
		Q.push(node(t, t, x));
	}
	int k; scanf("%d", &k);
	while (k --) {
		node tmp = Q.top(); Q.pop();
		printf("%d\n", tmp.id);
		tmp.x += tmp.t;
		Q.push(tmp);
	}
	return 0;
}
