#include <list>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAXN = 100000 + 10;

char st[MAXN];

int main() {
	while (gets(st)) {
		list <char> l;
		list <char> :: iterator it = l.begin();
		int n = strlen(st);
		for (int i = 0; i < n; ++ i) {
			if (st[i] == '[') {
				it = l.begin();
			} else if (st[i] == ']') {
				it = l.end();
			} else {
				l.insert(it, st[i]);
			}
		}
		for (it = l.begin(); it != l.end(); it ++) {
			printf("%c", *it);
		}
		puts("");
	}
	return 0;
}
