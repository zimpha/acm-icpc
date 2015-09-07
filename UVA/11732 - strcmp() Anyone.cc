#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef long long LL;

const int SIZE = 4000010;
const int MAXN = 1010;

struct Node {
	Node *child, *sibling;
	char ch;
	LL size;
} pool[SIZE], *root, *null, *cnt;

char st[MAXN];
LL ans;

void insert(char s[]) {
	Node *p = root, *t;
	int len = strlen(s);
	for (int i = 0; i <= len; ++ i) {
		for (t = p->child; t !=null; t = t->sibling) {
			if (t->ch == s[i]) break;
		}
		if (t == null) {
			t = cnt ++;
			t->ch = s[i]; t->sibling = p->child;
			t->child = null; p->child = t; t->size = 0;
		}
		ans += (p->size - t->size) * (i << 1 | 1);
		if (i == len) {
			ans += t->size * 2 * (i + 1);
			t->size ++;
		}
		p->size ++; p = t;
	}
}

void init() {
	null = pool; 
	null->child = null->sibling = null;
	null->size = 0; null->ch = 0;
	root = pool + 1; *root = *null; cnt = pool + 2;
	ans = 0;
}

int main() {
	int n, cas = 0;
	while (scanf("%d", &n) == 1 && n) {
		init();
		for (int i = 0; i < n; ++ i) {
			scanf("%s", st);
			insert(st);
		}
		printf("Case %d: %lld\n", ++ cas, ans);
	}
	return 0;
}
