#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10, SIZE = 1 << 22;
int a[MAXN], nx[SIZE], n, sum;
int Q[SIZE][2], P[SIZE];

inline int low(int x) {return x & -x;}
inline int high(int x) {
    if (x == 0) return 0;
    else return 1 << (31 - __builtin_clz(x));
}

unordered_set<int> S;
void expand(int l, int r, int &t, int d, int h) {
    int x = high(l), y = high(r);
    if (x >= y) l -= x, r += x;
    int msk = r << 14 | l;
    if (S.count(msk)) return;
    Q[t][0] = msk; Q[t ++][1] = d;
    S.insert(msk); P[t - 1] = h;
}

string solve() {
    if (__builtin_popcount(sum) != 1) return string("no");
    S.clear(); Q[0][0] = a[0] << 14; Q[0][1] = 1;
    for (int h = 0, t = 1; h < t; ++ h) {
        int l = Q[h][0] & 0x3fff, r = Q[h][0] >> 14;
        if (l == 0 && r == sum) {
            string ret = "";
            for (; h; h = P[h]) {
                ret = string(1, "lr"[Q[h][1]]) + ret;
            }
            return "l" + ret;
        }
        if (l + r == sum) continue;
        int add = a[nx[l + r]];
        if (l == 0 || add <= low(l)) {
            expand(l + add, r, t, 0, h);
        }
        if (add <= low(r)) {
            expand(l, r + add, t, 1, h);
        }
    }
    return string("no");
}

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%d", &n); sum = 0;
        for (int i = 0; i < n; ++ i) {
            scanf("%d", a + i), sum += a[i];
            nx[sum] = i + 1;
        }
        printf("%s\n", solve().c_str());
    }
    return 0;
}
