#include <bits/stdc++.h>
using namespace std;

int main() {
  int X[5], Y[5];
  while (scanf("%d", &X[0]) == 1) {
    for (int i = 1; i < 5; ++ i) scanf("%d", X + i);
    for (int i = 0; i < 5; ++ i) scanf("%d", Y + i);
    bool flag = true;
    for (int i = 0; i < 5; ++ i) {
      if (X[i] == Y[i]) flag = false;
    }
    puts(flag ? "Y" : "N");
  }
  return 0;
}
