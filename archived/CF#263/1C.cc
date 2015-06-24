#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 10;

struct BIT {
    int u[MAXN], n;
    void init(int _n) {
        this->n = _n;
        memset(u + 1, 0, sizeof(u[0]) * n);
    }
    void update(int x, int v) {
        for (; x <= n; x += x & -x) u[x] += v;
    }
    int get(int x) {
        int ret = 0;
        for (; x; x -= x & -x) ret += u[x];
        return ret;
    }
    int get(int l, int r) { // (l, r]
        return get(r) - get(l);
    }
} Task;

int a[MAXN], st, ed, d, n, q;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    st = 1, ed = n; d = 1;
    Task.init(n);
    for (int i = 1; i <= n; ++ i) {
        Task.update(i, 1);
        a[i] = 1;
    }
    while (q --) {
        int t; cin >> t;
        if (t == 1) {
            int p; cin >> p;
            if (d) {
                int ls = p, rs = ed - st - p + 1;
                if (ls <= rs) {
                    for (int i = 0; i < ls; ++ i) {
                        a[st + i + p] += a[st + p - 1 - i];
                        Task.update(st + i + p, a[st + p - 1 - i]);
                    }
                    st += p;
                }
                else {
                    d ^= 1;
                    for (int i = 0; i < rs; ++ i) {
                        a[st + p - 1 - i] += a[st + p + i];
                        Task.update(st + p - 1 - i, a[st + p + i]);
                    }
                    ed = st + p - 1;
                }
            }
            else {
                int ls = ed - st + 1 - p, rs = p;
                if (ls <= rs) {
                    for (int i = 0; i < ls; ++ i) {
                        a[ed - p + 1 + i] += a[ed - p - i];
                        Task.update(ed - p + 1 + i, a[ed - p - i]);
                    }
                    d ^= 1;
                    st = ed - p + 1;
                }
                else {
                    for (int i = 0; i < rs; ++ i) {
                        a[ed - p - i] += a[ed - p + 1 + i];
                        Task.update(ed - p - i, a[ed - p + 1 + i]);
                    }
                    ed = ed - p;
                }
            }
        }
        else {
            int l, r; cin >> l >> r;
            if (d) {
                cout << Task.get(st + l - 1, st + r - 1) << endl;
            }
            else {
                cout << Task.get(ed - r, ed - l) << endl;
            }
        }
    }
    return 0;
}
