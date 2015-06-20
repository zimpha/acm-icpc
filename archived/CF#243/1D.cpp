#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;

vector<int> XS[MAXN], YS[MAXN];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++ i) {
		int x, y; cin >> x >> y;
		XS[x].push_back(y);
		YS[y].push_back(x);
	}
	for (int i = 0; i < MAXN; ++ i) {
		sort(XS[i].begin(), XS[i].end());
		sort(YS[i].begin(), YS[i].end());
	}
	int ret = 0;
	for (int x = 0; x < MAXN; ++ x) {
		for (auto y : XS[x]) {
			int l = upper_bound(XS[x].begin(), XS[x].end(), y) - XS[x].begin();
			int r = upper_bound(YS[y].begin(), YS[y].end(), x) - YS[y].begin();
			while (l < (int)XS[x].size() && r < (int)YS[y].size()) {
				int yy = XS[x][l], xx = YS[y][r];
				if (xx - x < yy - y) r ++;
				else if (xx - x > yy - y) l ++;
				else {
					ret += binary_search(XS[xx].begin(), XS[xx].end(), yy);
					l ++; r ++;
				}
			}
		}
	}
	cout << ret << endl;
	return 0;
}
