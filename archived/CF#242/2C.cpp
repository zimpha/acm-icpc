#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 10;

int f[MAXN], n, ret;

int main() {
	cin >> n;
	for (int i = 1, x; i <= n; ++ i) {
		f[i] = f[i - 1] ^ i;
		cin >> x; ret ^= x;
	}
	for (int i = 1; i <= n; ++ i) {
		if ((n / i) & 1) ret ^= f[i - 1] ^ f[n % i];
		else ret ^= f[n % i];
	}
	cout << ret << endl;
	return 0;
}
