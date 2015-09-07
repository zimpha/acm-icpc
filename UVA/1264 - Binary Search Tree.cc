#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 20;
const int MOD = 9999991;

struct Node {
	Node *ch[2];
	int s, value;
	Node (int v, Node *n) : value(v) {
		s = 1; ch[0] = ch[1] = n;
	}
	void Update() { s = ch[0]->s + ch[1]->s + 1;}
} *root, *null;

int C[MAXN][MAXN];

void Insert(Node* &o, int x) {
	if (o == null) o = new Node(x, null);
	else {
		Insert(o->ch[x > o->value], x);
		o->Update();
	}
}

int solve(Node *o) {
	if (o == null || o->s == 1) return 1;
	int ret = C[o->s - 1][o->ch[0]->s];
	ret = (LL)ret * solve(o->ch[0]) % MOD * solve(o->ch[1]) % MOD;
	return ret;
}

int main() {
	memset(C, 0, sizeof(C));
	C[1][0] = C[1][1] = 1;
	for (int i = 2; i <= 20; ++ i) {
		for (int j = 1; j <= i; ++ j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		C[i][0] = 1;
	}
	int T; scanf("%d", &T);
	null = new Node(0, 0); null->s = 0; null->ch[0] = null->ch[1] = null;
	while (T --) {
		int N; scanf("%d", &N); root = null;
		for (int i = 0, x; i < N; ++ i) {
			scanf("%d", &x);
			Insert(root, x);
		}
		printf("%d\n", solve(root));
	}
	return 0;
}
