#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	string name;
	int num;
	Node () {}
	Node (string s, int n) : name(s), num(n) {}
	bool operator < (const Node &rhs) const {
		return num < rhs.num;
	}
};

int main() {
	int T; cin >> T;
	while (T --) {
		int n;
		vector <Node> P; P.clear();
		cin >> n;
		for (int i = 0; i < n; ++ i) {
			string s;
			int num;
			cin >> s >> num;
			P.push_back(Node(s, num));
		}
		sort(P.begin(), P.end());
		bool flag = false;
		for (int i = 0, j; i < (int)P.size(); i = j) {
			for (j = i; j < (int)P.size() && P[i].num == P[j].num; ++ j);
			if (j - i == 1) {
				cout << P[i].name << endl;
				flag = true;
				break;
			}
		}
		if (!flag) cout << "Nobody wins.\n";
	}
	return 0;
}
