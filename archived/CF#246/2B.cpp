#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100000;
int x[MAXN], y[MAXN];
int cx[MAXN], cy[MAXN], n;
map<int, int> home, away;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++ i) {
		cin >> x[i] >> y[i];
		home[x[i]] ++;
		away[y[i]] ++;
	}
	for (int i = 0; i < n; ++ i) {
		cx[i] = n - 1, cy[i] = n - 1;
		cx[i] += home[y[i]];
		cy[i] -= home[y[i]];
		cout << cx[i] << " " << cy[i] << endl;
	}
	return 0;
}
