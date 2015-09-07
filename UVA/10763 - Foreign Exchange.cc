#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
typedef map<PII, int>::iterator iter;

map<PII, int> mp;

inline void Insert(int a, int b) {
	PII t = make_pair(a, b);
	if (mp.count(t)) mp[t] ++;
	else mp[t] = 1;
}

inline bool check() {
	for (iter it = mp.begin(); it != mp.end(); ++ it) {
		PII t = make_pair(it->first.second, it->first.first);
		if (!mp.count(t)) return false;
		if (mp[t] != it->second) return false;
	}
	return true;
}

int main() {
	int n;
	while (scanf("%d", &n) == 1 && n) {
		mp.clear();
		for (int i = 0; i < n; ++ i) {
			int a, b; scanf("%d%d", &a, &b);
			Insert(a, b);
		}
		if (check()) puts("YES");
		else puts("NO");
	}
	return 0;
}
