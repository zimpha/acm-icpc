#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL ceil(LL a, LL b) {
    return a / b + (a % b != 0);
}

int main() {
    LL N, A, B; cin >> N >> A >> B;
    LL tot = N * A, ret = N;
    for (LL C = min(A * 2, 10ll); C < min(B * 2, 11ll); ++ C) {
        LL T = 20; if (C != 10) T = C + 1;
        T = min(T, B * 2);
        LL x = ceil(ret * T - 2 * tot, 2 * C - T);
        ret += x; tot += x * C;
    }
    cout << ret - N << endl;
    return 0;
}