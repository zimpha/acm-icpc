#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 600;

string data[MAXN];

void outblank(int n) {
	while (n --) cout << " ";
}

void print(int st, int dep, int l, int r) {
	while (l <= r) {
		int i, j = l;
		for (i = st; i < (int)data[l].length(); ++ i)
			if (data[l][i] == ' ') break;
		string x = data[l].substr(st, i - st);
		l ++;
		if (x == "") continue;
		for ( ; l <= r; ++ l) {
			if (i >= (int)data[l].length() || data[l].substr(st, i -st) != x || data[l][st - 1] != ' ' || data[l][i] != ' ') break;
		}
		outblank(dep);
		cout << x << endl;
		print(i + 1, dep + 1, j, l - 1);
	}
}

int main() {
	int n; 
	while (scanf("%d", &n) == 1) {
		getchar();
		for (int i = 0; i < n; ++ i) {
			getline(cin, data[i]);
			for (int j = 0; j < (int)data[i].length(); ++ j) {
				if (data[i][j] == '\\') data[i][j] = ' ';
			}
			data[i] = " " + data[i] + " ";
		}
		sort(data, data + n);
		print(1, 0, 0, n - 1);
		puts("");
	}
	return 0;
}
