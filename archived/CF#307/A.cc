#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++ i) scanf("%d", &v[i]);
  for (int i = 0; i < n; ++ i) {
    int r(1);
    for (int j = 0; j < n; ++ j) r += v[j] > v[i];
    cout << r << " ";
  }
  cout << endl;
  return 0;
}

