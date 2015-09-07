#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const char SMS[10][10] = {" ",
  ".,?\"", "abc", "def",
  "ghi", "jkl", "mno",
  "pqrs", "tuv", "wxyz"
};

int main() {
  int T, n, A[128], B[128];
	scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++ i) scanf("%d", &A[i]);
		for (int i = 0; i < n; ++ i) scanf("%d", &B[i]);
		for (int i = 0; i < n; ++ i) putchar(SMS[A[i]][B[i] - 1]);
		puts("");
	}
	return 0;
}

