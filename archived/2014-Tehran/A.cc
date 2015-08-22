#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    if (a == 0 && b == 0 && c == 0 && d == 0) break;
    cout << c - b << " " << d - a << endl;
  }
  return 0;
}

