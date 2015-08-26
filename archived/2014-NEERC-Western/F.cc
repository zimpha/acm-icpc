#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int SIZE = 100000 + 10;

char s[SIZE], *p;
LL f[SIZE];

LL get(char c) {
  if (c >= '0' && c <= '9') return c - '0';
  else return c - 'A' + 10;
}
char tochar(int x) {
  if (x < 10) return '0' + x;
  else return 'A' + x - 10;
}

LL get(string s) {
  int l = s.size();
  LL ret = 0;
  for (size_t i = 0; i < s.size(); ++ i) {
    ret += get(s[i]) * f[l - i];
  }
  return ret;
}

string tostr(LL n) {
  string ret;
  for (int i = 20; i >= 1; -- i) {
    int c = 0;
    while (n >= f[i]) {
      n -= f[i];
      ++ c;
    }
    ret += tochar(c);
  }
  for (size_t i = 0; i < ret.size(); ++ i) {
    if (ret[i] != '0') return ret.substr(i);
  }
  return string(1, '0');
}

int main() {
  f[0] = 1;
  for (int i = 1; i < 36; ++ i) f[i] = f[i - 1] * i;
  scanf("%s", s);
  LL ret = 0;
  for (p = s; *p;) {
    int sgn = 1;
    if (*p == '+') ++ p;
    else if (*p == '-') sgn = -1, ++ p;
    string num;
    while (*p != '+' && *p != '-' && *p) {
      num += string(1, *p); ++ p;
    }
    ret += get(num) * sgn;
  }
  printf("%s\n", tostr(ret).c_str());
  return 0;
}