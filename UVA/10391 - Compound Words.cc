#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string s;
	vector<string> v; v.clear();
	while (cin >> s) v.push_back(s);
	map<string, bool> mp; mp.clear();

	for (int i = 0; i < (int)v.size(); ++ i) mp[v[i]] = true;

	vector<string> ret; ret.clear();
	string s1, s2;
	for (int i = 0; i < (int)v.size(); ++ i) {
		for (int j = 1; j < (int)v[i].size(); ++ j) {
			s1 = v[i].substr(0, j);
			s2 = v[i].substr(j, v[i].size() - j);
			if (mp[s1] && mp[s2]) {
				ret.push_back(v[i]);
				break;
			}
		}
	}
	//sort(ret.begin(), ret.end());
	for (int i = 0; i < (int)ret.size(); ++ i) cout << ret[i] << endl;
	return 0;
}
