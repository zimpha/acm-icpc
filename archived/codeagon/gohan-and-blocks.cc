#include <bits/stdc++.h>
using namespace std;

char s[100];
int n;
map<string, int> mp;

void dfs(int d, string t, string r) {
  if (d == n && t.empty()) {
    mp[r] ++;
    return;
  }
  if (d < n) dfs(d + 1, t + s[d], r);
  
  if (t.size()) {
    r += t.back();
    t.pop_back();
    dfs(d, t, r);
  }
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  dfs(0, "", "");
  printf("%d %d\n", mp[s], (int)mp.size());
  return 0;
}