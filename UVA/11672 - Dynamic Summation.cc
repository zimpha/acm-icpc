#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 2000000 + 10;

struct Node {
	Node *ch[2], *p;
	int size, value;
	LL sum;
	Node () {sum = size = value = 0;}
	bool d() {return this == p->ch[1];}
	void setc(Node *c, int d) {ch[d] = c; c->p = this;}
	void Update() {
		size = ch[0]->size + ch[1]->size + 1;
		sum = ch[0]->sum + ch[1]->sum + value;
	}
} *root, *null, pool[MAXN], *stk[MAXN];

int B[MAXN], N, top;

inline Node *NewNode(int v) {
	Node *p = stk[-- top];
	p->ch[0] = p->ch[1] = p->p = null;
	p->size = 1; p->sum = p->value = v;
	return p;
}

inline void DeleteNode(Node *p) {
	stk[top ++] = p;
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

inline void Splay(Node* o, Node *f = null) { //make o become f's son, if f == null, then o become root
	for (; o->p != f; ) {
		if (o->p->p != f) o->d() == o->p->d() ? rot(o->p) : rot(o);
		rot(o);
	}
	o->Update();
}

inline Node *Select(int k) { // find the kth element 0-based
    for (Node *t = root;;) {
        int c = t->ch[0]->size;
        if (k == c) return t;
        if (k > c) k -= c + 1, t = t->ch[1];
        else t = t->ch[0];
    }
    return null;
}

inline Node *get_seq(int l, int r) { //get subsequene (l, r)
	Node *L = Select(l); Splay(L);
	Node *R = Select(r); Splay(R, root);
	return root->ch[1]->ch[0];
}

Node *build_tree(int *l, int *r) {
	if (l >= r) return null;
	if (l + 1 == r) return NewNode(*l);
	int *m = (r - l) / 2 + l;
	Node *p = NewNode(*m);
	p->setc(build_tree(l, m), 0);
	p->setc(build_tree(m + 1, r), 1);
	p->Update(); return p;
}

void DeleteTree(Node *p) {
	if (p == null) return;
	DeleteTree(p->ch[0]);
	DeleteTree(p->ch[1]);
	DeleteNode(p);
}

void init() {
	for (top = 0; top < MAXN; ++ top) stk[top] = pool + top;
	null = new Node; null->sum = null->value = null->size = 0;
	null->ch[0] = null->ch[1] = null->p = null;
	root = NewNode(0); Node *end = NewNode(0);
	root->setc(end, 1); Splay(end);
}

void INSERT() {
	int p, n, r, m, a, c;
	scanf("%d%d%d%d%d%d", &p, &n, &r, &m, &a, &c);
	for (int i = 0; i < r; ++ i) scanf("%d", &B[i]);
	for (int i = r; i < n; ++ i) {
		B[i] = ((LL)B[i - r] * a + c) % m;
		c = (((LL)B[i - r] * a + c) / m) % m;
	}
	Node *t_root = build_tree(B, B + n);
	get_seq(p, p + 1);
	root->ch[1]->setc(t_root, 0); Splay(t_root);
}

void SUM() {
	int i, j; scanf("%d%d", &i, &j); i ++, j ++;
	Node *p = get_seq(i - 1, j + 1);
	printf("%lld\n", p->sum);
}

void DELETE() {
	int i, j; scanf("%d%d", &i, &j); i ++, j ++;
	Node *p = get_seq(i - 1, j + 1);
	root->ch[1]->setc(null, 0); Splay(root->ch[1]);
	DeleteTree(p);
}

int main() {
	int cas = 0;
	while (scanf("%d", &N) == 1 && N) {
		init();
		printf("Scenario %d:\n", ++ cas);
		while (N --) {
			char st[100]; scanf("%s", st);
			if (st[0] == 'i') INSERT();
			else if (st[0] == 's') SUM();
			else if (st[0] == 'd') DELETE();
		}
		puts("");
	}
	return 0;
}
