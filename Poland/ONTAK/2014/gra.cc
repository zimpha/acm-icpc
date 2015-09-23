#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000 + 10;
char s[MAXN];
int n, x, c = 0;

int main() {
    scanf("%d%s", &n, s + 1); x = 0; c = 0;
    for (int i = 1; i <= n; ++ i) {
        if (s[i] == 'R') x ^= i;
    }
    for (int i = 1; i <= n; ++ i) {
        if (s[i] == 'R' && (x ^ i) < i) ++ c;
    }
    printf("%d\n", c);
    return 0;
}
