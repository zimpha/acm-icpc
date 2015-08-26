#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<char, int> PII;

#define c first
#define l second

vector<PII> A, B, C;
vector<PII> ret;

void input(vector<PII> &v) {
  char s[10]; v.clear();
  while (scanf("%s", s) == 1 && s[0] != '$') {
    int x; scanf("%d", &x);
    v.push_back(PII(s[0], x));
  }
}

void output(const vector<PII> &v) {
  for (size_t i = 0, j = 0; i < v.size(); i = j) {
    char c = v[i].c; int l = 0;
    for (j = i; j < v.size() && v[j].c == v[i].c; ++ j) {
      l += v[j].l;
    }
    if (l) printf("%c %d ", c, l);
  }
  puts("$");
}

bool check(size_t s) {
  if (A.size() - s < B.size()) return false;
  for (size_t i = 1; i + 1 < B.size(); ++ i) {
    if (A[s + i].c != B[i].c || A[s + i].l != B[i].l) return false;
  }
  int end = s + B.size() - 1;
  return A[end].c == B.back().c && A[end].l >= B.back().l;
}

int main() {
  input(A); input(B); input(C);
  if (B.size() == 1) {
    ret = A;
    for (size_t i = 0; i < A.size(); ++ i) {
      if (A[i].c != B[0].c || A[i].l < B[0].l) continue;
      ret.clear();
      for (size_t j = 0; j < i; ++ j) ret.push_back(A[j]);
      for (size_t j = 0; j < C.size(); ++ j) ret.push_back(C[j]);
      if (A[i].l - B[0].l) ret.push_back(PII(A[i].c, A[i].l - B[0].l));
      for (size_t j = i + 1; j < A.size(); ++ j) ret.push_back(A[j]);
      break;
    }
    output(ret);
    return 0;
  }
  ret = A;
  for (size_t i = 0; i < A.size(); ++ i) {
    if (A[i].c != B[0].c || A[i].l < B[0].l) continue;
    if (!check(i)) continue;
    ret.clear();
    for (size_t j = 0; j < i; ++ j) ret.push_back(A[j]);
    if (A[i].l - B[0].l) ret.push_back(PII(A[i].c, A[i].l - B[0].l));
    for (size_t j = 0; j < C.size(); ++ j) ret.push_back(C[j]);
    int ed = i + B.size() - 1;
    if (A[ed].l - B.back().l) ret.push_back(PII(A[ed].c, A[ed].l - B.back().l));
    for (size_t j = ed + 1; j < A.size(); ++ j) ret.push_back(A[j]);
    break;
  }
  output(ret);
  return 0;
}