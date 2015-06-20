#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

int after[1000010];

bool solve(int n, int m) {
  after[0] = after[n] = 0;
  for (int i = 1; i < n; ++ i) after[i] = 1, m --;
  if (m < 0) return false;
  if (m >= 2) after[0] = 2, m -= 2;
  else if (m >= 1) after[0] = 1, m -= 1;
  if (m >= 2) after[n] = 2, m -= 2;
  else if (m >= 1) after[n] = 1, m -= 1;
  for (int i = 1; i < n; ++ i) {
    if (m == 0) break;
    after[i] = 2;
    m --;
  }
  if (m) return false;
  return true;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (solve(n, m)) {
    if (after[0]) {
      while (after[0] --) putchar('1');
    }
    for (int i = 1; i <= n; ++ i) {
      putchar('0');
      while (after[i] --) putchar('1');
    }
    puts("");
  } else {
    puts("-1");
  }
  return 0;
}