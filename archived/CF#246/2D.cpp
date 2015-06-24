#include <cstring>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

char s[MAXN];
int Z[MAXN], sum[MAXN];

void calcZ(const char *s, int n, int Z[]) {
	for (int i = 0; i < n; ++ i) Z[i] = 0;
	for (int i = 1, x = 0, y = 0; i < n; ++ i) {
		if (i <= y) Z[i] = min(y - i, Z[i - x]);
		while (i + Z[i] < n && s[i + Z[i]] == s[Z[i]]) Z[i] ++;
		if (y <= i + Z[i]) x = i, y = i + Z[i];
	}
	Z[0] = n;
}

int main() {
	scanf("%s", s);
	int n = strlen(s);
	calcZ(s, n, Z);
	for (int i = 0; i < n; ++ i) sum[Z[i]] ++;
	for (int i = n - 1; i >= 0; -- i) sum[i] += sum[i + 1];
	vector<pair<int, int> > ret; ret.clear();
	for (int i = n - 1; i >= 0; -- i) {
		if (Z[i] == n - i) {
			ret.push_back(make_pair(Z[i], sum[Z[i]]));
		}
	}
	cout << ret.size() << endl;
	for (auto x : ret) {
		cout << x.first << " " << x.second << endl;
	}
	return 0;
}
