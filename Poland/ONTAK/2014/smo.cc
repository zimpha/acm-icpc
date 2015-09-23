#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100 + 10, MAXM = 50000 + 10;

set<string> S;
string s;
int A[MAXN], B[MAXN], C[MAXN];
int n, m;

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &n, &m);
        int tot = 1;
        for (int i = 0; i < n; ++ i) {
            scanf("%d%d%d", A + i, B + i, C + i);
            ++ tot;
            for (int j = 0; j < i; ++ j) {
                if (A[i] * B[j] != B[i] * A[j]) ++ tot;
            }
        }
        S.clear();
        for (int _ = 0; _ < m; ++ _) {
            int x, y; scanf("%d%d", &x, &y);
            s = "";
            for (int i = 0; i < n; ++ i) {
                if ((LL)A[i] * x + (LL)B[i] * y + C[i] < 0) s += "0";
                else s += "1";
            }
            S.insert(s);
        }
        if ((int)S.size() == tot) puts("TAK");
        else puts("NIE");
    }
    return 0;
}
