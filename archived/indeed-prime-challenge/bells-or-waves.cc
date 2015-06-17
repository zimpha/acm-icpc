#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef double flt;
typedef pair<flt, flt> PII;
const flt PI = acos(-1.0);

bool square(vector<PII> &p) {
  sort(p.begin(), p.end());
  flt a(0), b(0);
  for (size_t i = 0; i < p.size(); ++ i) {
    a = min(a, p[i].y); b = max(b, p[i].y);
  }
  for (size_t i =0; i < p.size(); ++ i) {
    if (!(abs(a - p[i].y) <= 0.1 || abs(b - p[i].y) < 0.1)) return false;
  }
  puts("square-wave");
  vector<int> v;
  for (int i = 0; i < 500; ++ i) {
    if (p[i].y > 0) v.push_back(1);
    else v.push_back(0);
  }
  v.erase(unique(v.begin(), v.end()), v.end());
  assert((v.size() / 2) % 5 == 0);
  printf("%d\n", (int)v.size() / 2);
  return true;
}

void sine(vector<PII> &p) {
  puts("sine-wave");
  for (int f = 5; f <= 50; f += 5) {
    bool flag = true;
    for (size_t i = 0; i < p.size(); ++ i) {
      flag &= abs(sin(PI * 2 * f * p[i].x) - p[i].y) <= 0.1;
    }
    if (flag) {
      printf("%d\n", f);
      break;
    }
  }
}

int main() {
  int n; scanf("%d", &n);
  vector<PII> p(n);
  for (int i = 0; i < n; ++ i) {
    scanf("%lf%lf", &p[i].x, &p[i].y);
  }
  if (!square(p)) sine(p);
  return 0;
}
