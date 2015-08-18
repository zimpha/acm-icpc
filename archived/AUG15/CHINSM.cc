#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;

int A[MAXN], nx[MAXN], mk[MAXN];
int N, K, global;

struct ST {
  const static int MAXN = 200000;
  int mx[MAXN][20], lg[MAXN], n;
  void build(int a[], int n) {
    lg[0]=-1; this->n=n;
    for (int i=1;i<=n;++i) lg[i]=lg[i>>1]+1;
    for (int i=0;i<n;++i) mx[i][0]=a[i];
    for (int j=1;(1<<j)<=n;++j) {
      for (int i=0;i+(1<<j)<=n;++i) {
        mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
      }
    }
  }
  int ask(int a, int b) {
    if (a>b) swap(a,b); int k=lg[b-a+1];
    return max(mx[a][k],mx[b-(1<<k)+1][k]);
  }
} AC;

int main() {
  scanf("%d%d", &N, &K); global = -1;
  memset(mk, -1, sizeof(mk));
  memset(nx, -1, sizeof(nx));
  for (int i = 0; i < N; ++ i) {
    int x; scanf("%d", &x);
    nx[i] = mk[x]; 
    if (x > K) nx[i] = max(nx[i], global);
    x -= K;
    if (x < 0) continue;
    else if (x == 0) global = i;
    else {
      for (int y = 1; y * y <= x; ++ y) if (x % y == 0) {
        if (y > K) mk[y] = i;
        if (x / y > K) mk[x / y] = i;
      }
    }
  }
  AC.build(nx, N);
  LL ret(0);
  for (int i = 0; i < N; ++ i) {
    int p = AC.ask(nx[i] + 1, i);
    ret += i - p;
  }
  cout << ret << endl;
}