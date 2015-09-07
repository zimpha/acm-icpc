#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 110;
const string ZERO = (string)"00000000000";
const string NINE = (string)"99999999999";

struct Node {
	Node *go[10];
	string name;
	bool push;
	Node() {}
	Node(string p) {
		for (int i = 0; i < 10; ++ i) this->go[i] = NULL;
		this->name = p; this->push = true;
	}
};

vector <string> ans;
Node *root;
string A[MAXN], B[MAXN], plan[MAXN];
int cnt;

inline void make(string &s1, string &s2) {
	int n1 = s1.size(), n2 = s2.size();
	for (int i = n1 - n2 - 1; i >= 0; -- i) {
		s2 = s1[i] + s2;
	}
}

inline bool same(string &s, int st, int ed, char c){
	for (int i = st; i < ed; ++ i) {
		if (s[i] != c) return false;
	}
	return true;
}

inline void PushDown(Node *p) {
	for (int i = 0; i < 10; ++ i) {
		if (p->go[i] == NULL) {
			p->go[i] = new Node(p->name);
		} else {
			p->go[i]->name = p->name;
			p->go[i]->push = true;
		}
	}
	p->push = false;
}	

void Insert(Node *p, string s1, string s2, string v, int dep, int n) {
	if (same(s1, dep, n, '0') && same(s2, dep, n, '9')) {
		p->name = v; p->push = true;
		return;
	}
	if (p->push == true) {
		PushDown(p);
	}
	for (char i = s1[dep]; i <= s2[dep]; ++ i) {
		int o = i - '0';
		Insert(p->go[o], i == s1[dep] ? s1 : ZERO, i == s2[dep] ? s2 : NINE, v, dep + 1, n);
	}
	string ret = p->go[0]->name;
	bool flag = true;
	for (int i = 0; i < 10; ++ i) {
		if (ret != p->go[i]->name) {
			flag = false;
		}
	}
	p->name = flag ? ret : "";
}

void query(Node *p, string s) {
	if (p->name != "") {
		if (p->name != "invalid") {
			if (p == root) {
				for (char i = '0'; i <= '9'; ++ i) {
					ans.push_back((string)"" + i + " " + p->name);
				}
			}
			else {
				ans.push_back(s + " " + p->name);
			}
		}
		return;
	}
	for (int i = 0; i < 10; ++ i) {
		query(p->go[i], s + (char)(i + '0'));
	}
}

void Recycle(Node *p) {
	if (p == NULL) return;
	for (int i = 0; i < 10; ++ i) {
		Recycle(p->go[i]);
	}
	free(p);
}

int main() {
	int n, cas = 0;
	while (cin >> n) {
		if (cas ++) cout << endl;
		root = new Node("invalid");
		for (int i = 0; i < n; ++ i) {
			cin >> A[i] >> B[i];
			cin >> B[i] >> plan[i];
			make(A[i], B[i]);
		}
		for (int i = n - 1; i >= 0; -- i) {
			Insert(root, A[i], B[i], plan[i], 0, A[i].size());
		}
		ans.clear();
		query(root, "");
		cout << ans.size() << endl;
		for (int i = 0; i < (int)ans.size(); ++ i) {
			cout << ans[i] << endl;
		}
		Recycle(root);
	}
	return 0;
}
