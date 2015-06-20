#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, ret = 0; cin >> n;
    for (long long h = 1; (h + 1) * h / 2 * 3 <= h + n; ++ h) {
        if ((h + n) % 3 == 0) ++ ret;
    }
    cout << ret << endl; 
    return 0;
}
