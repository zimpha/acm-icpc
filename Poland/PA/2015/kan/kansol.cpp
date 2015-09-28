#include "kanapka.h"

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  long long N = GetN();
  if (N == 1)
    cout << max(0ll, GetTaste(0)) << endl;
  else
    cout << max(max(GetTaste(0), GetTaste(N - 1)),
            max(0ll, GetTaste(0) + GetTaste(N - 1))) << endl;
  return 0;
}
