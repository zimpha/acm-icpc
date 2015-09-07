#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

using namespace std;
const int MAXN = 100000 + 10;
int C[MAXN];

void add(int x, int v) {
	for (int i = x; i < MAXN; i += (i & -i)) C[i] += v;
}


int get(int x) {
	int ret = 0;
	for (int i = x; i; i -= (i & -i)) ret += C[i];
	return ret;
}

int main() {
	int T;
	while (scanf("%d", &T) == 1 && T) {
		memset(C, 0, sizeof(C));
		while (T --) {
			char st[10];
			int a, b, y;
			scanf("%s", st);
			if (st[0] == 'B') {
				scanf("%d%d%d", &a, &b, &y);
				add(a, y); add(b + 1, -y);
			}
			else {
				scanf("%d", &a);
				printf("%d\n", get(a));
			}
		}
	}
	return 0;
}
