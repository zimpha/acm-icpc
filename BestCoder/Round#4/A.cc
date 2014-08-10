#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long LL;

int main() {
    int T; scanf("%d", &T);
    int A[10], p[10], b[10];
    while (T --) {
        for (int i = 0; i < 6; ++ i) scanf("%d", A + i);
        for (int i = 0; i < 6; ++ i) p[i] = i;
        bool flag = false;
        do {
            for (int i = 0; i < 6; ++ i) b[i] = A[p[i]];
            int sg = b[0] + b[5];
            sort(b + 1, b + 5);
            int sb = b[4] + b[2] + b[3];
            if (sg > sb) flag = true;
        } while (next_permutation(p, p + 6));
        if (flag) puts("Grandpa Shawn is the Winner!");
        else puts("What a sad story!");
    }
}
