#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long LL;
const int MAXN = 500000 + 10;
map<int, vi> mp;
int a[MAXN], n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) scanf("%d", &a[i]);
    LL sum = 0;
    for (int i = 0; i < n; ++ i) {
        sum += a[i]; mp[sum].push_back(i);
    }
    LL tmp = 0, ret = 0;
    for (int i = n - 1; i >= 0; -- i) {
        tmp += a[i]; if (tmp * 3 != sum) continue;
        vi &v = mp[tmp];
        int add = lower_bound(v.begin(), v.end(), i - 1) - v.begin();
        ret += max(add, 0);
    }
    cout << ret << endl;
    return 0;
}
