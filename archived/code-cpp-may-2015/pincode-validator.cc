#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000 + 10;
char s[MAXN];
set<string> pin;

bool check(char *s, int p, int n) {
  if (!isdigit(s[p]) || !isdigit(s[p + 1]) || !isdigit(s[p + 2])) return false;
  if (s[p + 3] != '-') return false;
  if (!isdigit(s[p + 4]) || !isdigit(s[p + 5])) return false;
  if (s[p + 6] != '-') return false;
  if (!isdigit(s[p + 7]) || !isdigit(s[p + 8])) return false;
  if (s[p + 9] != '-') return false;
  for (int i = 1; i <= 8; ++ i) {
    if (!isdigit(s[p + 9 + i])) return false;
  }
  return s[p + 18] == '-' && isupper(s[p + 19]);
}

void extract(char s[]) {
  int n = strlen(s);
  for (int i = 0; i + 20 <= n; ++ i) {
    if (check(s, i, n)) pin.insert(string(s + i, s + i + 20));
  }
}

int main() {
  int n; scanf("%d ", &n);
  for (int i = 0; i < n; ++ i) {
    gets(s);
    extract(s);
  }
  for (auto &x: pin) printf("%s\n", x.c_str());
  if (pin.empty()) puts("JUNK");
  return 0;
}
