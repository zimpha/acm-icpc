#include <bits/stdc++.h>
using namespace std;
typedef double flt;
const int MAXN= 200;
const flt eps= 1e-8;

flt a[MAXN][MAXN], b[MAXN];
int w, h, s;

bool gauss(flt a[][MAXN],flt b[],int n){
  for(int k=0,i,j,s;k<n;++k){
    for(s=k,i=k+1;i<n;++i)
    if(fabs(a[i][k])>fabs(a[s][k]))s=i;
    if(fabs(a[s][k])<eps)return false;
    if(s!=k){
      swap(b[s],b[k]);
      for(i=k;i<n;++i)swap(a[s][i],a[k][i]);
    }
    for(j=k+1;j<n;++j){
      flt t=-a[j][k]/a[k][k];
      b[j]+=b[k]*t;
      for(i=k+1;i<n;++i)a[j][i]+=t*a[k][i];
    }
  }
  for(int i=n-1;i>=0;--i){
    b[i]/=a[i][i];
    for(int j=0;j<i;++j)b[j]-=a[j][i]*b[i];
  }
  return 1;
}

int main() {
  while (scanf("%d%d%d", &w, &h, &s) == 3) {
    int n = w * h;
    memset(a, 0, sizeof(a));
    map<int, int> mp;
    for (int i = 0; i < n; ++ i) b[i] = a[i][i] = 1;
    for (int i = 0; i < s; ++ i) {
      int u, v; scanf("%d%d", &u, &v);
      -- u, -- v; mp[u] = v;
    }
    for (int i = 0; i < n - 1; ++ i) {
      for (int d = 1; d <= 6; ++ d) {
        int j = i + d;
        if (j > n - 1) j = n * 2 - 2 - j;
        if (mp.count(j)) j = mp[j];
        //cout << i << "->" << j << endl;
        a[i][j] -= 1.0 / 6;
      }
    }
    gauss(a, b, n);
    printf("%.10f\n", b[0] - 1);
  }
  return 0;
}