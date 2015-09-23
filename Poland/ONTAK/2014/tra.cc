#include <bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 200000 + 10;
vector<PII> event;
vector<int> C;
int L[2][MAXN], R[2][MAXN];
int ret[MAXN], mx[MAXN << 2];
int n, m;

void add(int x, int v) {
    int rt = 1, l = 1, r = m;
    mx[rt] = max(mx[rt], v);
    while (l < r) {
        if (x <= mid) r = mid, rt = lson;
        else l = mid + 1, rt = rson;
        mx[rt] = max(mx[rt], v);
    }
}

int get(int x) {
    int l = 1, r = m, rt = 1, ret = 0;
    while (x < r) {
        if (x <= mid) r = mid, rt = lson;
        else ret = max(ret, mx[lson]), rt = rson, l = mid + 1;
    }
    return max(ret, mx[rt]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
        scanf("%d%d%d%d", &L[0][i], &R[0][i], &L[1][i], &R[1][i]);
        C.push_back(L[1][i]); C.push_back(R[1][i]);
        event.push_back(PII(L[0][i], i));
        event.push_back(PII(R[0][i], -i));
    }
    sort(C.begin(), C.end()); C.erase(unique(C.begin(), C.end()), C.end());
    for (int i = 1; i <= n; ++ i) {
        L[1][i] = lower_bound(C.begin(), C.end(), L[1][i]) - C.begin() + 1;
        R[1][i] = lower_bound(C.begin(), C.end(), R[1][i]) - C.begin() + 1;
    }
    sort(event.begin(), event.end()); m = C.size();
    for (int i = 0; i < (int)event.size(); ++ i) {
        int idx = event[i].second;
        if (idx > 0) ret[idx] = get(L[1][idx]);
        else add(R[1][-idx], ret[-idx] + 1);
    }
    printf("%d\n", get(m));
    return 0;
}
