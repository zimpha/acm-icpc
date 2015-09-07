#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100;
string A[MAXN];
int N;

bool cmp(const string &a, const string &b) {
	return a + b > b + a;
}

int main() {
	while (cin >> N && N) {
		for (int i = 0; i < N; ++ i) cin >> A[i];
		sort(A, A + N, cmp);
		for (int i = 0; i < N; ++ i) cout << A[i];
		cout << endl;
	}
	return 0;
}
