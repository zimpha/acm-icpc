#include <bits/stdc++.h>
using namespace std;
#define mid ((l+r)>>1)
#define lson (rt<<1)
#define rson (rt<<1|1)

const int MAXN = 1000000 + 10;

int T[MAXN << 2];

void build(int rt, int l, int r) {
  T[rt]=r-l+1;
  if (l==r) return;
  build(lson, l, mid);
  build(rson, mid+1, r);
}

int query(int rt, int l, int r, int k) {
  T[rt]--;
  if (l==r) return l;
  if (k<=T[lson]) return query(lson, l, mid, k);
  else return query(rson, mid+1, r, k-T[lson]);
}

int main() {
  int N, D, K;
  while (scanf("%d%d", &N, &D)==2 && N) {
    build(1, 1, N); K = D;
    int pos, sum;
    for (int i=1; i<=N; i++) {
      pos=query(1, 1, N, K);
      if (i == N) break;
      sum=T[1]; D = -D;
      if (D > 0) K = (K - 1 + D - 1)%sum;
      else K = (K + sum + D + 1)%sum;
      K=(K+sum)%sum;
      if (K==0)  K=sum;
    }
    printf("%d\n", pos);
  }
  return 0;
}

