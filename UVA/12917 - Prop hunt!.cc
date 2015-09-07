#include <bits/stdc++.h>
using namespace std;

int main() {
  int p, h, o; 
  while (cin >> p >> h >> o) {
    if (o - p >= h) puts("Props win!");
    else puts("Hunters win!");
  }
  return 0;
}
