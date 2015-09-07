#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 200000 + 10;
const int INF = 1 << 30;

struct Node {
    Node *ch[2], *p;
    int size, value, rev;
    Node() {size = 0; value = -INF;}
    bool d() {return this == p->ch[1];}
    void setc(Node *c, int d) {ch[d] = c; c->p = this;}
    void markRev() {
        rev^=1; swap(ch[0], ch[1]);
    }
    void Update() {
        size = ch[0]->size + ch[1]->size + 1;
    }
}*null, *root, pool[MAXN], *cnt;

int A[MAXN], N, M;

inline Node *New_Node(int v) {
	cnt->value = v; cnt->size = 1; cnt->rev = 0;
	cnt->ch[0] = cnt->ch[1] = cnt->p = null;
	return cnt ++;
}

inline void PushDown(Node* t) {
	if (t == null) return;
	if (t->rev) {
		if (t->ch[0] != null) t->ch[0]->markRev();
		if (t->ch[1] != null) t->ch[1]->markRev();
		t->rev = 0;
	}
}

inline Node *rot(Node *t) {
    Node *p = t->p;
    PushDown(p); PushDown(t);
    int d = t->d();
    p->p->setc(t, p->d());
    p->setc(t->ch[!d], d);
    t->setc(p, !d);
    p->Update();
    if (p == root) root = t;
    return t;
}

inline void Splay(Node* o, Node *f) {
	for (PushDown(o); o->p != f; ) {
		if (o->p->p != f) o->d() == o->p->d() ? rot(o->p) : rot(o);
		rot(o);
	}
	o->Update();
}

inline Node *Select(int k) {
    for (Node *t = root;;) {
        PushDown(t);
        int c = t->ch[0]->size;
        if (k == c) return t;
        if (k > c) k -= c + 1, t = t->ch[1];
        else t = t->ch[0];
    }
    return null;
}

inline Node *get_seq(int l, int r) { //(l, r)
	Node *L = Select(l); Splay(L, null);
	Node *R = Select(r); Splay(R, root);
	return root->ch[1]->ch[0];
}

Node *build_tree(int *l, int *r) {
	if (l >= r) return null;
	if (l + 1 == r) return New_Node(*l);
	int *m = (r - l) / 2 + l;
	Node *p = New_Node(*m);
	p->setc(build_tree(l, m), 0);
	p->setc(build_tree(m + 1, r), 1);
	p->Update(); return p;
}

void init() {
	cnt = pool; null = New_Node(INF);
	null->size = 0; null->ch[0] = null->ch[1] = null->p = null;
	A[0] = A[N + 1] = INF;
	root = build_tree(A, A + N + 2);
}

void print(Node *p) {
	PushDown(p);
	if (p->ch[0] != null) print(p->ch[0]);
	printf("%d\n", p->value);
	if (p->ch[1] != null) print(p->ch[1]);
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++ i) A[i] = i;
	init();
	while (M --) {
		int a, b; scanf("%d%d", &a, &b);
		int s = b - a + 1;
		Node *t = get_seq(a - 1, b + 1);
		t->markRev();
		t->p->setc(null, 0); Splay(root->ch[1], null);
		get_seq(N - s, N - s + 1);
		root->ch[1]->setc(t, 0); Splay(t, null);
	}
	print(get_seq(0, N + 1));
	return 0;
}
