#include <bits/stdc++.h>
#define PB push_back
using namespace std;
const double PI = acos(-1.0), eps = 1e-8;
const int MAXN = 100000 + 10;
typedef pair<double, int> PDI;
vector<PDI> ve;
int x[MAXN], y[MAXN], n;

inline int sgn(double x) {
    if (x < -eps) return -1;
    else return x > eps;
}

inline double dis(double x, double y) {
    return sqrt(x * x + y * y);
}

inline double adjust(double x) {
    if (sgn(x) < 0) x += PI * 2;
    else if (sgn(x - PI * 2) > 0) x -= PI * 2;
    return x;
}

inline void add(double l, double r) {
    if (sgn(l - PI) >= 0) {
        ve.PB(PDI(l - PI, 0));
        ve.PB(PDI(r - PI, 1));
    }
    else if (sgn(r -  PI) <= 0) {
        ve.PB(PDI(l, 0));
        ve.PB(PDI(r, 1));
    }
    else {
        ve.PB(PDI(l, 0)); ve.PB(PDI(PI, 1));
        ve.PB(PDI(0.0, 0)); ve.PB(PDI(r - PI, 1));
    }
}

bool check(double r) {
    ve.clear();
    int need = n, cnt = 0;
    for (int i = 1; i <= n; ++ i) {
        double d = dis(x[i], y[i]);
        if (sgn(d - r) <= 0) -- need;
        else {
            double dd = asin(r / d), theta = atan2(y[i], x[i]);
            double a = adjust(theta - dd), b = adjust(theta + dd);
            if (a <= b) add(a, b);
            else add(a, PI * 2), add(0, b);
        }
    }
    if (cnt >= need) return true;
    sort(ve.begin(), ve.end()); cnt = 0;
    for (int i = 0; i < (int)ve.size(); ++ i) {
        if (ve[i].second == 0) ++ cnt;
        else -- cnt;
        if (cnt >= need) return true;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i <= n; ++ i) scanf("%d%d", x + i, y + i);
    for (int i = 1; i <= n; ++ i) x[i] -= x[0], y[i] -= y[0];
    double left = 0, right = 1e8;
    for (int i = 1; i <= n; ++ i) right = max(right, fabs(y[i]));
    for (int _ = 0; _ < 50; ++ _) {
        double mid = (left + right) * 0.5;
        if (check(mid)) right = mid;
        else left = mid;
    }
    printf("%.6f\n", (left + right) * 0.5);
    return 0;
}
