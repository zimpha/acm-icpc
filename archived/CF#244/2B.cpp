#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 200000 + 10;

int a[MAXN], n, t, c;

int main() {
	cin >> n >> t >> c;
	multiset<int> S;
	for (int i = 0; i < c; ++ i) {
		cin >> a[i];
		S.insert(a[i]);
	}
	int ret = (*S.rbegin() <= t);
	for (int i = c; i < n; ++ i) {
		cin >> a[i];
		S.erase(S.find(a[i - c]));
		S.insert(a[i]);
		ret += (*S.rbegin() <= t);
	}
	cout << ret << endl;
	return 0;
}
