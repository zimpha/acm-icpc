#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	int ret = 0, rest = 0;
	while (n --) {
		int x; cin >> x;
		if (x > 0) rest += x;
		else {
			if (rest) rest --;
			else ret ++;
		}
	}
	cout << ret << endl;
	return 0;
}
