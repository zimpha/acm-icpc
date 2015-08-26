#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100 + 10;
PII a[MAXN];
char s[MAXN];

#define x first
#define y second

int type(const PII &a) {
  if (a.x > a.y) return -1;
  else return (a.x < a.y);
}
bool cmp(const PII &a, const PII &b) {
  if (type(a) != type(b)) return type(a) < type(b);
  if (type(a) == -1) return a.y < b.y;
  else if (type(a) == 1) return a.x > b.x;
  return false;
}

int main() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    scanf("%s", s);
    vector<char> v;
    int x(0), y(0);
    for (char *p = s; *p; ++ p) {
      if (*p == '(') v.push_back('('), ++ x;
      else {
        if (v.size() && v.back() == '(') {
          v.pop_back(); -- x;
        }
        else v.push_back(')'), ++ y;
      }
    }
    a[i] = PII(x, y);
  }
  sort(a, a + n, cmp);
  int left = 0, flag = true;
  for (int i = 0; i < n; ++ i) {
    if (a[i].y > left) {flag = false; break;}
    left += a[i].x - a[i].y;
  }
  if (left == 0 && flag) puts("Yes");
  else puts("No");
  return 0;
}