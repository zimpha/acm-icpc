#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
const int INF = 1e9;

struct Node {
	Node *ch[2], *p;
	int size, mx, rev, value;
	Node () {size = rev = 0, value = mx = INF;}
	bool d() {return this == p->ch[1];}
	void setc(Node *c, int d) {ch[d] = c; c->p = this;}
	void markRev() {rev ^= 1; swap(ch[0], ch[1]);}
	void Update() {
		size = ch[0]->size + ch[1]->size + 1;
		mx = min(ch[0]->mx, ch[1]->mx);
		mx = min(mx, value);
	}
	void PushDown();
} *root, *null, pool[MAXN], *stk[MAXN];

int A[MAXN], V[MAXN];
int N, top;

void Node :: PushDown() {
	if (rev) {
		if (ch[0] != null) ch[0]->markRev();
		if (ch[1] != null) ch[1]->markRev();
		rev = 0;
	}
}

inline Node *NewNode(int v) {
	Node *p = stk[-- top];
	p->mx = p->value = v; p->size = 1; p->rev = 0;
	p->ch[0] = p->ch[1] = p->p = null;
	return p;
}

inline void DeleteNode(Node *t) {
	stk[++ top] = t;
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

Node *build_tree(int *l, int *r) {
	if (l >= r) return null;
	if (l + 1 == r) return NewNode(*l);
	int *m = l + (r - l) / 2;
	Node *p = NewNode(*m);
	p->setc(build_tree(l, m), 0);
	p->setc(build_tree(m + 1, r), 1);
	p->Update(); return p;
}

void init() {
	top = 0;
	for (int i = 0; i < MAXN; ++ i) stk[++ top] = pool + i;
	null = new Node(); null->size = null->rev = 0;
	null->p = null->ch[0] = null->ch[1] = null;
	A[0] = A[N + 1] = INF;
	root = build_tree(A, A + N + 2);
}

Node *get_min(Node *p) {
	if (p == null) return null;
	p->PushDown();
	if (p->ch[0] != null && p->mx == p->ch[0]->mx) return get_min(p->ch[0]);
	if (p->mx == p->value) return p;
	if (p->ch[1] != null && p->mx == p->ch[1]->mx) return get_min(p->ch[1]);
	return null;
}

bool cmp(int a, int b) {
	if (V[a] == V[b]) return a < b;
	else return V[a] < V[b];
}

int main() {
	while (scanf("%d", &N) == 1 && N) {
		for (int i = 1; i <= N; ++ i) {
			scanf("%d", &V[i]); A[i] = i;
		}
		sort(A + 1, A + N + 1, cmp);
		for (int i = 1; i <= N; ++ i) V[A[i]] = i;
		for (int i = 1; i <= N; ++ i) A[i] = V[i];
		init();
		for (int i = 0; i < N; ++ i) {
			if (i) putchar(' ');
			Node *L, *R;
			Splay(Select(0));
			Splay(get_min(root), root);
			L = root->ch[1]->ch[0]; R = root->ch[1]->ch[1];
			L->markRev();
			printf("%d", L->size + 1 + i);
			if (L == null) root->setc(R, 1);
			else {
				root->setc(L, 1); Splay(L);
				Splay(Select(root->size - 1));
				root->setc(R, 1); Splay(R);
			}
		}
		puts("");
	}
	return 0;
}
