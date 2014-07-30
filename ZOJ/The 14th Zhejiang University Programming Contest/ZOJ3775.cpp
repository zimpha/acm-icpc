#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(string &s) {
	string t = "";
	for (int i = 0; i < (int)s.length(); ++ i) {
		if (s[i] == '_') t += s;
		else if (s[i] == '!') t += "Hello, world!";
		if (t.length() > s.length()) return false;
	}
	return s == t;
}

int main() {
	int T; cin >> T;
	string s; getline(cin, s);
	while (T --) {
		getline(cin, s);
		if (check(s)) puts("Yes");
		else puts("No");
	}
	return 0;
}
