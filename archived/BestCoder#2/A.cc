#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;;
typedef pair<int, int> PII;

int sum[5000];

int main() {
    int T, N; scanf("%d", &T);
    while (T --) {
        memset(sum, 0, sizeof(sum));
        scanf("%d", &N);
        while (N --) {
            int x, h1, m1, h2, m2;
            scanf("%d %d:%d %d:%d", &x, &h1, &m1, &h2, &m2);
            int t1 = h1 * 60 + m1, t2 = h2 * 60 + m2;
            sum[t1] += x; sum[t2] -= x;
        }
        int ret = sum[0];
        for (int i = 1; i <= 1440; ++ i) {
            sum[i] += sum[i - 1];
            ret = max(ret, sum[i]);
        }
        printf("%d\n", ret);
    }
    return 0;
}
