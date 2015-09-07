#include <set>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int calc_size(const string &s, const int k) {
	int n = s.length();
	set <string> S; S.clear();
	for (int i = 0; i + k - 1 < n; ++ i) {
		string t = s.substr(i, k);
		S.insert(t);
	}
	return (int)S.size();
}

int check(const string &s) {
	int n = s.length();
	for (int k = 1; k <= n; ++ k) {
		int sz = calc_size(s, k);
		if (sz > k + 1) return k;
	}
	return 0;
}

int main() {
	string st, tmp;
	while (getline(cin, st)) {
		int ret = check(st);
		if (ret == 0) {
			cout << "YES" << endl;
		} else {
			tmp = st;
			for (int i = 0; i < (int)tmp.size(); ++ i) {
				st = tmp.substr(0, i + 1);
				if (check(st)) {
					ret = i + 1;
					break;
				}
			}
			cout << "NO:" << ret << endl;
		}
	}
	return 0;
}
