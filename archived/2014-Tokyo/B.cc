#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL solve1(char s[]) {
  stack<LL> a;
  stack<char> o;
  for (int i = 0; s[i]; ++ i) {
    if (s[i] >= '0' && s[i] <= '9') a.push(s[i] - '0');
    else {
      if (s[i] == '+') {
        while (!o.empty() && o.top() == '*') {
          LL x = a.top(); a.pop();
          LL y = a.top(); a.pop();
          a.push(x * y); o.pop();
        }
        o.push('+');
      }
      else o.push(s[i]);
    }
  }
  while (!o.empty()) {
    LL x = a.top(); a.pop();
    LL y = a.top(); a.pop();
    if (o.top() == '+') a.push(x + y);
    else a.push(x * y);
    o.pop();
  }
  return a.top();
}

LL solve2(char s[]) {
  LL r(0), p(0);
  for (int i = 0; s[i]; ++ i) {
    if (s[i] >= '0' && s[i] <= '9') {
      if (p) r = r * (s[i] - '0');
      else r += s[i] - '0';
    }
    else {
      p = s[i] == '*';
    }
  }
  return r;
}

int main() {
  char s[100]; int n;
  while (scanf("%s%d", s, &n) == 2) {
    LL r1 = solve1(s);
    LL r2 = solve2(s);
    if (r1 == n && r2 == n) puts("U");
    else if (r1 == n && r2 != n) puts("M");
    else if (r1 != n && r2 == n) puts("L");
    else puts("I");
  }
  return 0;
}

