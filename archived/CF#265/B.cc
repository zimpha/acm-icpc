#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

struct Point {
    LL x, y, z;
    Point() {}
    Point(int a[]) : x(a[0]), y(a[1]), z(a[2]) {}
    Point(LL _x, LL _y, LL _z) : x(_x), y(_y), z(_z) {}
    bool operator < (const Point &rhs) const {
        if (x != rhs.x) return x < rhs.x;
        if (y != rhs.y) return y < rhs.y;
        return z < rhs.z;
    }
    bool operator != (const Point &rhs) const {
        return (x != rhs.x || y != rhs.y || z != rhs.z);
    }
    Point operator - (const Point &rhs) const {
        return Point(x - rhs.x, y - rhs.y, z - rhs.z);
    }
    Point operator + (const Point &rhs) const {
        return Point(x + rhs.x, y + rhs.y, z + rhs.z);
    }
    LL sqr() {return x * x + y * y + z * z;}
};

int p[8][3];

vector<int> Left, Right;

LL issquare(Point A[]) {
    LL mx = 0;
    for (int i = 0; i < 4; ++ i) {
        for (int j = i + 1; j < 4; ++ j) {
            mx = max(mx, (A[i] - A[j]).sqr());
        }
    }
    vector<PII> v; v.clear();
    for (int i = 0; i < 4; ++ i) {
        for (int j = i + 1; j < 4; ++ j) {
            if (mx == (A[i] - A[j]).sqr()) v.push_back(PII(i, j));
        }
    }
    if (v.size() != 2) return 0;
    int a = v[0].first, c = v[0].second;
    int b = v[1].first, d = v[1].second;
    if (a == b || a == d || c == b || c == d) return 0;
    LL dab = 2ll * (A[a] - A[b]).sqr(), dbc = 2ll * (A[b] - A[c]).sqr();
    LL dad = 2ll * (A[a] - A[d]).sqr(), dcd = 2ll * (A[d] - A[c]).sqr();
    if (dab != mx || dbc != mx || dad != mx || dcd != mx) return 0;
    return dab >> 1;
}

bool check(Point A[], Point B[]) {
    sort(A, A + 3); sort(B, B + 3);
    for (int i = 0; i < 3; ++ i) 
        if (A[i] != B[i]) return false;
    return true;
}

bool check(Point A[], int used) {
    Point B[3];
    vector<int> rest; rest.clear();
    for (int i = 0; i < 4; ++ i) 
        if (i != used) rest.push_back(Right[i]);
    for (int i = 0; i < 3; ++ i) sort(p[rest[i]], p[rest[i]] + 3);
    do {
        do {
            do {
                for (int i = 0; i < 3; ++ i) B[i] = Point(p[rest[i]]);
                if (check(A, B)) return true;
            } while (next_permutation(p[rest[2]], p[rest[2]] + 3));
        } while (next_permutation(p[rest[1]], p[rest[1]] + 3));
    } while (next_permutation(p[rest[0]], p[rest[0]] + 3));
    return false;
}

bool solve() {
    Point A[4], B[4];
    for (int i = 0; i < 4; ++ i) A[i] = Point(p[Left[i]]);
    LL len = issquare(A);
    if (len == 0) return false;
    for (int i = 0; i < 4; ++ i) {
        sort(p[Right[i]], p[Right[i]] + 3);
        do {
            Point t(p[Right[i]]);
            if (len != (t - A[0]).sqr()) continue;
            for (int j = 0; j < 4; ++ j) B[j] = A[j] + t - A[0];
            if (check(B + 1, i)) {
                cout << "YES" << endl;
                for (int i = 0; i < 8; ++ i) {
                    cout << p[i][0] << " " << p[i][1] << " " << p[i][2] << endl;
                }
                return true;
            }
        } while (next_permutation(p[Right[i]], p[Right[i]] + 3));
    }
    return false;
}

bool dfs(int dep) {
    if (dep == 4) return solve();
    else {
        sort(p[Left[dep]], p[Left[dep]] + 3);
        do {
            if (dfs(dep + 1)) return true;
        } while (next_permutation(p[Left[dep]], p[Left[dep]] + 3));
    }
    return false;
}

int main() {
    for (int i = 0; i < 8; ++ i) {
        cin >> p[i][0] >> p[i][1] >> p[i][2];
    }
    bool flag = false;
    for (int mask = 0; mask < 256 && !flag; ++ mask) {
        if (__builtin_popcount(mask) != 4) continue;
        Left.clear(); Right.clear();
        for (int i = 0; i < 8; ++ i) {
            if ((mask >> i) & 1) Left.push_back(i);
            else Right.push_back(i);
        }
        if (dfs(0)) flag = true;
    }
    if (!flag) cout << "NO" << endl;
    return 0;
}
