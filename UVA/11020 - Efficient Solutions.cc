#include <set>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct Node {
	int x, y;
	bool operator < (const Node &rhs) const {
		return (x < rhs.x || (x == rhs.x && y < rhs.y));
	}
};

multiset <Node> S;

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		if (cas > 1) puts("");
		printf("Case #%d:\n", cas);
		int N; scanf("%d", &N);
		S.clear();
		while (N --) {
			Node P; scanf("%d%d", &P.x, &P.y);
			multiset <Node> :: iterator it;
			it = S.lower_bound(P);
			if (it == S.begin() || (-- it)->y > P.y) {
				S.insert(P);
				it = S.upper_bound(P);
				while (it != S.end() && it->y >= P.y) S.erase(it ++);
			}
			printf("%d\n", (int)S.size());
		}
	}
	return 0;
}
