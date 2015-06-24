#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;
char s[MAXN];
int a[MAXN], n;

int min_index(char *s, int n) {// O(N)
    for (int i=0,j=1,k,ci,cj;;) {
        for (k=0;k<n;++k) 
            if ((ci=s[(i+k)%n])!=(cj=s[(j+k)%n])) break;
        if (k==n) return min(i,j);
        if (ci>cj) i+=k+1,i+=(i==j);
        else j+=k+1,j+=(i==j);
    }
    return -1;
}

int main() {
    scanf("%d%s", &n, s);
    string ret(s);
    for (int i = 0; i < n; ++ i) a[i] = s[i] - '0';
    for (int _ = 0; _ < 10; ++ _) {
        for (int i = 0; i < n; ++ i) a[i] = (a[i] + 1) % 10;
        for (int i = 0; i < n; ++ i) s[i] = char('0' + a[i]);
        int id = min_index(s, n);
        rotate(s, s + id, s + n);
        if (ret > string(s)) ret = string(s);
    }
    cout << ret << endl;
    return 0;
}
