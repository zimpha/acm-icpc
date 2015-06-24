#include <iostream>
#include <algorithm>
using namespace std;

int a[200][200], n, m;

bool check(int x) {
	for (int l = 0, r = x - 1; l <= r; l ++, r --) {
		for (int i = 0; i < m; ++ i)
			if (a[l][i] != a[r][i]) return false;
	}
	return true;
}

int solve(int x) {
	if (x & 1) return x;
	if (check(x)) return solve(x / 2);
	else return x;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++ i) 
		for (int j = 0; j < m; ++ j)
			cin >> a[i][j];
	cout << solve(n) << endl;
}
