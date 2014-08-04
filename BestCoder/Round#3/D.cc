#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long LL;

LL mul_mod(LL a, LL n, LL p) {
    LL ret = 0;
    for (; n; n >>= 1) {
        if (n & 1) ret = (ret + a) % p;
        a = (a + a) % p;
    }
    return ret;
}

LL pow_mod(LL a, LL n, LL p) {
    LL ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul_mod(ret, a, p);
        a = mul_mod(a, a, p);
    }
    return ret;
}

bool test(LL n, LL b) {
    LL m = n - 1;
    LL counter = 0;
    while (~m & 1) {
        m >>= 1;
        ++ counter;
    }
    LL ret = pow_mod(b, m, n);
    if (ret == 1 || ret == n - 1) return true;
    for (-- counter; counter >= 0; -- counter) {
        ret = mul_mod(ret, ret, n);
        if (ret == n - 1) return true;
    }
    return false;
}

const int BASE[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

bool is_prime(LL n) {
    if (n < 2) return false;
    if (n < 4) return true;
    if (n == 3215031751LL) return false;
    for (int i = 0; i < 12 && BASE[i] < n; ++ i) {
        if (!test(n, BASE[i])) return false;
    }
    return true;
}

bool check(LL n) {
    if (n % 2 == 0) n /= 2;
    if (is_prime(n)) return true;
    for (int i = 2; ; ++ i) {
        LL x = pow(1.0 * n, 1.0 / i) + 1e-8;
        if (pow_mod(x, i, n + 1) == n) {
            if (is_prime(x)) return x != 2;
        }
        if (x < 2) return false;
    }
    return true;
}

int main() {
    LL m;
    while (scanf("%lld", &m) == 1 && m != -1) {
        if (m <= 6) printf("%lld\n", m - 1);
        else if (check(m)) printf("%lld\n", m - 1);
        else printf("1\n");
    }
    return 0;
}
