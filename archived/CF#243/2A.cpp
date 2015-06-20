#include <iostream>
#include <algorithm>

using namespace std;

int n, s, a[200];

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; ++ i) cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 1; i < n; ++ i) s -= a[i];
	if (s >= 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
