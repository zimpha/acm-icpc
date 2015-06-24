#include <iostream>
#include <algorithm>
using namespace std;

int a[30], b[30], son[30], n;

bool solve(int dep) {
	if (dep == n) {
		for (int i = 0; i < n; ++ i)
			if (a[i] > 1 || (b[i] > 1 && son[i] < 2)) return false;
		return true;
	}
	for (int i = 0; i < dep; ++ i) {
		if (a[dep] < a[i] - (!son[i])) {
			a[i] -= a[dep]; son[i] ++;
			if (solve(dep + 1)) return true;
			a[i] += a[dep]; son[i] --;
		}
	}
	return false;
}

int main() {
	cin >> n;
	bool flag = 1;
	for (int i = 0; i < n; ++ i) {
		cin >> a[i];
		flag &= (a[i] != 2);
	}
	sort(a, a + n);
	reverse(a, a + n);
	copy(a, a + n, b);
	flag &= (a[0] == n);
	fill(son, son + n, 0);
	if (flag && solve(1)) puts("YES");
	else puts("NO");
}
