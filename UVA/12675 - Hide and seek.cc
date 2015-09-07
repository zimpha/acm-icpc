#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-10, PI = acos(-1.0);

inline int sgn(double x) {
    if (fabs(x) <= eps) return 0;
    else if (x > eps) return 1;
    else return -1;
}

struct Point {
    double x, y, ang;
    Point() : x(0), y(0) {}
    Point(double a, double b) : x(a), y(b) {
        ang = atan2(y, x);
    }
    Point operator + (const Point &rhs) const {
        return Point(x + rhs.x, y + rhs.y);
    }
    Point operator - (const Point &rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }
    Point operator * (double k) const {
        return Point(x * k, y * k);
    }
    Point operator / (double k) const {
        return Point(x / k, y / k);
    }
    double dot(const Point &rhs) const {
        return x * rhs.x + y * rhs.y;
    }
    double det(const Point &rhs) const {
        return x * rhs.y - y * rhs.x;
    }
    double abs() const {
        return hypot(x, y);
    }
    void read() {
        scanf("%lf%lf", &x, &y);
    }
} O;

double nowAng;

Point inter(Point A, Point B, Point C, Point D) {
    return A + (B - A) * ((D - C).det(C - A) / (D - C).det(B - A));
}

struct Line {
    Point A, B;
    Line() {}
    Line(Point a, Point b) : A(a), B(b) {}
    double dis() const {
        if (sgn((O - A).det(O - B)) == 0) return min((O - A).abs(), (O - B).abs());
        return (O - inter(A, B, O, Point(cos(nowAng), sin(nowAng)))).abs();
    }
    bool operator < (const Line &rhs) const {
        return sgn(dis() - rhs.dis()) < 0;
    }
};

struct Event {
    double ang;
    int id, type;
    Event() : ang(0), id(0), type(0) {}
    Event(double a, int b, int c) : ang(a), id(b), type(c) {}
    bool operator < (const Event &rhs) const {
        if (sgn(ang - rhs.ang) != 0) return sgn(ang - rhs.ang) < 0;
        return type < rhs.type;
    }
};

const int MAXN = 30000 + 10;

Point P[MAXN];
Line L[MAXN];
int S, N, M;

vector<Event> E;
set<Line> Seg;
set<Line>::iterator its[MAXN];

double fix(double x) {
    if (x < 0) x += PI * 2;
    if (x >= PI * 2) x -= PI * 2;
    return x;
}

int gao(int id) {
    int ret = 0;
    E.clear();
    for (int i = 0; i < N; ++ i) {
        if (i == id) continue;
        Point tmp = P[i] - P[id];
        E.push_back(Event(tmp.ang, i, 1));
    }
    for (int i = 0; i < M; ++ i) {
        Point A = L[i].A - P[id];
        Point B = L[i].B - P[id];
        double delta = fix(B.ang - A.ang);
        if (sgn(delta - PI) > 0) swap(A, B);
        if (sgn(A.ang - B.ang) > 0) {
            E.push_back(Event(A.ang, i, 0));
            E.push_back(Event(PI, i, 2));
            E.push_back(Event(-PI, i, 0));
            E.push_back(Event(B.ang, i, 2));
        }
        else {
            E.push_back(Event(A.ang, i, 0));
            E.push_back(Event(B.ang, i, 2));
        }
    }
    sort(E.begin(), E.end());
    Seg.clear();
    for (int i = 0; i < (int)E.size(); ++ i) {
        int nowID = E[i].id;
        nowAng = E[i].ang;
        if (E[i].type == 0) {
            its[nowID] = Seg.insert(Line(L[nowID].A - P[id], L[nowID].B - P[id])).first;
        }
        else if (E[i].type == 1) {
            ret += (Seg.empty() || sgn(Seg.begin()->dis() - (P[id] - P[nowID]).abs()) > 0);
        }
        else if (E[i].type == 2) {
            Seg.erase(its[nowID]);
        }
    }
    return ret;
}

int main() {
    O = Point(0, 0);
    while (scanf("%d%d%d", &S, &N, &M) == 3) {
        for (int i = 0; i < N; ++ i) P[i].read();
        for (int i = 0; i < M; ++ i) {
            L[i].A.read();
            L[i].B.read();
        }
        for (int i = 0; i < S; ++ i) {
            printf("%d\n", gao(i));
        }
    }
    return 0;
}
