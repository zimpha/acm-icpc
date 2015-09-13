#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
LL fact[MAXN], inv[MAXN];

LL pm(LL a, LL n, LL m) {
  LL r=1;
  for (;n;n>>=1,a=a*a%m) if (n&1) r=r*a%m;
  return r;
}
void init(int p) {
    fact[0] = 1%p;
    for(int i = 1; i < p; ++i) {
        fact[i] = fact[i-1]*i%p;
        inv[i] = pm(i, p - 2,p);
    }
}
// O(log(n)/log(p))
LL mod_inv(int a, int p) {
  return inv[a];
}
LL mod_fact(LL n, LL p, int& e) {
    e = 0;
    if(!n) return 1;
    LL res = mod_fact(n/p, p, e);
    e += n/p;
    return (n/p%2 ? p-fact[n%p] : fact[n%p])*res%p;
}
LL mod_comb(LL n, LL k, int p) {
    if(n < 0 || k < 0 || n < k) return 0;
    int e1, e2, e3;
    LL a1 = mod_fact(n, p, e1);
    LL a2 = mod_fact(k, p, e2);
    LL a3 = mod_fact(n-k, p, e3);
    if(e1 > e2+e3) return 0;
    return a1*mod_inv(a2*a3%p, p)%p;
}
void exgcd(LL a,LL b,LL &g,LL &x,LL &y) {
  if (!b) x=1,y=0,g=a;
  else {exgcd(b,a%b,g,y,x);y-=x*(a/b);}
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    LL n, m; scanf("%lld%lld", &n, &m);
    LL M(1);
    int k, p[20]; scanf("%d", &k);
    for (int i = 0; i < k; ++ i) {
      scanf("%d", p + i);
      M *= p[i];
    }
    LL ret(0);
    for (int i = 0; i < k; ++ i) {
      init(p[i]);
      LL a = mod_comb(n, m, p[i]);
      LL tm = M / p[i], x, y, g;
      exgcd(tm,p[i],g,x,y);
      __int128 tmp = tm;
      tmp = tmp * x % M * a % M;
      ret = (ret + tmp) % M;
    }
    ret = (ret + M) % M;
    printf("%lld\n", ret);
  }
  return 0;
}
