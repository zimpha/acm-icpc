#include <bits/stdc++.h>
using namespace std;

char buf;
inline int xint() { int x; while (buf = getchar(), buf < '0' || buf > '9'); x = buf - '0'; for (; buf = getchar(), buf >= '0' && buf <= '9'; x = x * 10 + buf - '0'); return x; }

int main() {
    int r = 0, d, x;
    d = xint();
    for (int i = 0; i < d; ++ i) {
        x = xint(); r ^= x;
    }
    printf("%d\n", r);
    return 0;
}
