#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T --) {
        long long N; cin >> N;
        long long r = 9, ret;
        for (int i = 1; ; ++ i) {
            if (r >= N) {ret = 1; break;}
            r *= 2;
            if (r >= N) {ret = 2; break;}
            r *= 9;
        }
        cout << ret << endl;
    }
    return 0;
}