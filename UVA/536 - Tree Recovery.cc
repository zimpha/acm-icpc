#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

void solve(string A, string B) {
	if (!A.size()) return;
	int p = B.find(A[0]);
	int q = B.size() - p - 1;
	solve(A.substr(1, p), B.substr(0, p));
	solve(A.substr(1 + p, q), B.substr(p + 1, q));
	putchar(A[0]);
}

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		solve(s1, s2);
		puts("");
	}
	return 0;
}
