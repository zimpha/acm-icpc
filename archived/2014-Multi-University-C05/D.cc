#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <algorithm>
using namespace std;

typedef long double flt;
typedef complex<double> Complex;
const int MOD = 119, MAXN = 100000;
const flt PI = acos(-1.0);

/*class Complex {
public:
	flt r, i;
	Complex(flt r = 0, flt i = 0) : r(r), i(i) {}
	Complex operator + (const Complex &rhs) {return Complex(r + rhs.r, i + rhs.i);}
	Complex operator - (const Complex &rhs) {return Complex(r - rhs.r, i - rhs.i);}
	Complex operator * (const Complex &rhs) {return Complex(r * rhs.r - i * rhs.i, r * rhs.i + i * rhs.r);}
};*/

struct FFT {
	void trans(Complex P[], int n, int oper) { // oper = -1 inverse
        for (int i = 1, j = 0; i < n - 1; ++ i) {
            for (int s = n; j ^= s >>= 1, ~j & s;);
            if (i < j) swap(P[i], P[j]);
        }
        Complex unit_p0;
        for (int d = 0; (1 << d) < n; ++ d) {
            int m = 1 << d, m2 = m << 1;
            flt p0 = PI / m * oper;
            unit_p0 = Complex(cos(p0), sin(p0));
            for (int i = 0; i < n; i += m2) {
                Complex unit(1, 0);
                for (int j = 0; j < m; ++ j) {
                    Complex &P1 = P[i + j + m], &P2 = P[i + j];
                    Complex t = unit * P1;
                    P1 = P2 - t; P2 = P2 + t;
                    unit = unit * unit_p0;
                }
            }
        }
		/*if (oper < 0) {
			for (int i = 0; i < n; ++ i) P[i].r /= n;
		}*/
	}
} Solver;

typedef vector<int> vi;

Complex A[MAXN], B[MAXN];
int n, a, b, p, q;

void add_mod(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

vi operator * (const vi &u, const vi &v) {
    int n = 1;
    while (n <= q + q - 2) n <<= 1;
    for (int i = 0; i < n; ++ i) A[i] = Complex(i < q ? u[i] : 0, 0);
    for (int i = 0; i < n; ++ i) B[i] = Complex(i < q ? v[i] : 0, 0);
    Solver.trans(A, n, 1); Solver.trans(B, n, 1);
    for (int i = 0; i < n; ++ i) A[i] = A[i] * B[i];
    Solver.trans(A, n, -1);
    vi w(q + q - 1, 0);
    for (int i = 0; i < (int)w.size(); ++ i) {
        w[i] = ((int)(A[i].real() / n + 0.5)) % MOD;
    }
    for (int i = (int)w.size() - 1; i >= q; -- i) {
        add_mod(w[i - p], a * w[i] % MOD);
        add_mod(w[i - q], b * w[i] % MOD);
    }
    w.resize(q);
    return w;
}

int main() {
    while (scanf("%d%d%d%d%d", &n, &a, &b, &p, &q) == 5) {
        n += q - 1; a %= MOD; b %= MOD;
        vi product(q, 0); product[0] = 1;
        vi base(q, 0); base[1] = 1;
        for (; n; n >>= 1) {
            if (n & 1) product = product * base;
            base = base * base;
        }
        int ret = 0;
        for (int i = 0; i < q; ++ i) ret = (ret + product[i]) % MOD;
        ret = (ret + MOD) % MOD;
        printf("%d\n", ret);
    }
    return 0;
}
