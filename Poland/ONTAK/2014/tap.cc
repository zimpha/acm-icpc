#include <bits/stdc++.h>
using namespace std;
const int SIZE = 5000000 + 10;
typedef long long LL;
char s[SIZE], t[SIZE];
int fail[SIZE], n, m;

int period(char s[], int n) {
    fail[0] = -1;
    for (int i = 1, j = -1; i < n; ++ i) {
        while (j >= 0 && s[i] != s[j + 1]) j = fail[j];
        fail[i] = (s[j + 1] == s[i]) ? ++ j : j;
    }
    int p = n - 1 - fail[n - 1];
    if (n % p == 0) return p;
    else return n;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        scanf("%s", s + i * m);
    }
    LL rn = 1, rm = 1, tmp;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) t[j] = s[i * m + j];
        t[m] = 0; tmp = period(t, m);
        rm = rm / __gcd(rm, tmp) * tmp;
        if (rm > m) rm = m;
    }
    for (int j = 0; j < m; ++ j) {
        for (int i = 0; i < n; ++ i) t[i] = s[i * m + j];
        t[n] = 0; tmp = period(t, n);
        rn = rn / __gcd(rn, tmp) * tmp;
        if (rn > n) rn = n;
    }
    printf("%d %d\n", (int)rn, (int)rm);
    for (int i = 0; i < rn; ++ i) {
        for (int j = 0; j < rm; ++ j) {
            putchar(s[i * m + j]);
        }
        puts("");
    }
    return 0;
}
