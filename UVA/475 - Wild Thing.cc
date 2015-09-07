#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string p, s, t;
bool flag;

void check(int pl, int pr, int sl, int sr) {
	if (pl == pr && sl == sr) {
		flag = true;
		return;
	}
	if (pl < pr && p[pl] == '*') {
		int nx = 0;
		for (nx = pl + 1; nx < pr && p[nx] != '*'; ++ nx);
		int len = nx - pl - 1;
		for (int i = sl; i + len <= sr; ++ i) {
			if (p.substr(pl + 1, len) == s.substr(i, len)) {
				check(pl + len + 1, pr, i + len, sr);
			}
			if (flag) return;
		}
	} else if (pl < pr && p[pl] != '*') {
		int nx = 0;
		for (nx = pl + 1; nx < pr && p[nx] != '*'; ++ nx);
		int len = nx - pl;
		if (sl + len <=sr && p.substr(pl, len) == s.substr(sl, len)) {
			check(pl + len, pr, sl + len, sr);
		}
		if (flag) return;
	}
}

int main() {
	int cas = 0;
	while (getline(cin, p)) {
		t = p;
		for (int i = p.size() - 1; i > 0; -- i) {
			if (p[i] == '*' && p[i - 1] == '*') {
				p.erase(p.begin() + i);
			}
		}
		vector <string> ans; ans.clear();
		while (getline(cin, s)) {
			if (s == "") break;
			flag = false;
			if (p == "*") flag = true;
			if (!flag) check(0, p.size(), 0, s.size());
			if (flag) ans.push_back(s);
		}
		if (ans.size()) {
			if (cas) cout << endl; cas ++;
			cout << "MATCHES FOR THE PATTERN: " << t << endl;
			for (int i = 0; i < (int)ans.size(); ++ i) {
				cout << ans[i] << endl;
			}
		}
	}
	return 0;
}
