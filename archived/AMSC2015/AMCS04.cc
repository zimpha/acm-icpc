#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

LL phi(LL n) {//O(sqrt{N})
  LL ret=n;
  for (LL i=2;i*i<=n;++i) if (n%i==0) {
    ret=ret/i*(i-1);
    while (n%i==0) n/=i;
  }
  if (n>1) ret=ret/n*(n-1);
  return ret;
}

LL pm(LL a, LL n, LL m) {
  LL r=1;
  for (;n;n>>=1,a=a*a%m) if (n&1) r=r*a%m;
  return r;
}

int log(int a, int r, int m){
  if(r>=m) return -1;
  int i,g,x,c=0,at=int(2+sqrt(m));
  for(i=0,x=1%m;i<50;i++,x=LL(x)*a%m) if(x==r) return i;
  for(g=x=1;__gcd(int(LL(x)*a%m),m)!=g;c++) g=__gcd(x=LL(x)*a%m,m);
  if(r%g) return -1;
  if(x==r) return c;
  unordered_map<int,int> u;
  g=phi(m/g),u[x]=0; g=pm(a,g-at%g,m);
  for(i=1;i<at;i++){ // Baby Step
    u.insert(PII(x=LL(x)*a%m,i));
    if(x==r) return c+i;
  }
  for(i=1;i<at;i++){ // Giant Step
    unordered_map<int,int>::iterator t=u.find(r=LL(r)*g%m);
    if(t!=u.end()) return c+i*at+t->second;
  }
  return -1;
}

int get(int a, int n, int m) {
  vector<int> fac;
  for (int i = 1; i * i <= n; ++ i) {
    if (n % i == 0) fac.push_back(i), fac.push_back(n / i);
  }
  sort(fac.begin(), fac.end());
  for (size_t i = 0; i < fac.size(); ++ i) {
    if (pm(a, fac[i], m) == 1) return fac[i];
  }
  return -1;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int A, C, M, K; cin >> A >> C >> M >> K;
    int X = log(A, C, M);
    if (X == -1) puts("0");
    else {
      int phi = M, N = M;
      for (int i = 2; i * i <= M; ++ i) {
        if (M % i == 0) {
          phi = phi / i * (i - 1);
          while (M % i == 0) M /= i;
        }
      }
      if (M > 1) phi = phi / M * (M - 1);
      phi = get(A, phi, N);
      LL ret = (LL)K * X % MOD;
      ret += ((LL)K * (K - 1) / 2) % MOD * phi % MOD;
      ret %= MOD;
      printf("%lld\n", ret);// LL(K) * (X * 2 + (LL)phi * (K - 1)) / 2);
    }
  }
  return 0;
}