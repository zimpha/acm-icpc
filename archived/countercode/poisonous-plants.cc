#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
int u[MAXN], a[MAXN], n;

void add(int x, int v) {
  for (; x <= n; x += ~x & x + 1) u[x] += v;
}
int get(int x) {
  int r(0);
  for (; x >= 0; x -= ~x & x + 1) r += u[x];
  return r;
}
int kth(int k) {
  int left = 1, right = n;
  while (left < right) {
    int mid = (left + right) >> 1;
    if (get(mid) >= k) right = mid;
    else left = mid + 1;
  }
  return left;
}

int main() {
  int ret(0); scanf("%d", &n);
  vector<int> rv;
  set<int> S;
  for (int i = 1; i <= n; ++ i) {
    scanf("%d", a + i);
    add(i, 1); S.insert(i);
    if (i > 1 && a[i] > a[i - 1]) rv.push_back(i);
  }
  int t = n;
  while (rv.size()) {
    vector<int> cnt; ++ ret;
    for (size_t i = 0; i < rv.size(); ++ i) {
      cout << rv[i] << " "; S.erase(rv[i]);
      cnt.push_back(get(rv[i]));
    }
    cout << endl;
    vector<int> pt;
    for (size_t i = 0, j; i < cnt.size(); ++ i) {
      for (j = i; j + 1 < cnt.size() && cnt[j + 1] == cnt[j] + 1; ++ j);
      if (cnt[i] - 1 >= 1) {
        int x = kth(cnt[i] - 1);
        if (S.count(x)) pt.push_back(x);
      }
      if (cnt[j] + 1 <= t) {
        int x = kth(cnt[j] + 1);
        if (S.count(x)) pt.push_back(x);
      }
      i = j;
    }
    sort(pt.begin(), pt.end());
    pt.erase(unique(pt.begin(), pt.end()), pt.end());
    t -= rv.size();
    cnt.resize(pt.size());
    for (size_t i = 0; i < rv.size(); ++ i) add(rv[i], -1);
    rv.clear();
    for (size_t i = 0; i < pt.size(); ++ i) cnt[i] = get(pt[i]);
    for (size_t i = 1; i < pt.size(); ++ i) {
      if (cnt[i] == cnt[i - 1] + 1 && a[pt[i]] > a[pt[i - 1]]) {
        rv.push_back(pt[i]);
      }
    }
  }
  printf("%d\n", ret);
  return 0;
}