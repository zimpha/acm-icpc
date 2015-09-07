#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;
const int SIZE = 400000 + 10;
const int MAXN = 200000 + 10;
const int seed = 5;

struct Node {
	ULL a, b;
	int size;
	bool value, rev;
	Node *ch[2], *p;
	Node () {size = value = rev = 0;}
	bool d() {return p->ch[1] == this;}
	void setc(Node *c, int d) {ch[d] = c; c->p = this;}
	void markRev() {rev ^= 1; swap(ch[0], ch[1]); swap(a, b);}
	void Update();
	void PushDown();
} *root, *null, pool[SIZE];

Node *stk[SIZE];
ULL pp[SIZE];
bool A[MAXN];
int N, M, top;

void Node :: Update() {
	size = ch[0]->size + ch[1]->size + 1;
	a = ch[0]->a + (value + 1) * pp[ch[0]->size] + ch[1]->a * pp[ch[0]->size + 1];
	b = ch[1]->b + (value + 1) * pp[ch[1]->size] + ch[0]->b * pp[ch[1]->size + 1];
}

void Node :: PushDown() {
	if (rev) {
		if (ch[0] != null) ch[0]->markRev();
		if (ch[1] != null) ch[1]->markRev();
		rev = 0;
	}
}

inline Node* NewNode(bool v) {
	Node *p = stk[-- top];
	p->value = v; p->size = 1; p->rev = 0;
	p->ch[0] = p->ch[1] = p->p = null;
	p->a = p->b = (int)v + 1;
	return p;
}

inline void DeleteNode(Node *t) {
	stk[top ++] = t;
}

inline Node* rot(Node *t) {
	Node *p = t->p;
	p->PushDown(); t->PushDown();
	int d = t->d();
	p->p->setc(t, p->d());
	p->setc(t->ch[!d], d);
	t->setc(p, !d);
	p->Update();
	if (p == root) root = t;
	return t;
}

inline void Splay(Node *o, Node *f = null) {
	for (o->PushDown(); o->p != f; ) {
		if (o->p->p != f) o->d() == o->p->d() ? rot(o->p) : rot(o);
		rot(o);
	}
	o->Update();
}

inline Node *Select(int k) {
	for (Node *t = root; ; ) {
		t->PushDown();
		int c = t->ch[0]->size;
		if (k == c) return t;
		if (k > c) k -= c + 1, t = t->ch[1];
		else t = t->ch[0];
	}
	return null;
}

inline Node *get_seq(int l, int r) {
	Node *L = Select(l); Splay(L);
	Node *R = Select(r); Splay(R, root);
	return root->ch[1]->ch[0];
}

Node *build_tree(bool *l, bool *r) {
	if (l >= r) return null;
	if (l + 1 == r) return NewNode(*l);
	bool *m = l + (r - l) / 2;
	Node *p = NewNode(*m);
	p->setc(build_tree(l, m), 0);
	p->setc(build_tree(m + 1, r), 1);
	p->Update(); return p;
}

void print(Node *t) {
	if (t == null) return;
	t->PushDown();
	print(t->ch[0]);
	printf("%d", t->value);
	print(t->ch[1]);
}

void init() {
	top = 0;
	for (int i = 0; i < SIZE; ++ i) stk[top ++] = pool + i;
	null = new Node();
	null->size = null->rev = null->a = null->b = 0;
	null->p = null->ch[0] = null->ch[1] = null;
	A[0] = A[N + 1] = 0;
	root = build_tree(A, A + N + 2);
}

inline void INSERT() {
	int p; char c;
	scanf("%d %c", &p, &c);
	get_seq(p, p + 1);
	Node *t = NewNode(c - '0');
	root->ch[1]->setc(t, 0);
	Splay(t); N ++;
}

inline void DELETE() {
	int p; scanf("%d", &p);
	Node *t = get_seq(p - 1, p + 1);
	root->ch[1]->setc(null, 0); Splay(root->ch[1]);
	DeleteNode(t); N --;
}

inline void REVERSE() {
	int p1, p2; scanf("%d%d", &p1, &p2);
	Node *t = get_seq(p1 - 1, p2 + 1);
	t->markRev(); Splay(t);
}

ULL get_hash(int l, int r) {
	Node *p = get_seq(l - 1, r + 1);
	return p->a;
}

inline void LCP() {
	int p1, p2; scanf("%d%d", &p1, &p2);
	int left = 0, right = min(N - p1, N - p2) + 1;
	while (left < right) {
		int mid = (left + right + 1) >> 1;
		ULL h1 = get_hash(p1, p1 + mid - 1);
		ULL h2 = get_hash(p2, p2 + mid - 1);
		if (h1 == h2) left = mid;
		else right = mid - 1;
	}
	printf("%d\n", left);
}

int main() {
	pp[0] = 1;
	for (int i = 1; i < SIZE; ++ i) pp[i] = seed * pp[i - 1];
	while (scanf("%d%d", &N, &M) == 2) {
		getchar();
		for (int i = 1; i <= N; ++ i) {
			char c = getchar();
			A[i] = c - '0';
		}
		init();
		while (M --) {
			int p; scanf("%d", &p);
			if (p == 1) INSERT();
			else if (p == 2) DELETE();
			else if (p == 3) REVERSE();
			else if (p == 4) LCP();
		}
	}
	return 0;
}
