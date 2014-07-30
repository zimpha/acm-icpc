#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXK = 20;

vector <LL> prime;
LL pow_mat[41][MAXK][MAXK];
LL comb[MAXK][MAXK];
LL N, K, M;

LL mul_mod(LL a, LL b) {
	LL ret = 0;
	for (; b; b >>= 1) {
		if (b & 1) {
			ret += a;
			if (ret >= M) ret -= M;
		}
		a <<= 1;
		if (a >= M) a -= M;
	}
	return ret;
}

void mul_mat(LL a[MAXK][MAXK], LL b[MAXK][MAXK]) {
	LL c[MAXK][MAXK];
	memset(c, 0, sizeof(c));
	for (int i = 0; i <= K + 1; i ++) {
		for (int j = 0; j <= K + 1; ++ j) {
			for (int l = 0; l <= K + 1; ++ l) {
				c[i][j] += mul_mod(a[i][l], b[l][j]);
				if (c[i][j] >= M) c[i][j] -= M;
			}
		}
	}
	memcpy(a, c, sizeof(c));
}

void calc_comb() {
	comb[0][0] = 1;
	for (int i = 1; i < MAXK; ++ i) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; ++ j) {
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
			if (comb[i][j] >= M) comb[i][j] -= M;
		}
	}
}

void factor(LL x) {
	prime.clear();
	for (LL i = 2; i * i <= x; ++ i) {
		if (x % i == 0) {
			prime.push_back(i);
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1) prime.push_back(x);
}

void get_matrix() {
	memset(pow_mat[1], 0, sizeof(pow_mat[1]));
	for (int i = 0; i <= K; ++ i) {
		for (int j = 0; j <= i; ++ j) pow_mat[1][i][j] = comb[i][j];
	}
	pow_mat[1][K + 1][K + 1] = 1;
	for (int i = 0; i <= K; ++ i) pow_mat[1][K + 1][i] = comb[K][i];
	for (int i = 2; i < 41; ++ i) {
		memcpy(pow_mat[i], pow_mat[i - 1], sizeof(pow_mat[i - 1]));
		mul_mat(pow_mat[i], pow_mat[i]);
	}
}

LL solve(LL n) {
	LL ret[MAXK];
	memset(ret, 0, sizeof(ret));
	ret[0] = 1;
	for (int t = 1; n; n >>= 1, ++ t) {
		if (n & 1) {
			LL tmp[MAXK];
			for (int i = 0; i <= K + 1; ++ i) {
				tmp[i] = 0;
				for (int j = 0; j <= K + 1; ++ j) {
					tmp[i] += mul_mod(pow_mat[t][i][j], ret[j]);
					if (tmp[i] >= M) tmp[i] -= M;
				}
			}
			memcpy(ret, tmp, sizeof(tmp));
		}
	}
	return ret[K + 1];
}

int main() {
	scanf("%lld%lld%lld", &N, &K, &M);
	calc_comb();
	factor(N);
	get_matrix();
	LL ret = 0;
	for (int mask = 0; mask < (1 << prime.size()); ++ mask) {
		LL pp = 1, cof = 1;
		for (int i = 0; i < (int)prime.size(); ++ i) {
			if ((mask >> i) & 1) pp *= prime[i], cof *= -1;
		}
		LL tmp = solve(N / pp);
		for (int i = 0; i < K; ++ i) tmp = mul_mod(tmp, pp);
		ret += cof * tmp;
		if (ret < 0) ret += M;
		if (ret >= M) ret -= M;
	}
	printf("%lld\n", ret);
	return 0;
}
