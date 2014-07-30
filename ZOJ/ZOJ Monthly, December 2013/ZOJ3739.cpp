#include <cmath>
#include <cstdio>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long double ldb;
typedef long long LL;

const ldb PI = M_PIl;
const ldb eps=1e-10;
const int MAXR=120;
const int MAXM=20;
const int M=12;

int A, B, R, K;

ldb sum[MAXM];
LL dp[MAXR][MAXR+1];

inline LL sqr(LL x) {return x*x;}

inline ldb calc(ldb alpha, ldb beta) {
	return 0.125l*((A+B)*(beta-alpha)+(A-B)*sin(beta-alpha)*cos(beta+alpha));
}

int main() {
	cout.precision(18);
	for (int i = 1; i <= MAXR; ++ i) dp[0][i] = sqr(sqr(i * i));
	for (int i = 1; i < MAXR; ++ i)
		for (int j = i + 1; j <= MAXR; ++ j) {
			dp[i][j] = 1LL<<60;
			for (int k = i; k < j; ++ k)
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + sqr(j * j * j * j - k * k * k * k));
		}
	while (cin >> R >> A >> B >> K) {
		if (K == 0 || K == 1 || K == 2 || K == 4 ||
			(A == B && K % 3 == 0 && K <= 12 && K != 9)) {
			puts("0.000000000000000000");
			continue;
		}
		ldb ret = 1e100;
		for (int i = 0; i < M; ++ i) sum[i] = calc(i * PI / 6.0, (i + 1) * PI / 6.0);
		ldb total = R * R * R * R * calc(0, PI * 2);
		for (int mask = 0; mask < (1 << M); ++ mask) {
			int k1 = __builtin_popcount(mask);
			int k2 = K - k1;
			int N = (k2 + 1) * (k1 < 2 ? 1 : k1);
			if (k2 >= R || k2 < 0) continue;
			ldb tmp = 0;
			if (k1 < 2) {
				for (int i = 0; i < M; ++ i) tmp += sum[i];
				tmp = tmp * tmp;
			}
			else {
				for (int i = 0; i < M; ++ i)
					if ((mask >> i ) & 1) {
						ldb x = sum[i];
						for (int j = (i + 1) % M; ((mask >> j) & 1) == 0; j = (j + 1) % M) x += sum[j];
						tmp += x * x;
					}
			}
			ret = min(ret, tmp * dp[k2][R] / N - pow(total / N, 2));
		}
		if (fabs(ret) < eps) ret=0;
		ret = max(0.0L, ret);
		cout << fixed << sqrt(ret) << endl;
	}
	return 0;
}
