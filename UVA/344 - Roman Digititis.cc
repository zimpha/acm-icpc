#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

string Change(int n) {
	string s = "";
	while (n >= 1000) s += "M", n -= 1000;
	if (n >= 900) s += "CM", n -= 900;
	if (n >= 500) s += "D", n -= 500;
	if (n >= 400) s += "CD", n -= 400;
	while (n >= 100) s += "C", n -= 100;
	if (n >= 90) s += "XC", n -= 90;
	if (n >= 50) s += "L", n -= 50;
	if (n >= 40) s += "XL", n -= 40;
	while (n >= 10) s += 'X', n -= 10;
	if (n >= 9) s += "IX", n -= 9;
	if (n >= 5) s += "V", n -= 5;
	if (n >= 4) s += "IV", n -= 4;
	while (n) s += "I", n --;
	return s;
}

int main() {
	int N;
	while (scanf("%d", &N) == 1 && N) {
		int i = 0, v = 0, x = 0, l = 0, c = 0;
		for (int n = 1; n <= N; ++ n) {
			string ret = Change(n);
			for (int j = 0; j < (int)ret.size(); ++ j) {
				i += (ret[j] == 'I');
				v += (ret[j] == 'V');
				x += (ret[j] == 'X');
				l += (ret[j] == 'L');
				c += (ret[j] == 'C');
			}
		}
		printf("%d: %d i, %d v, %d x, %d l, %d c\n", N, i, v, x, l, c);
	}
	return 0;
}
