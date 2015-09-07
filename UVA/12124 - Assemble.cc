#include <map>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAXN = 1000 + 10;

struct Node {
	int price, quality;
	Node () {}
	Node (int p, int q) : price(p), quality(q) {}
	bool operator < (const Node &rhs) const {
		return price < rhs.price;
	}
};

vector<Node> A[MAXN];
map<string, int> mp;
int N, M, B;

int ID(string s) {
	if (!mp.count(s)) mp[s] = M ++;
	return mp[s];
}

bool check(int lim) {
	int ret = 0;
	for (int i = 0; i < M; ++ i) {
		int cheapest = B + 1;
		for (int j = 0; j < (int)A[i].size(); ++ j)
			if (A[i][j].quality >= lim) cheapest = min(cheapest, A[i][j].price);
		if (cheapest == B + 1) return false;
		ret += cheapest;
		if (ret > B) return false;
	}
	return true;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &N, &B);
		M = 0; mp.clear();
		for (int i = 0; i < N; ++ i) A[i].clear();
		int left = 0, right = 0;
		for (int i = 0; i < N; ++ i) {
			char s1[100], s2[100];
			int p, q;
			scanf("%s%s%d%d", s1, s2, &p, &q);
			right = max(right, q);
			A[ID(s1)].push_back(Node(p, q));
		}
		while (left < right) {
			int mid = (left + right + 1) >> 1;
			if (check(mid)) left = mid;
			else right = mid - 1;
		}
		printf("%d\n", left);
	}
	return 0;
}
