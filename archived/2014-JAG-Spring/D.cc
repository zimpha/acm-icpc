#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100;
map<PII, string> dp;
char s[MAXN];

bool isNum(int l, int r) {
  for (int i = l; i <= r; ++ i) {
    if (!(isdigit(s[i]) || s[i] == '?')) return false;
  }
  return true;
}

bool Less(const string &x, const string &y) {
  if (x.size() > y.size()) return false;
  if (x.size() < y.size()) return true;
  for (size_t i = 0; i < x.size(); ++ i) {
    if (x[i] > y[i]) return false;
    if (x[i] < y[i]) return true;
  }
  return false;
}

void upd(string &x, const string &y) {
  if (Less(x, y)) x = y;
}

string solve(int l, int r) {
  if (dp.count(PII(l, r))) return dp[PII(l, r)];
  if (isNum(l, r)) {
    string ret = "";
    for (int i = l; i <= r; ++ i) {
      if (s[i] == '?') ret += '9';
      else ret += s[i];
    }
    if (ret[0] == '0' && ret.size() > 1) ret = "";
    return dp[PII(l, r)] = ret;
  }
  if (r - l + 1 < 6) return "";
  if (s[l] != 'L' && s[l] != 'R' && s[l] != '?') return "";
  if (s[r] != ')' && s[r] != '?') return "";
  if (s[l + 1] != '(' && s[l + 1] != '?') return "";
  string ret = "";
  for (int i = l + 3; i <= r - 2; ++ i) if (s[i] == '?' || s[i] == ',') {
    string x = solve(l + 2, i - 1);
    string y = solve(i + 1, r - 1);
    if (x == "" || y == "") continue;
    if (s[l] == 'L' || s[l] == '?') upd(ret, x);
    if (s[l] == 'R' || s[l] == '?') upd(ret, y);
  }
  return dp[PII(l, r)] = ret;
}

int main() {
  scanf("%s", s);
  int n = strlen(s);
  string ret = solve(0, n - 1);
  if (ret == "") ret = "invalid";
  cout << ret << endl;
  return 0;
}