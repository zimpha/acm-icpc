#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	vector<int> v;
	cin >> n >> k;
	for (int i = 0, x; i < n; ++ i) {
		cin >> x;
		if (x + k <= 5) v.push_back(x);
	}
	cout << v.size() / 3 << endl;
	return 0;
}
