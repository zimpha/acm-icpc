#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef tuple<int, int, int> Status;

set<Status> S;
int A, B, C, N;

const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};

bool check(int x, int y, int z) {
  Status s = make_tuple(x, y, z);
  if (S.count(s)) return 1;
  if (x < 0 || x >= A || y < 0 || y >= B || z < 0 || z >= C) return 1;
  return 0;
}

int main() {
  scanf("%d%d%d%d", &A, &B, &C, &N);
  LL ret = 2ll * A * B + 2ll * A * C + 2ll * B * C;
  for (int i = 0; i < N; ++ i) {
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    for (int k = 0; k < 6; ++ k) {
      int x = a + dx[k], y = b + dy[k], z = c + dz[k];
      if (check(x, y, z)) -- ret;
      else ++ ret;
    }
    S.insert(make_tuple(a, b, c));
  }
  cout << ret << endl;
  return 0;
}
