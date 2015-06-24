#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;
int t[MAXN], p[MAXN];
LL v[MAXN];
int h[MAXN], n, q, sz;
vector<int> H;

struct BIT {
public:
    static const int SIZE = 200000 + 10;
    LL u[SIZE];
    void init(int n = SIZE) {
        memset(u, 0, sizeof(u[0]) * n);
    }
    void modify(int x, LL v) {
        for (; x < SIZE; x += x & -x) u[x] += v;
    }
    LL getsum(int x) {
        LL ret = 0;
        for (; x; x -= x & -x) ret += u[x];
        return ret;
    }
} cnt, sum;

inline int GET(int h) {
    return lower_bound(H.begin(), H.end(), h) - H.begin() + 1;
}

int main() {
    scanf("%d%d", &n, &q);
    sum.init(); cnt.init(); sz = 0;
    for (int i = 1; i <= n; ++ i) {
        scanf("%d", &h[i]);
        H.push_back(h[i]);
    }
    for (int i = 0; i < q; ++ i) {
        scanf("%d", &t[i]);
        if (t[i] == 1) {
            scanf("%d%lld", p + i, v + i);
            H.push_back(v[i]);
        }
        else scanf("%lld", v + i);
    }
    sort(H.begin(), H.end());
    H.erase(unique(H.begin(), H.end()), H.end());
    for (int i = 1; i <= n; ++ i) {
        cnt.modify(GET(h[i]), 1);
        sum.modify(GET(h[i]), h[i]);
    }
    for (int i = 0; i < q; ++ i) {
        if (t[i] == 1) {
            cnt.modify(GET(h[p[i]]), -1);
            sum.modify(GET(h[p[i]]), -h[p[i]]);
            h[p[i]] = v[i];
            cnt.modify(GET(h[p[i]]), 1);
            sum.modify(GET(h[p[i]]), h[p[i]]);
        }
        else {
            int left = 1, right = H.size();
            while (left < right) {
                int mid = (left + right + 1) >> 1;
                LL cc = cnt.getsum(mid), ss = sum.getsum(mid);
                if (H[mid - 1] * cc - ss < v[i]) left = mid;
                else right = mid - 1;
            }
            LL cc = cnt.getsum(left), ss = sum.getsum(left);
            double ret = H[left - 1] + (v[i] - H[left - 1] * cc + ss) / (double)cc;
            printf("%.10f\n", ret);
        }
    }
    return 0;
}
