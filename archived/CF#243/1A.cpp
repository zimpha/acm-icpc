#include <iostream>
#include <algorithm>
using namespace std;

vector<int> A, B, C;
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0, x; i < n; ++ i) {
		cin >> x; A.push_back(x);
	}
	int ret = -10000;
	for (int i = 0; i < n; ++ i) {
		for (int j = i; j < n; ++ j) {
			int sum = 0; B.clear(); C.clear();
			for (int k = 0; k < i; ++ k) C.push_back(A[k]);
			for (int k = i; k <= j; ++ k) B.push_back(A[k]), sum += A[k];
			for (int k = j + 1; k < n; ++ k) C.push_back(A[k]);
			sort(B.begin(), B.end());
			sort(C.begin(), C.end()); reverse(C.begin(), C.end());
			ret = max(ret, sum);
			for (int k = 0; k < m && k < (int)B.size() && k < (int)C.size(); ++ k) {
				sum -= B[k]; sum += C[k];
				ret = max(ret, sum);
			}
		}
	}
	cout << ret << endl;
	return 0;
}
