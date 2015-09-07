#include <set>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) == 1 && n) {
		multiset <int> S; S.clear();
		long long ret = 0;
		for (int i = 0; i < n; ++ i) {
			int k, x; scanf("%d", &k);
			for (int j = 0; j < k; ++ j) {
				scanf("%d", &x);
				S.insert(x);
			}
			int a = *S.begin();
			S.erase(S.begin());
			int b = *S.rbegin();
			S.erase(-- (S.rbegin().base()));
			ret += abs(a - b);
		}
		printf("%lld\n", ret);
	}
	return 0;
}
