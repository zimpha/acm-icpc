#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

inline double area(int a, int b, int c) {
	double p = (a + b + c)/2.0;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

inline bool check(int a, int b, int c) {
	return (a + b > c && a + c > b && b + c > a);
}

int calclen(int s, int t, int A[]) {
	int ret = 0;
	for (int i = s + 1; ; ++ i) {
		if (i == 7) i = 1;
		ret += A[i];
		if (i == t) break;
	}
	return ret;
}

int main() {
	int A[10];
	while (scanf("%d%d", &A[1], &A[2]) == 2) {
		scanf("%d%d%d%d", &A[3], &A[4], &A[5], &A[6]);
		double ret = 0;
		for (int turn = 0; turn < 2; ++ turn) {
			if (turn == 1) {swap(A[3], A[5]); swap(A[4], A[6]);}
			for (int mask = 0; mask < 7; ++ mask) {
				for (int i = 1; i <= 3; ++ i)
					if ((mask >> (i - 1)) & 1) swap(A[2 * i - 1], A[2 * i]);
				for (int i = 1; i <= 6; ++ i) 
					for (int j = i + 1; j <= 6; ++ j) 
						for (int k = j + 1; k <= 6; ++ k) {
							int a = calclen(i, j, A);
							int b = calclen(j, k, A);
							int c = calclen(k, i, A);
							if (check(a, b, c)) ret = max(ret, area(a, b, c));
						}
				for (int i = 1; i <= 3; ++ i)
					if ((mask >> (i - 1)) & 1) swap(A[2 * i - 1], A[2 * i]);
			}
		}
		printf("%.12f\n", ret);
	}
	return 0;
}
