#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, LL> PII;
const int MAXN = 100;

struct ATM {
  vector<int> Q;
  void read() {
    int k; scanf("%d", &k);
    Q.assign(k, 0);
    for (int i = 0; i < k; ++ i) scanf("%d", &Q[i]);
    sort(Q.begin(), Q.end(), greater<int>());
  }
  vector<PII> get(int x, int &cnt) {
    vector<PII> ret; ret.resize(Q.size()); cnt = 0;
    for (size_t i = 0; i < Q.size(); ++ i) {
      ret[i] = PII(Q[i], x / Q[i]); x %= Q[i];
      cnt += ret[i].second > 0;
    }
    return ret;
  }
} atm[MAXN];

vector<PII> has;
int V[MAXN], A[MAXN];
int N, M, E;

int change(int x) {
  assert(x >= 0);
  int cnt = 0;
  for (int i = 0; i < N; ++ i) {
    cnt += x / has[i].first;
    x %= has[i].first;
  }
  return cnt;
}

void pay(int x) {
  if (has.back().second > x / 2) {
    for (int i = N - 1; i >= 0; -- i) {
      int c = min(has[i].second, (LL)x / has[i].first);
      A[i] = c; has[i].second -= c; x -= c * has[i].first;
    }
  }
  else {
    for (int i = 0; i < N; ++ i) {
      int c = min(has[i].second, (LL)x / has[i].first);
      A[i] = c; has[i].second -= c; x -= c * has[i].first;
    }
  }
  if (x > 0) {
    int ret = -1, best = 1e9;
    for (int i = 0; i < N; ++ i) if (has[i].second) {
      int tmp = change(has[i].first - x);
      if (tmp < best) best = tmp, ret = i;
    }
    A[ret] ++; has[ret].second --; x -= has[ret].first;
  }
  assert(x <= 0);
  x = -x;
  for (int i = 0; i < N; ++ i) {
    has[i].second += x / has[i].first;
    x %= has[i].first;
  }
  reverse(A, A + N);
  for (int i = 0; i < N; ++ i) printf("%d%c", A[i], " \n"[i == N - 1]);
}

int main() {
  srand(time(NULL));
  scanf("%d%d", &N, &M); has.resize(N);
  for (int i = 0; i < N; ++ i) scanf("%d", &has[i].first);
  for (int i = 0; i < N; ++ i) scanf("%lld", &has[i].second);
  sort(has.begin(), has.end(), greater<PII>());
  for (int i = 0; i < M; ++ i) atm[i].read();
  scanf("%d", &E);
  for (int _ = 0; _ < E; ++ _) {
    static char op[100]; scanf("%s", op);
    int x; 
    if (op[0] == 'P') {
      scanf("%d", &x);
      pay(x);
    }
    else if (op[0] == 'R') {
      scanf("%d", &x);
      vector<PII> ret, tmp;
      int best = 1e9, cnt, id;
      for (int i = 0; i < M; ++ i) {
        tmp = atm[i].get(x, cnt);
        if (cnt < best || (cnt == best && tmp.back() > ret.back())) {
          best = cnt; ret = tmp; id = i;
        }
      }
      for (size_t i = 0; i < ret.size(); ++ i) {
        for (int j = 0; j < N; ++ j) if (ret[i].first == has[j].first) {
          has[j].second += ret[i].second;
          break;
        }
      }
      printf("%d\n", id + 1);
    }
    else if (op[0] == 'B') {
      scanf("%d", &x); N ++;
      has.push_back(PII(x, 0));
      sort(has.begin(), has.end(), greater<PII>());
    }
    else atm[M ++].read();
    fflush(stdout);
  }
  return 0;
}