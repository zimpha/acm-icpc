#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int cmpI(string &a, string &b) {
  if (a[0] == '-' && b[0] == '-') {
    if (a.size() < b.size()) return 1;
    if (a.size() > b.size()) return -1;
    for (size_t i = 1; i < a.size(); ++ i) {
      if (a[i] > b[i]) return -1;
      if (a[i] < b[i]) return 1;
    }
    return 0;
  }
  else if (a[0] == '-' && b[0] != '-') return -1;
  else if (a[0] != '-' && b[0] == '-') return 1;
  else {
    if (a.size() < b.size()) return -1;
    if (a.size() > b.size()) return 1;
    for (size_t i = 0; i < a.size(); ++ i) {
      if (a[i] > b[i]) return 1;
      if (a[i] < b[i]) return -1;
    }
    return 0;
  }
}

int cmpF(string &a, string &b) {
  while (a.size() > 1 && a.back() == '0') a.pop_back();
  while (b.size() > 1 && b.back() == '0') b.pop_back();
  for (size_t i = 0; i < min(a.size(), b.size()); ++ i) {
    if (a[i] > b[i]) return 1;
    if (a[i] < b[i]) return -1;
  }
  if (a.size() == b.size()) return 0;
  else if (a.size() < b.size()) return -1;
  else return 1;
}

pair<string, string> get(string s) {
  string I, F;
  bool f(0);
  for (size_t i = 0; i < s.size(); ++ i) {
    if (s[i] == '.') {f = 1; continue;}
    if (f) F += s[i];
    else I += s[i];
  }
  return make_pair(I, F);
}

int main() {
  string A, B;
  for (int cas(1); cin >> A >> B; ++ cas) {
    pair<string, string> ap = get(A);
    pair<string, string> bp = get(B);
    int i = cmpI(ap.first, bp.first);
    int f = cmpF(ap.second, bp.second);
    printf("Case %d: ", cas);
    if (i < 0) puts("Smaller");
    else if (i > 0) puts("Bigger");
    else {
      if (ap.first[0] == '-') {
        if (f == 0) puts("Same");
        else if (f > 0) puts("Smaller");
        else puts("Bigger");
      }
      else {
        if (f == 0) puts("Same");
        else if (f < 0) puts("Smaller");
        else puts("Bigger");
      }
    }
  }
  return 0;
}
