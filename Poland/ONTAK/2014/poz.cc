#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
typedef pair<ULL, ULL> PII;
set<PII> S;
const int MAXN = 2000;
const ULL s1 = 1e9 + 7, s2 = 1e9 + 3;
ULL p1[MAXN], p2[MAXN];
int a[MAXN], cnt[MAXN], n;

int main() {
    p1[0] = p2[0] = 1;
    for (int i = 1; i < MAXN; ++ i) {
        p1[i] = p1[i - 1] * s1;
        p2[i] = p2[i - 1] * s2;
    }
    random_shuffle(p1, p1 + MAXN);
    random_shuffle(p2, p2 + MAXN);
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) scanf("%d", a + i);
    for (int i = 0; i < n; ++ i) {
        memset(cnt, 0, sizeof(cnt));
        ULL r1 = 0, r2 = 0; 
        for (int j = i; j < n; ++ j) {
            ++ cnt[a[j]];
            if (cnt[a[j]] == 1) r1 += p2[a[j]], r2 += p2[a[j]];
            S.insert(PII(r1, r2));
        }
    }
    printf("%d\n", (int)S.size());
    return 0;
}
