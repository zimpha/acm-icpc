#include <set>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 500000 + 10;

typedef long long LL;

int A[MAXN], idx[MAXN], N, X;
int mx[MAXN << 2];
LL S[MAXN];

bool cmp(int a, int b) {
    return S[a] < S[b];
}

set<int> Q;

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &N, &X);
        for (int i = 0; i <= N; ++ i) idx[i] = i; S[0] = 0;
        for (int i = 1; i <= N; ++ i) {
            scanf("%d", A + i);
            S[i] = A[i] + S[i - 1];
        }
        sort(idx, idx + 1 + N, cmp);
        Q.clear();
        int ret = N * 2;
        for (int i = 0, j = 0; i <= N; ++ i) {
            while (j < i && S[idx[i]] - S[idx[j]] >= X) {
                Q.insert(idx[j]);
                ++ j;
            }
            set<int>::iterator it = Q.lower_bound(idx[i]);
            if (it != Q.begin()) {
                -- it;
                ret = min(ret, idx[i] - *it);
            }
        }
        if (ret > N) ret = -1;
        printf("%d\n", ret);
    }
    return 0;
}
