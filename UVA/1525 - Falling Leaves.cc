#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
const int MAXN = 30;

int L[MAXN], R[MAXN];
int N, root;

int Find(int x, int rt) {
	if (x < rt && L[rt] != -1) return Find(x, L[rt]);
	else if (x > rt && R[rt] != -1) return Find(x, R[rt]);
	else return rt;
}

void print(int rt) {
	if (rt == -1) return;
	putchar(rt + 'A');
	print(L[rt]); print(R[rt]);
}

int main() {
	string t, st;
	while (cin >> t) {
		N = 0; st = t;
		while (cin >> t) {
			if (t == "*" || t == "$") break;
			st += t;
		}
		memset(L, -1, sizeof(L)); memset(R, -1, sizeof(R));
		for (int i = st.size() - 1; i >= 0; -- i) {
			if (i == (int)st.size() - 1) {
				root = st[i] - 'A';
				continue;
			}
			int fa = Find(st[i] - 'A', root);
			if (st[i] - 'A' < fa) L[fa] = st[i] - 'A';
			else R[fa] = st[i] - 'A';
		}
		print(root); puts("");
	}
	return 0;
}
