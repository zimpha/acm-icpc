#include <bits/stdc++.h>
using namespace std;

int main() {
  for (int s; scanf("%d", &s), s; ) {
    int left = 1, right = 20000;
    while (left < right) {
      int mid = (left + right) >> 1;
      if (mid * (mid + 1) / 2 > s) right = mid;
      else left = mid + 1;
    }
    printf("%d %d\n", left * (left + 1) / 2 - s, left);
  }
  return 0;
}
