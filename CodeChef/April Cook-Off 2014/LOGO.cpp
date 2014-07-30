#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <cmath>

using namespace std;

const double DEPTH = -100000;
const int XMAX = 320;
const int YMAX = 240;
const double EPS = 1e-9;

vector<vector<double> > depth(YMAX, vector<double>(XMAX));
vector<vector<char> > color(YMAX, vector<char>(XMAX));

inline bool isEqual(double d1, double d2)
{
    return fabs(d1-d2) < EPS;
}

struct point
{
    int x, y, z;
};

istream& operator>>(istream& in, point &p)
{
    return in >> p.x >> p.y >> p.z;
}

struct edge
{
    int ymin, ymax, x, n, d, sign;
    void set(int _ymin, int _ymax, int _x, int _n, int _d)
    {
        ymin = _ymin;
        ymax = _ymax;
        x = _x;
        n = abs(_n);
        d = abs(_d);
        sign = ((_n < 0) == (_d < 0)) ? 1 : -1;
    }
};

class triangle
{
public:
    triangle(point _p1, point _p2, point _p3, char _c)
        : p1(_p1), p2(_p2), p3(_p3), color(_c)
    {}
    void draw();

private:
    point p1, p2, p3;
    edge e1, e2, e3;
    char color;
    int a, b, c, d;

    void setPlane();
    void setEdges();
};

void triangle::setPlane()
{
    a = p1.y*(p2.z-p3.z) + p2.y*(p3.z-p1.z) + p3.y*(p1.z-p2.z);
    b = p1.z*(p2.x-p3.x) + p2.z*(p3.x-p1.x) + p3.z*(p1.x-p2.x);
    c = p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y) + p3.x*(p1.y-p2.y);
    d = -p1.x*(p2.y*p3.z-p3.y*p2.z) - p2.x*(p3.y*p1.z-p1.y*p3.z) - p3.x*(p1.y*p2.z-p2.y*p1.z);
    assert(d == -(a*p1.x+b*p1.y+c*p1.z));
}

void triangle::setEdges()
{
    //Sort points by y
    if (p1.y > p2.y)
        swap(p1, p2);
    if (p2.y > p3.y)
        swap(p2, p3);
    if (p1.y > p2.y)
        swap(p1, p2);
    e1.set(p1.y, p2.y, p1.x, p1.y - p2.y, p1.x - p2.x);
    e2.set(p1.y, p3.y, p1.x, p1.y - p3.y, p1.x - p3.x);
    e3.set(p2.y, p3.y, p2.x, p2.y - p3.y, p2.x - p3.x);
}

inline int roundOff(double d)
{
    return static_cast<int>(d+0.5);
}

void triangle::draw()
{
    setPlane();
    setEdges();
    int x, x1, x2, px1, px2, xl, xr, y = e1.ymin;
    double z;
    int c1 = 0, c2 = 0;
    int parts = 1;
    if (e1.n == 0)
        e1 = e3;
    else if (e2.n == 0)
        e2 = e3;
    else
        parts++;
    px1 = e1.x;
    px2 = e2.x;
    e1.n*=e1.sign;
    e2.n*=e2.sign;
    while (parts--) {
        for (;y <= e1.ymax && y <= e2.ymax; y++, c1 += e1.d, c2 += e2.d) {
            assert(0 <= y && y < YMAX);
            x1 = roundOff(px1+static_cast<double>(c1)/e1.n);
            px1 += c1/e1.n;
            c1 %= e1.n;
            x2 = roundOff(px2+static_cast<double>(c2)/e2.n);
            px2 += c2/e2.n;
            c2 %= e2.n;
            xl = min(x1, x2);
            xr = max(x1, x2);
            for (x = xl; x <= xr; x++) {
                assert(0 <= x && x < XMAX);
                z = static_cast<double>(-(a*x + b*y + d))/c;
                assert(z >= DEPTH);
                if ((!isEqual(z, depth[y][x]) && z > depth[y][x]) || (isEqual(z, depth[y][x]) && ::color[y][x] < color)) {
                    depth[y][x] = z;
                    ::color[y][x] = color;
                }
            }
        }
        if (y > e1.ymax) {
            e1 = e3;
            c1 = 0;
            px1 = e1.x;
            e1.n*=e1.sign;
        } else {
            e2 = e3;
            c2 = 0;
            px2 = e2.x;
            e2.n*=e2.sign;
        }
    }
}

bool onright(point p1, point p2, point p3)
{
    int dx1, dy1, dx2, dy2;
    dx1 = p2.x - p1.x;
    dy1 = p2.y - p1.y;
    dx2 = p3.x - p1.x;
    dy2 = p3.y - p1.y;
    if (dy1*dx2 > dy2*dx1)
        return true;
    return false;
}

int main(int argc, const char *argv[])
{
    int n, i, j, t, x, y, z, c;
    vector<point> points(4);
    for (i = 0; i < YMAX; i++)
        for(j = 0; j < XMAX; j++) {
            color[i][j] = '0';
            depth[i][j] = DEPTH;
        }
    cin >> n;
    while (n--) {
        cin >> t >> c;
        for (i = 0; i < 2 + t; i++)
            cin >> points[i];
        c += '0';
        if (t == 1) { //triangle
            triangle tri(points[0], points[1], points[2], c);
            tri.draw();
        } else { //quadrilateral
            if (onright(points[0], points[1], points[2])) {
                triangle tri(points[0], points[1], points[3], c);
                tri.draw();
                triangle tri2(points[1], points[2], points[3], c);
                tri2.draw();
            } else if (onright(points[2], points[3], points[0])) {
                triangle tri(points[1], points[2], points[3], c);
                tri.draw();
                triangle tri2(points[0], points[1], points[3], c);
                tri2.draw();
            } else {
                triangle tri(points[0], points[1], points[2], c);
                tri.draw();
                triangle tri2(points[2], points[3], points[0], c);
                tri2.draw();
            }
        }
    }
    for (i = 0; i < YMAX; i++) {
        for(j = 0; j < XMAX; j++)
            putchar(color[i][j]);
        putchar('\n');
    }
    return 0;
}
 
