#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<string, string> PSS;

map<PSS, vector<int> > mp;
char buf[10000];

bool check(string &s) {
  if (s.size() & 1) return 0;
  for (auto &c: s) c = tolower(c);
  for (size_t i = 0; i < s.size(); i += 2) {
    if (s[i] != 'h' || s[i + 1] != 'e') return 0;
  }
  return s.size() > 2;
}

int main() {
  while (scanf("%s", buf) == 1) {
    string name1, name2;
    for (int i = 0, f(0); buf[i]; ++ i) {
      if (buf[i] == '>') f = 1;
      if (isalpha(buf[i])) {
        if (f) name2 += buf[i];
        else name1 += buf[i];
      }
    }
    if (name1 > name2) swap(name1, name2);
    gets(buf);
    for (int i = 0; buf[i]; ++ i) {
      if (!isalpha(buf[i])) buf[i] = ' ';
    }
    stringstream sin(buf);
    bool flag(0);
    string s;
    while (sin >> s) {
      flag |= check(s);
    }
    mp[PSS(name1, name2)].push_back(flag);
  }
  int tot(0), cnt(0);
  for (auto &x: mp) {
    vector<int> p = x.second;
    for (size_t i = 0; i < p.size(); ++ i) {
      tot += p[i]; cnt += p[i];
    }
    if (p.empty() || p.back() == 0) tot ++;
  }
  printf("%.0f%%\n", 100.0 * cnt / tot);
  return 0;
}
