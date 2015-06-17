#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v;
  for (int i = 0; i < 545; ++ i) {
    int x; scanf("%*s%*s%*s%d", &x);
    v.push_back(x);
  }
  vector<int> d;
  for (int i = 1; i < 545; ++ i) {
    d.push_back(v[i] - v[i - 1]);
  }
  int s[54] = {0};
  for (int i = 9; i < 10; ++ i) {
    for (int j = 0; j < 54; ++ j) {
      s[j] += d[i * 54 + j];
    }
  }
  for (int j = 0; j < 54; ++ j) s[j] /= 1;
  for (int i = 0, x = v.back(); i < 50; ++ i) {
    x += s[i];
    printf("%d\n", x);
  }
  return 0;
}