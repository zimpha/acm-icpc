#include "kanapka.h"

#include <stdio.h>

long long max(long long a, long long b) {
    return (a > b) ? a : b;
}

int main() {
  long long N = 0;
  N = GetN();
  if (N == 1) {
    printf("%lld\n", max(0, GetTaste(0)));
  } else {
    printf("%lld\n", max(max(GetTaste(0), GetTaste(N - 1)),
            max(0, GetTaste(0) + GetTaste(N - 1))));
  }
  return 0;
}
