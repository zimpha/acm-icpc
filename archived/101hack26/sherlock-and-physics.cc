#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; cin >> T;
  for (int _ = 0; _ < T; ++ _) {
    LL R, S; cin >> R >> S;
    LL k = R / S; R %= S;
    LL a, b;
    if (R * 4 <= S) {
      cout << k * S + R << " ";
      a = R; b = S;
      cout << a / __gcd(a, b) << "/" << b / __gcd(a, b) << endl;
    }
    else {
      cout << k * S + S << " " << "0/1" << endl;
    }
  }
  return 0;
}

