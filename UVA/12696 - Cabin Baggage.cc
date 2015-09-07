#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const double eps = 1e-8;

int sgn(double x) {
    if (abs(x) <= eps) return 0;
    else if (x > eps) return 1;
    else return -1;
}

int main() {
    int T; scanf("%d", &T);
    int tot = 0;
    while (T --) {
        double len, wid, dep, wei;
        scanf("%lf%lf%lf%lf", &len, &wid, &dep, &wei);
        if (sgn(wei - 7) <= 0 && (sgn(len + wid + dep - 125) <= 0 || (sgn(len - 56) <= 0 && sgn(wid - 45) <= 0 && sgn(dep - 25) <= 0))) {
            puts("1");
            ++ tot;
        }
        else puts("0");
    }
    printf("%d\n", tot);
    return 0;
}
