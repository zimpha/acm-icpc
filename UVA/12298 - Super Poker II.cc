#include <bits/stdc++.h>
using namespace std;

typedef long double ldb;
class Complex {
public:
	ldb r, i;
	Complex() {}
	Complex(ldb r = 0, ldb i = 0) : r(r), i(i) {}
	Complex operator + (const Complex &rhs) {return Complex(r + rhs.r, i + rhs.i);}
	Complex operator - (const Complex &rhs) {return Complex(r - rhs.r, i - rhs.i);}
	Complex operator * (const Complex &rhs) {return Complex(r * rhs.r - i * rhs.i, r * rhs.i + i * rhs.r);}
};

class FFT {
private:
	int arrange(vector<Complex> &A) {
		int n = A.size();
		for (int i = 0, j = 0, k; i < n; ++ i, j |= k) {
			if (j > i) swap(A[i], A[j]);
			for (k = n; j & (k >>= 1); j &= (~k));
		}
		return n;
	}
public:
	void trans(vector<Complex> &A, int o) {
		int n = arrange(A);
		const ldb PI = acos(-1);
		for (int step = 1; step < n; step <<= 1) {
			Complex wn(cos(o * PI / step), sin(o * PI / step)), w(1.0, 0.0);
			for (int k = 0; k < step; ++ k) {
				for (int i = k, j; j = i + step, i < n; i += (step << 1)) {
					Complex t = w * A[j];
					A[j] = A[i] - t;
					A[i] = A[i] + t;
				}
				w = w * wn;
			}
		}
		if (o < 0) {
			for (int i = 0; i < n; ++ i) A[i].r /= n;
		}
	}
} FFT;

const int MAXN = 50000 + 10;
int plist[MAXN], vis[MAXN], m = 0;

void sieve() {
	for (int i = 2; i < MAXN; ++ i) {
		if (!vis[i]) plist[m ++] = i;
		for (int j = 0; j < m && i * plist[j] < MAXN; ++ j) {
			vis[i * plist[j]] = true;
			if (i % plist[j] == 0) break;
		}
	}
}

int main() {
	sieve();
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) == 3 && a) {
		int n = 1;
		while (n <= b * 4) n <<= 1;
		vector<Complex> S(n, Complex(0, 0)), H(n, Complex(0, 0));
		vector<Complex> C(n, Complex(0, 0)), D(n, Complex(0, 0));
		for (int i = 0; i <= b; ++ i) {
			if (vis[i]) S[i] = H[i] = C[i] = D[i] = Complex(1, 0);
		}
		while (c --) {
			int p; char ch;
			scanf("%d%c", &p, &ch);
			if (p > b) continue;
			if (ch == 'S') S[p] = Complex(0, 0);
			if (ch == 'H') H[p] = Complex(0, 0);
			if (ch == 'C') C[p] = Complex(0, 0);
			if (ch == 'D') D[p] = Complex(0, 0);
		}
		FFT.trans(S, 1); FFT.trans(H, 1); FFT.trans(C, 1); FFT.trans(D, 1);
		for (int i = 0; i < n; ++ i) {
			S[i] = S[i] * H[i] * C[i] * D[i];
		}
		FFT.trans(S, -1);
		for (int i = a; i <= b; ++ i) {
			printf("%.0Lf\n", fabs(S[i].r));
		}
		puts("");
	}
	return 0;
}
