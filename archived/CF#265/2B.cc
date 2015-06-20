#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a[2000];
    cin >> n;
    for (int i = 0; i < n; ++ i) cin >> a[i];
    int cnt = 0, ret = 0;
    for (int i = 0, j; i < n; ) {
        if (a[i] == 0) ++ i;
        else {
            for (j = i; j < n && a[j] == 1; ++ j);
            ret += j - i; ++ cnt; i = j;
        }
    }
    if (ret == 0) cnt = 1;
    cout << ret + cnt - 1 << endl;
    return 0;
}
