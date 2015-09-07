#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, D;
    for (int cas = 1; scanf("%d%d", &n, &D) == 2 && D; ++ cas) {
        double ret = 0;
        int tl = 0;
        for (int i = 0; i < n; ++ i) {
            int p, l, v; scanf("%d%d%d", &p, &l, &v);
            tl += l; ret += 2.0 * l / v;
        }
        ret += D - tl;
        printf("Case %d: %.3f\n\n", cas, ret);
    }
    return 0;
}
