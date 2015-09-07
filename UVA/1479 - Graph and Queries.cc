#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int INF = 1 << 30;
const int MAXN = 20000 + 10;
const int MAXM = 60000 + 10;
const int MAXQ = 500000 + 10;

struct Node {
	int size, value, pri;
	Node *ch[2];
	Node (int v, Node *n) : value(v) {
		pri = rand() % INF - 1; size = 1;
		ch[0] = ch[1] = n;
	}
	void Update() {
		size = ch[0]->size + 1 + ch[1]->size;
	}
} *root[MAXN], *null;

struct CMD {
	int type, x, v;
} command[MAXQ];

struct EDGE {
	int u, v;
} edge[MAXM];

int weight[MAXN], fa[MAXN];
bool removed[MAXM];
int N, M, Q;

void rot(Node* &o, int d) {
	Node *k = o->ch[d];
	o->ch[d] = k->ch[!d];
	k->ch[!d] = o;
	o->Update(); k->Update(); o = k;
}

void Insert(Node* &o, int value) {
	if (o == null) o = new Node(value, null);
	else {
		int d = value > o->value;
		Insert(o->ch[d], value);
		if (o->ch[d]->pri < o->pri) rot(o, d);
		else o->Update();
	}
}

void Delete(Node* &o, int value) {
	if (o == null) return;
	if (o->value == value) {
		int d = o->ch[1]->pri < o->ch[0]->pri;
		if (o->ch[d] == null) {delete o; o = null; return;}
		rot(o, d);
		Delete(o->ch[!d], value);
	} else {
		int d = value > o->value;
		Delete(o->ch[d], value);
	}
	o->Update();
}

int Kth(Node *o, int k) {
	int s = o->ch[1]->size + 1;
	if (k == s) return o->value;
	if (k < s) return Kth(o->ch[1], k);
	else return Kth(o->ch[0], k - s);
}

void init() {
	null = new Node(0, 0); null->pri = INF;;
	null->size = 0; null->ch[0] = null->ch[1] = null;
}

void Merge(Node* &src, Node* &dest) {
	if (src->ch[0] != null) Merge(src->ch[0], dest);
	if (src->ch[1] != null) Merge(src->ch[1], dest);
	Insert(dest, src->value);
}

void DeleteTree(Node* &o) {
	if (o->ch[0] != null) DeleteTree(o->ch[0]);
	if (o->ch[1] != null) DeleteTree(o->ch[1]);
	delete o;
}

int findset(int x) {
	if (x != fa[x]) fa[x] = findset(fa[x]);
	return fa[x];
}

inline void ADDEDGE(int x) {
	int u = findset(edge[x].u);
	int v = findset(edge[x].v);
	if (u == v) return;
	if (root[u]->size > root[v]->size) {
		fa[v] = u;
		Merge(root[v], root[u]);
	} else {
		fa[u] = v;
		Merge(root[u], root[v]);
	}
}

inline int QUERY(int x, int k) {
	int u = findset(x);
	if (k <= 0 || k > root[u]->size) return 0;
	else return Kth(root[u], k);
}

inline void CHANGE(int x, int v) {
	int u = findset(x);
	Delete(root[u], weight[x]);
	Insert(root[u], v);
	weight[x] = v;
}

int main() {
	srand(time(NULL)); init();
	int cas = 0;
	while (scanf("%d%d", &N, &M) == 2 && N) {
		for (int i = 1; i <= N; ++ i) {
			scanf("%d", &weight[i]);
		}
		for (int i = 1; i <= M; ++ i) scanf("%d%d", &edge[i].u, &edge[i].v), removed[i] = 0;
		char st[10]; Q = 0;
		while (scanf("%s", st) == 1 && st[0] != 'E') {
			int type, x, p = 0, v = 0; scanf("%d", &x);
			if (st[0] == 'D') type = 1, removed[x] = 1;
			else if (st[0] == 'Q') scanf("%d", &p), type = 2;
			else if (st[0] == 'C') {
				scanf("%d", &v); type = 3;
				p = weight[x]; weight[x] = v;
			}
			command[++ Q] = (CMD){type, x, p};
		}
		for (int i = 1; i <= N; ++ i) {
			fa[i] = i;
			root[i] = new Node(weight[i], null);
		}
		for (int i = 1; i <= M; ++ i) if (!removed[i]) ADDEDGE(i);
		long long ret = 0, cnt = 0;
		for (int i = Q; i; -- i) {
			if (command[i].type == 1) ADDEDGE(command[i].x);
			if (command[i].type == 2) {
				ret += QUERY(command[i].x, command[i].v);
				cnt ++;
			}
			if (command[i].type == 3) CHANGE(command[i].x, command[i].v);
		}
		printf("Case %d: %.6lf\n", ++ cas, (double)ret/(double)cnt);
		for (int i = 1; i <= N; ++ i) DeleteTree(root[i]);
	}
	return 0;
}
