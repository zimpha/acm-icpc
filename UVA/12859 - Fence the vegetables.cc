#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 400000 + 10;

struct Point {
  int x, y;
  Point() {}
  Point(int a, int b): x(a), y(b) {}
};

Point P[MAXN];
int n;

bool cmp_top(const Point &a, const Point &b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cmp_bottom(const Point &a, const Point &b) {
  return a.x < b.x || (a.x == b.x && a.y > b.y);
}

bool rv_top(Point &a, Point &b, Point &c) {
  return a.y >= b.y && c.y >= b.y;
}

bool rv_bottom(Point &a, Point &b, Point &c) {
  return a.y <= b.y && c.y <= b.y;
}

LL solve_top() {
  vector<Point> st, border;
  for (int i = 0, j = 0; i < n; ++ i) {
    while (i + 1 < n && P[i + 1].x == P[i].x) ++ i;
    while (j >= 2 && rv_top(st[j - 2], st[j - 1], P[i])) -- j, st.pop_back();
    st.push_back(P[i]); ++ j;
  }
  border.push_back(Point(st[0].x - 1, st[0].y + 1));
  int stop = -1;
  for (size_t i = 1; i < st.size(); ++ i) {
    if (st[i].y < st[i - 1].y) {stop = i; break;}
    border.push_back(Point(st[i].x - 1, st[i - 1].y + 1));
    border.push_back(Point(st[i].x - 1, st[i].y + 1));
  }
  if (stop != -1) {
    for (size_t i = stop; i < st.size(); ++ i) {
      border.push_back(Point(st[i - 1].x + 1, st[i - 1].y + 1));
      border.push_back(Point(st[i - 1].x + 1, st[i].y + 1));
    }
  }
  border.push_back(Point(st.back().x + 1, st.back().y + 1));
  LL ret = 0;
  for (size_t i = 0; i < border.size(); i += 2) {
    ret += (LL)border[i].y * (border[i + 1].x - border[i].x);
  }
  border[0].x = st[0].x; border[border.size() - 1].x = st.back().x;
  for (size_t i = 0; i < border.size(); ++ i) P[n ++] = border[i];
  return ret;
}

LL solve_bottom() {
  vector<Point> st, border;
  for (int i = 0, j = 0; i < n; ++ i) {
    while (i + 1 < n && P[i + 1].x == P[i].x) ++ i;
    while (j >= 2 && rv_bottom(st[j - 2], st[j - 1], P[i])) -- j, st.pop_back();
    st.push_back(P[i]); ++ j;
  }
  border.push_back(Point(st[0].x - 1, st[0].y - 1));
  int stop = -1;
  for (size_t i = 1; i < st.size(); ++ i) {
    if (st[i].y > st[i - 1].y) {stop = i; break;};
    border.push_back(Point(st[i].x - 1, st[i - 1].y - 1));
    border.push_back(Point(st[i].x - 1, st[i].y - 1));
  }
  if (stop != -1) {
    for (size_t i = stop; i < st.size(); ++ i) {
      border.push_back(Point(st[i - 1].x + 1, st[i - 1].y - 1));
      border.push_back(Point(st[i - 1].x + 1, st[i].y - 1));
    }
  }
  border.push_back(Point(st.back().x + 1, st.back().y - 1));
  LL ret = 0;
  for (size_t i = 0; i < border.size(); i += 2) {
    ret += (LL)border[i].y * (border[i + 1].x - border[i].x);
  }
  return ret;
}

int main() {
  while (scanf("%d", &n) == 1) {
    int x1, y1, x2, y2;
    for (int i = 0; i < n; ++ i) scanf("%d%d", &P[i].x, &P[i].y);
    if (n == 1) {puts("8 4"); continue;}
    x1 = x2 = P[0].x, y1 = y2 = P[0].y;
    for (int i = 0; i < n; ++ i) {
      x1 = min(x1, P[i].x); x2 = max(x2, P[i].x);
      y1 = min(y1, P[i].y); y2 = max(y2, P[i].y);
    }
    LL peri = (x2 - x1) * 2 + (y2 - y1) * 2 + 8;
    sort(P, P + n, cmp_top);
    LL area = solve_top();
    sort(P, P + n, cmp_bottom);
    area -= solve_bottom();
    printf("%lld %lld\n", peri, area);
  }
  return 0;
}