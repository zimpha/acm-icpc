#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

bool solve(int n) {
    n *= 2;
    for (long long d = 2; d * d <= n; ++ d) {
        if (n % d == 0) {
            LL a = n / d - d + 1;
            if (a >= 2 && a % 2 == 0) {
                a /= 2;
                printf("%d = %d", n / 2, a);
                for (int i = 1; i < d; ++ i) {
                    printf(" + %d", a + i);
                }
                puts("");
                return true;
            }
        }
    }
    return false;
}
int main() {
    int T; scanf("%d", &T);
    while(T --) {
        int n; scanf("%d", &n);
        if (!solve(n)) puts("IMPOSSIBLE");
    }
    return 0;
}
