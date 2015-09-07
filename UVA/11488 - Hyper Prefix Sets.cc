#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int SIZE=10000010;

struct node {
	node *ch[2];
	int size;
}*root;
int ret;

node *new_node() {
	node *p=new(node);
	for (int i=0; i<2; i++) p->ch[i]=NULL;
	p->size=0; return p;
}

void insert(char *s) {
	node *p=root;
	for (int i=0; s[i]; i++) {
		if (p->ch[s[i]-'0']==NULL) p->ch[s[i]-'0']=new_node();
		p=p->ch[s[i]-'0']; p->size++;
	}
}

void query(int dep, node *p) {
	if (p==NULL) return;
	ret=max(ret, dep*(int)p->size);
	for (int i=0; i<2; i++) {
		query(dep+1, p->ch[i]);
	}
	free(p);
}

int main() {
	int T, n; scanf("%d", &T);
	for (int cas=1; cas<=T; cas++) {
		scanf("%d", &n);
		root=new_node();
		for (int i=0; i<n; i++) {
			char s[300]; scanf("%s", s);
			insert(s);
		}
		ret=0; query(0, root);
		printf("%d\n", ret);
	}
	return 0;
}
