#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T, N, M; cin >> T;
	for (int cas = 1; cas <= T; ++ cas) {
		cin >> N >> M;
		map<string, string> mp; mp.clear();
		for (int i = 0; i < N; ++ i) {
			string s1, s2;
			cin >> s1;
			s2 = s1;
			if (s1.length() > 2) {
				sort(s1.begin() + 1, s1.end() - 1);
			}
			mp[s1] = s2;
		}
		string line; getline(cin, line);
		cout << "Case #" << cas << ":\n";
		while (M --) {
			getline(cin, line);
			string s1 = "", s2 = "";
			bool f = true;
			for (int i = 0; i < (int)line.size(); ++ i) {
				if (line[i] != ' ') {
					s1 = "";
					for (; i < (int)line.size() && line[i] != ' '; ++ i) {
						s1 += line[i];
					}
					if (s1.size() > 2) sort(s1.begin() + 1, s1.end() - 1);
					if (!f) cout << " ";
					else f = false;
					cout << mp[s1];
				}
			}
			cout << endl;
		}
	}
	return 0;
}

