#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double flt;
typedef pair<int, int> PII;
const flt eps = 1e-8;

struct Point {
  flt x, y;
  Point() {}
  Point(flt x, flt y): x(x), y(y) {}
  Point(const Point &a): x(a.x), y(a.y) {}
  Point operator + (const Point &rhs) const {
    return Point(x + rhs.x, y + rhs.y);
  }
  Point operator - (const Point &rhs) const {
    return Point(x - rhs.x, y - rhs.y);
  }
  Point operator * (const flt k) const {
    return Point(x * k, y * k);
  }
  Point operator / (const flt k) const {
    return Point(x / k, y / k);
  }
  flt det(const Point &rhs) const {
    return x * rhs.y - y * rhs.x;
  }
  flt dot(const Point &rhs) const {
    return x * rhs.x + y * rhs.y;
  }
  flt sqr() const {
    return x * x + y * y;
  }
  flt abs() const {
    return hypot(x, y);
  }
};

int sgn(flt x) {
  if (x < -eps) return -1;
  else return x > eps;
}

Point sym(const Point &O, const Point &A, const Point &B) {
  if (sgn((A - O).det(B - O)) == 0) return O;
  Point AB = B - A;
  Point AP = AB * ((O - A).dot(AB) / AB.sqr());
  return O + (A - O + AP) * 2.0;
}

Point inter(const Point &A, const Point &B, const Point &C, const Point &D) {
  Point AB = B - A, CD = D - C;
  return A + AB * (CD.det(C - A) / CD.det(AB));
}

struct Factor {
  Point A, B;
  int type;// 0 point, 1 line
  Factor() {}
  Factor(const Point &a) : A(a), type(0) {}
  Factor(const Point &a, const Point &b): A(a), B(b), type(1) {}
  Factor operator + (const Factor &rhs) const {
    if (type == 0) {
      if (rhs.type == 0) return Factor(A, rhs.A);
      else return Factor(sym(A, rhs.A, rhs.B));
    }
    else if (type == 1) {
      if (rhs.type == 0) return Factor(sym(rhs.A, A, B));
      else return Factor(inter(A, B, rhs.A, rhs.B));
    }
    else assert(false);
  }
  void print() {
    printf("%.10f %.10f\n", A.x, A.y);
  }
};

char s[200], *p;

bool check(char c) {
  return c == '-' || isdigit(c);
}

int getInt() {
  int sgn = 1, ret = 0;
  if (*p == '-') ++ p, sgn = -1;
  while (isdigit(*p)) ret = ret * 10 + (*p - '0'), ++ p;
  return sgn * ret;
}

Point getP() {
  int x = getInt(); ++ p;
  int y = getInt();
  return Point(x, y);
}

int main() {
  while (scanf("%s", s) == 1 && s[0] != '#') {
    stack<char> op;
    stack<Factor> num;
    for (p = s; *p; ) {
      if (*p == '(') {
        if (check(*(p + 1))) {
          ++ p;
          Factor now(getP());
          ++ p;
          while (!op.empty() && op.top() == '@') {
            Factor pre = num.top(); num.pop(); op.pop();
            now = now + pre;
          }
          num.push(now);
        }
        else op.push('('), ++ p;
      }
      else if (*p == ')') {
        assert(op.top() == '('); 
        op.pop(); ++ p;
        Factor now = num.top(); num.pop();
        while (!op.empty() && op.top() == '@') {
          Factor pre = num.top(); num.pop(); op.pop();
          now = now + pre;
        }
        num.push(now);
      }
      else if (*p == '@') {
        op.push('@'); ++ p;
      }
    }
    num.top().print();
  }
  return 0;
}