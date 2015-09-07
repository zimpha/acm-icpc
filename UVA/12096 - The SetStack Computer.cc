#include <map>
#include <set>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef set <int> Set;

map <Set, int> IDcache;
vector <Set> Setcache;
stack <int> S;

int ID(Set x) {
	if (IDcache.count(x)) return IDcache[x];
	Setcache.push_back(x);
	return IDcache[x] = Setcache.size() - 1;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		while (!S.empty()) S.pop();
		int N;
		char st[20];
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) {
			scanf("%s", st);
			if ((string)st == "PUSH") S.push(ID(Set()));
			else if ((string)st == "DUP") S.push(S.top());
			else {
				Set x1 = Setcache[S.top()]; S.pop();
				Set x2 = Setcache[S.top()]; S.pop();
				Set X;
				if ((string)st == "UNION") {
					set_union(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(X, X.begin()));
				} else if ((string)st == "INTERSECT") {
					set_intersection(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(X, X.begin()));
				} else if ((string)st == "ADD") {
					X = x2;
					X.insert(ID(x1));
				}
				S.push(ID(X));
			}
			printf("%d\n", (int)Setcache[S.top()].size());
		}
		puts("***");
	}
	return 0;
}
