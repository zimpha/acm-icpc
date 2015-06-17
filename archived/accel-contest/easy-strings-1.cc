#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 300000 + 10;
char s[MAXN];
int z[MAXN], n;

void calcZ(char *s, int n, int z[]) {
  memset(z, 0, sizeof(z[0]) * n);
  for (int i=1,x=0,y=0;i<n;++i) {
    if (i<=y) z[i]=min(y-i,z[i-x]);
    while (i+z[i]<n&&s[i+z[i]]==s[z[i]]) z[i]++;
    if (y<=i+z[i]) x=i,y=i+z[i];
  }
  z[0] = n;
}

int main() {
  scanf("%s", s); n = strlen(s);
  calcZ(s, n, z);
  int ret = 0;
  //YYW
  for (int i = 1; i + 1 < n; ++ i) ret += z[i] >= i && i * 2 < n;
  //YWY
  for (int i = n - 1; i >= 0; -- i) {
    int l = n - i;
    if (z[i] == l && l * 2 < n) ++ ret;
  }
  //WYY
  reverse(s, s + n); calcZ(s, n, z);
  for (int i = 1; i + 1 < n; ++ i) ret += z[i] >= i && i * 2 < n;
  cout << ret << endl;
  return 0;
}

