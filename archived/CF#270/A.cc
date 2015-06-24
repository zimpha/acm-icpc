#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
    for (int i = 2; i * i <= n; ++ i) {
        if (n % i == 0) return true;
    }
    return false;
}

int main() {
    int n; cin >> n;
    for (int i = 4; i <= n; ++ i) {
        if (check(i) && check(n - i)) {
            cout << i << " " << n - i << endl;
            break;
        }
    }
    return 0;
}
