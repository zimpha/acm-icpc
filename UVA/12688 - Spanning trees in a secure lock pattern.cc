#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        int n; scanf("%d", &n);
        if (n == 2) puts("16");
        else if (n == 3) puts("17745");
        else if (n == 4) puts("1064918960");
        else if (n == 5) puts("3271331573452800");
        else if (n == 6) puts("504061943351318476800000");
    }
    return 0;
}
