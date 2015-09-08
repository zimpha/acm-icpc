#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int d[20], n, flag;

LL gcd(LL a, LL b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

void dfs(LL a, LL b, int k) {
  if (k == n) {
    if (a == 0) flag = 1;
    return;
  }
  if (a <= 0) return;
  int s = b / a;
  if (k && s <= d[k - 1]) s = d[k - 1] + 1;
  if (s == 1) s ++;
  LL t = (n - k) * b / a;
  if (t > 100) t = 100;
  for (int i = s; i <= t; ++ i) {
    d[k] = i;
    LL m = gcd(i * a - b, b * i);
    dfs((i * a - b) / m, b * i / m, k + 1);
    if (flag) return;
  }
}

char* ans[] = {
"1",
"No solution",
"2 3 6",
"2 3 7 42",
"2 3 7 78 91",
"2 3 8 56 78 91",
"2 3 9 55 70 77 99",
"2 3 10 55 70 77 90 99",
"2 3 12 45 70 78 84 90 91",
"2 3 14 55 60 70 77 84 90 99",
"2 3 16 60 66 70 77 80 88 90 99",
"2 4 12 16 60 66 70 77 80 88 90 99",
"3 4 6 12 16 60 66 70 77 80 88 90 99",
"2 4 16 24 36 60 66 70 72 77 80 88 90 99",
"3 4 6 16 24 36 60 66 70 72 77 80 88 90 99",
"2 4 24 32 36 48 60 66 70 72 77 80 88 90 96 99",
"3 4 6 24 32 36 48 60 66 70 72 77 80 88 90 96 99",
"3 5 6 20 24 32 36 48 60 66 70 72 77 80 88 90 96 99",
"4 5 6 12 20 24 32 36 48 60 66 70 72 77 80 88 90 96 99",
"3 6 10 15 20 24 30 32 36 48 60 66 70 72 77 80 88 90 96 99",
};

int main() {
  scanf("%d", &n);
  puts(ans[n - 1]);
  return 0;
}