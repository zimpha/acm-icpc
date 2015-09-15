#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        int a, b, n; scanf("%d%d%d", &a, &b, &n);
        if (n % __gcd(a, b)) {puts("R");continue;}
        if (n % a == 0) {puts("E"); continue;}
        if (a < b) {
            if (n >= a) puts("E");
            else if (n + a < b) puts("E");
            else if (n % (b - a)) puts("E");
            else puts("P");
        }
        else {
            if (n < a) puts("P");
            else if (n % a >= b) puts("P");
            else if (n % a + b < a) puts("P");
            else if ((n % a) % (a - b)) puts("P");
            else puts("E");
        }
    }
    return 0;
}