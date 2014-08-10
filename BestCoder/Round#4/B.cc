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

const int MAXN = 100;
const double eps = 1e-8;

int A[MAXN], N;
bool dp[MAXN][2];

int sgn(double x) {
    if (fabs(x) <= eps) return 0;
    else if (x > eps) return 1;
    else return -1;
}

bool check(double len) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    if (sgn(A[0] + len - A[1]) <= 0) dp[0][1] = 1;
    for (int i = 1; i < N; ++ i) {
        if (sgn(A[i - 1] + len - A[i]) <= 0) dp[i][0] |= dp[i - 1][0];
        if (sgn(A[i - 1] + len * 2 - A[i]) <= 0) dp[i][0] |= dp[i - 1][1];
        if (sgn(A[i - 1] + len - A[i]) == 0) dp[i][0] |= dp[i - 1][1];
        if (i == N - 1) dp[i][1] = true;
        else if (sgn(A[i] + len - A[i + 1]) <= 0) dp[i][1] = true;
        if (dp[i][0] == 0 && dp[i][1] == 0) return false;
    }
    return dp[N - 1][0] | dp[N - 1][1];
}

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++ i) scanf("%d", A + i);
        sort(A, A + N);;
        double ret = 0;
        for (int i = 1; i < N; ++ i) {
            if (check(A[i] - A[i - 1])) ret = max(ret, 1.0 * A[i] - A[i - 1]);
            if (check((A[i] - A[i - 1]) * 0.5)) ret = max(ret, (A[i] - A[i - 1]) * 0.5);
        }
        printf("%.3f\n", ret);
    }
    return 0;
}
