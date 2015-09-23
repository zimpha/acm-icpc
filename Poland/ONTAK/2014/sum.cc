#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<LL> VI;

VI solve(VI v) {
    if (v.empty()) return VI();
    VI even, odd;
    for (int i = 0; i < (int)v.size(); ++ i) {
        if (v[i] & 1) odd.push_back(v[i]);
        else even.push_back(v[i] / 2);
    }
    LL mx = 1e18;
    for (int i = 0; i < (int)odd.size(); ++ i) mx = min(mx, odd[i]);
    for (int i = 0; i < (int)odd.size(); ++ i) {
        odd[i] -= mx;
        if (odd[i]) even.push_back(odd[i] / 2);
    }
    odd = solve(even);
    for (int i = 0; i < (int)odd.size(); ++ i) odd[i] <<= 1;
    if (mx != LL(1e18)) odd.push_back(mx);
    return odd;
}

string toBin(LL x) {
    string s = "";
    for (int i = 0; i < 60; ++ i) {
        s = char('0' + ((x >> i) & 1)) + s;
    }
    return s;
}

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        VI ret; int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++ i) {
            LL x; scanf("%lld", &x);
            ret.push_back(x);
        }
        for (size_t i = 0; i < ret.size(); ++ i) {
            printf("%s\n", toBin(ret[i]).c_str());
        }
        ret = solve(ret);
        sort(ret.begin(), ret.end());
        printf("TAK\n%d\n", (int)ret.size());
        for (size_t i = 0; i < ret.size(); ++ i) {
            printf("%lld%c", ret[i], " \n"[i == ret.size() - 1]);
        }
        for (size_t i = 0; i < ret.size(); ++ i) {
            printf("%s\n", toBin(ret[i]).c_str());
        }
    }
    return 0;
}
