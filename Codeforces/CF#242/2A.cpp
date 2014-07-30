#include <cctype>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	int cnt = 0;
	for (int i = 0; i < (int)s.size(); ++ i)
		if (isupper(s[i])) cnt ++;
	if (2 * cnt <= n) {
		cnt = n / 2 - cnt;
		cout << cnt << endl;
		for (int i = 0; i < (int)s.size() && cnt; ++ i)
			if (islower(s[i])) cnt --, s[i] = toupper(s[i]);
		cout << s << endl;
	}
	else {
		cnt = cnt - n / 2;
		cout << cnt << endl;
		for (int i = 0; i < (int)s.size() && cnt; ++ i)
			if (isupper(s[i])) cnt --, s[i] = tolower(s[i]);
		cout << s << endl;
	}
	return 0;
}
