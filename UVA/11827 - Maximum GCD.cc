#include <cctype>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 110;
const int SIZE = 1000000;

char buf[SIZE];
vector<int> num;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int T; scanf("%d\n", &T);
	while (T --) {
		gets(buf);
		int n = strlen(buf); num.clear();
		for (int i = 0, x; i < n; ++ i) {
			if (isdigit(buf[i])) {
				sscanf(&buf[i], "%d", &x);
				num.push_back(x);
				while (isdigit(buf[i])) ++ i;
			}
		}
		int ret = 0;
		for (int i = 0; i < (int)num.size(); ++ i) {
			for (int j = i + 1; j < (int)num.size(); ++ j) {
				ret = max(ret, gcd(num[i], num[j]));
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
