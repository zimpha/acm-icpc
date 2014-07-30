#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200000 + 10;
const int SIZE = 400000 + 10;

int gcd(int a, int b) {
	if (a == -1) return b;
	else if (b == -1) return a;
	if (b == 0) return a;
	else return gcd(b, a % b);
}

struct Node {
	Node *ch[2], *p;
	int size, g[2], value, status;
	Node() {size = 0; g[0] = g[1] = value = -1;}
	bool d() {return this == p->ch[1];}
	void setc(Node *c, int d) {ch[d] = c; c->p = this;}
	void Update() {
		size = ch[0]->size + ch[1]->size + 1;
		g[0] = gcd(ch[0]->g[0], ch[1]->g[0]);
		g[1] = gcd(ch[0]->g[1], ch[1]->g[1]);
		g[status] = gcd(g[status], value);
		g[!status] = gcd(g[!status], -1);
	}
} *null, *root, pool[SIZE], *stk[SIZE];

int A[MAXN], S[MAXN], N, M, top;

inline Node *newNode(int value, int status) {
	Node *now = stk[-- top];
	now->value = value; now->status = status; now->size = 1;
	now->g[status] = value; now->g[!status] = -1;
	now->ch[0] = now->ch[1] = now->p = null;
	return now;
}

inline void deleteNode(Node *now) {
	stk[top ++] = now;
}

inline Node *rot(Node *t) {
	Node *p = t->p;
	int d = t->d();
	p->p->setc(t, p->d());
	p->setc(t->ch[!d], d);
	t->setc(p, !d);
	p->Update();
	if (p == root) root = t;
	return t;
}

inline void Splay(Node *o, Node *f) {
	for (; o->p != f; ) {
		if (o->p->p != f) o->d() == o->p->d() ? rot(o->p) : rot(o);
		rot(o);
	}
	o->Update();
}

inline Node *Select(int k) {
	for (Node *t = root; ;) {
		int c = t->ch[0]->size;
		if (k == c) return t;
		if (k > c) k -= c + 1, t = t->ch[1];
		else t = t->ch[0];
	}
	return null;
}

inline Node *get_seq(int l, int r) {//(l, r)
	Node *L = Select(l); Splay(L, null);
	Node *R = Select(r); Splay(R, root);
	return root->ch[1]->ch[0];
}

Node *buildTree(int l, int r) {
	if (l >= r) return null;
	if (l + 1 == r) return newNode(A[l], S[l]);
	int m = (r - l) / 2 + l;
	Node *p = newNode(A[m], S[m]);
	p->setc(buildTree(l, m), 0);
	p->setc(buildTree(m + 1, r), 1);
	p->Update(); return p;
}

void init(int n) {
	top = 0;
	for (int i = 0; i < n; ++ i) stk[top ++] = pool + i;
	null = newNode(-1, 0); null->status = 0;
	null->size = 0; null->value = null->g[0] = null->g[1] = -1;
	null->ch[0] = null->ch[1] = null->p = null;
	A[0] = A[N + 1] = -1; S[0] = S[N + 1] = 0;
	root = buildTree(0, N + 2);
}

void Query() {
	int L, R, s; scanf("%d%d%d", &L, &R, &s);
	Node *p = get_seq(L - 1, R + 1);
	printf("%d\n", p->g[s]);
	Splay(p, null);
}

void Insert() {
	int i, v, s; scanf("%d%d%d", &i, &v, &s);
	Node *t = newNode(v, s);
	get_seq(i, i + 1);
	root->ch[1]->setc(t, 0); Splay(t, null);
}

void Erase() {
	int i; scanf("%d", &i);
	get_seq(i - 1, i + 1);
	deleteNode(root->ch[1]->ch[0]);
	root->ch[1]->setc(null, 0);
}

void ModifyS() {
	int i; scanf("%d", &i);
	Node *t = get_seq(i - 1, i + 1);
	t->status = 1 - t->status;
	swap(t->g[0], t->g[1]);
	Splay(t, null);
}

void ModifyV() {
	int i, v; scanf("%d%d", &i, &v);
	Node *t = get_seq(i - 1, i + 1);
	t->value = v;
	t->Update();
	Splay(t, null);
}

int main() {
	while (scanf("%d%d", &N, &M) == 2) {
		for (int i = 1; i <= N; ++ i) scanf("%d%d", A + i, S + i);
		init(N + M + 100);
		while (M --) {
			char st[10]; scanf("%s", st);
			if (st[0] == 'Q') Query();
			else if (st[0] == 'I') Insert();
			else if (st[0] == 'D') Erase();
			else if (st[0] == 'R') ModifyS();
			else if (st[0] == 'M') ModifyV();
		}
	}
	return 0;
}
