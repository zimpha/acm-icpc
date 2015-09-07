#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 10000 + 10;

struct Node {
	int l, r;
	bool operator < (const Node &rhs) const {
		return l < rhs.l;
	}
};

vector<Node> A, ret;
int N, M;

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &M); A.clear();
		for (int a, b; scanf("%d%d", &a, &b); ) {
			if (a == 0 && b == 0) break;
			A.push_back((Node){a, b});
		}
		sort(A.begin(), A.end());
		int i, j, l = 0, r = 0, flag = 0;
		N = A.size();
		for (i = 0; i < N && A[i].r <= 0; ++ i);
		if (i < N) {
			ret.clear();
			for (int p; i < N; i = j) {
				for (j = i; j < N && l >= A[j].l; ++ j) 
					if (A[j].r > r) r = A[j].r, p = j;
				if (j == i) break;
				ret.push_back(A[p]); l = r;
				if (l >= M) {flag = 1; break;}
			}
		}
		if (flag) {
			printf("%d\n", (int)ret.size());
			for (int i = 0; i < (int)ret.size(); ++ i) printf("%d %d\n", ret[i].l, ret[i].r);
		} else puts("0");
		if (T) puts("");
	}
	return 0;
}
