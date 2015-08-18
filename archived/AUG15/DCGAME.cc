#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1000000 + 10;

map<PII, vector<int> > mp;
vector<int> Xs;
int A[MAXN], L[MAXN], R[MAXN], N, M;
LL ret[MAXN];

inline LL C(LL x) {
  if (x <= 0) return 0;
  return x * (x - 1) / 2 + x;
}

int main() {
  scanf("%d%d", &N, &M);
  Xs.resize(N); ret[0] = 0;
  for (int i = 1; i <= N; ++ i) {
    scanf("%d", A + i);
    Xs[i - 1] = A[i]; ret[i] = 0;
  }
  sort(Xs.begin(), Xs.end());
  Xs.erase(unique(Xs.begin(), Xs.end()), Xs.end());
  A[0] = A[N + 1] = N;
  for (int i = N; i >= 1; -- i) {
    A[i] = lower_bound(Xs.begin(), Xs.end(), A[i]) - Xs.begin();
    for (R[i] = i + 1; A[R[i]] <= A[i]; R[i] = R[R[i]]);
  }
  for (int i = 1; i <= N; ++ i) {
    for (L[i] = i - 1; A[L[i]] <= A[i]; L[i] = L[L[i]]);
    mp[PII(L[i], R[i])].push_back(i);
  }
  for (auto &x: mp) {
    int l = x.first.first, r = x.first.second;
    vector<int> &pt = x.second;
    int val = A[pt[0]], pv = l;
    ret[val] += C(r - l - 1) - C(r - pt.back() - 1);
    for (size_t i = 0; i < pt.size(); ++ i) {
      ret[val] -= C(pt[i] - pv - 1);
      pv = pt[i];
    }
  }
  for (int i = N - 1; i >= 0; -- i) ret[i] += ret[i + 1];
  for (int i = 0, k; i < M; ++ i) {
    char t[10], s[10];
    scanf("%s%d%s", t, &k, s);
    if (t[0] == '>') {
      k = upper_bound(Xs.begin(), Xs.end(), k) - Xs.begin();
      if (ret[k] & 1) putchar(s[0]);
      else {
        if (s[0] == 'D') putchar('C');
        else putchar('D');
      }
    }
    else if (t[0] == '<') {
      k = lower_bound(Xs.begin(), Xs.end(), k) - Xs.begin();
      if ((ret[0] - ret[k]) & 1) putchar(s[0]);
      else {
        if (s[0] == 'D') putchar('C');
        else putchar('D');
      }
    }
    else {
      int i = lower_bound(Xs.begin(), Xs.end(), k) - Xs.begin();
      if (i < (int)Xs.size() && Xs[i] == k) {
        if ((ret[i] - ret[i + 1]) & 1) putchar(s[0]);
        else {
          if (s[0] == 'D') putchar('C');
          else putchar('D');
        }
      }
      else {
        if (s[0] == 'D') putchar('C');
        else putchar('D');
      }
    }
  }
  return 0;
}