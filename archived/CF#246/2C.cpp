#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
int a[MAXN], p[MAXN], n;

vector<pair<int, int> > ret;
vector<int> plist;
bool prime[MAXN];

int get(int n) {
	if (n == 2) return 0;
	for (auto a : plist) {
		int b = n - a;
		if (prime[b]) return a;
	}
	return 0;
}

void change(int i, int j) {
	int t = i + get(j - i + 2) - 1;
	ret.push_back(make_pair(i, t));
	ret.push_back(make_pair(t, j));
	ret.push_back(make_pair(i, t));
}

void exchange(int i, int j) {
	a[j] = a[i]; a[i] = i;
	p[a[j]] = j; p[i] = i;
	if (i > j) swap(i, j);
	int len = j - i + 1;
	if (len <= 3) ret.push_back(make_pair(i, j));
	else if (len % 2 == 0) {
		ret.push_back(make_pair(j - 1, j));
		change(i, j - 1);
		ret.push_back(make_pair(j - 1, j));
	}
	else change(i, j);
}

int main() {
	cin >> n;
	for (int i = 2; i <= n; ++ i) prime[i] = true;
	for (int i = 2; i <= n; ++ i) {
		if (prime[i]) {
			plist.push_back(i);
			for (int j = i + i; j <= n; j += i) {
				prime[j] = false;
			}
		}
	}
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
		p[a[i]] = i;
	}
	for (int i = 1; i <= n; ++ i) {
		if (a[i] != i) {
			int now = i;
			while (a[now] != now) {
				int next = p[now];
				exchange(now, p[now]);
				now = next;
			}
		}
	}
	cout << ret.size() << endl;
	for (auto x : ret) {
		assert(prime[x.second - x.first + 1]);
		cout << x.first << " " << x.second << endl;
	}
	return 0;
}
