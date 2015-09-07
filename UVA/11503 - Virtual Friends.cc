#include <map>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAXN = 200000;

map<string, int> Table;
int fa[MAXN], size[MAXN], N;

int getid(char s[]) {
	if (Table.find((string)s) == Table.end()) Table[(string)s] = N ++;
	return Table[(string)s];
}

int Find(int x) {
	if (x != fa[x]) fa[x] = Find(fa[x]);
	return fa[x];
}

int solve(int a, int b) {
	a = Find(a); b = Find(b);
	if (a != b) {
		fa[a] = b; size[b] += size[a];
	}
	return size[b];
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int M; scanf("%d", &M);
		for (int i = 0; i < MAXN; ++ i) fa[i] = i, size[i] = 1;
		Table.clear(); N = 0;
		while (M --) {
			char s1[30], s2[30];
			scanf("%s%s", s1, s2);
			int a = getid(s1), b = getid(s2);
			printf("%d\n", solve(a, b));
		}
	}
	return 0;
}
