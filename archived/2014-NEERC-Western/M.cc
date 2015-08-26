#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long LL;
typedef double flt;
typedef pair<flt, flt> PII;
const flt eps = 1e-9;
flt dis(PII a, PII b) {
  return hypot(a.x - b.x, a.y - b.y);
}

flt area, len;

bool solve(PII A, PII B, PII C) {
  flt a = dis(B, C), b = dis(A, C), c = dis(A, B);
  flt cosa = (b * b + c * c - a * a) / (2.0 * b * c);
  flt sina = sqrt(1.0 - cosa * cosa);
  flt s = (a + b + c) * 0.5, t = area / sina;
  flt delta = s * s - 4.0 * t;
  if (delta < -eps) return false;
  flt x = (sqrt(delta) + s) * 0.5, y = s - x;
  if(b > c) swap(b, c), swap(B, C);
  if (x > y) swap(x, y);
  if (x >= -eps && x <= b + eps && y >= -eps && y <= c + eps) {
    PII P(A.x + (C.x - A.x) * x / b, A.y + (C.y - A.y) * x / b);
    PII Q(A.x + (B.x - A.x) * y / c, A.y + (B.y - A.y) * y / c);
    printf("%.18f %.18f\n%.18f %.18f\n", P.x, P.y, Q.x, Q.y);
    return true;
  }
  x = (s - sqrt(delta)) * 0.5, y = s - x;
  if (x > y) swap(x, y);
  if (x >= -eps && x <= b + eps && y >= -eps && y <= c + eps) {
    PII P(A.x + (C.x - A.x) * x / b, A.y + (C.y - A.y) * x / b);
    PII Q(A.x + (B.x - A.x) * y / c, A.y + (B.y - A.y) * y / c);
    printf("%.18f %.18f\n%.18f %.18f\n", P.x, P.y, Q.x, Q.y);
    return true;
  }
  return false;
}

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  area = 0.5 * b * c;
  PII A(0, 0), B(c, 0), C(a, b);
  solve(A, B, C) || solve(B, C, A) || solve(C, A, B);
  return 0;
}