#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  string s;
  while (getline(cin, s) && s != "#") {
    vector<string> v;
    for (size_t i = 0; i < s.size(); i += v.back().size()) {
      if (s[i] == 'n') v.push_back(s.substr(i, 5));
      else v.push_back(s.substr(i, 4));
    }
    reverse(v.begin(), v.end());
    int a = 0, b = 1;
    if (v[0] == "north") a = 0;
    else a = 90;
    for (size_t i = 1; i < v.size(); ++ i) {
      a *= 2; b *= 2;
      if (v[i] == "north") a -= 90;
      else a += 90;
    }
    int g = __gcd(a, b);
    a /= g, b /= g;
    if (b > 1) cout << a << "/" << b << endl;
    else cout << a << endl;
  }
  return 0;
}