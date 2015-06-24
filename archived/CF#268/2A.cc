#include <bits/stdc++.h>
using namespace std;

bitset<200> A, B;

int main() {
    int n, m; cin >> n;
    cin >> m;
    for (int i = 0; i < m; ++ i) {
        int x; cin >> x;
        A.set(x - 1);
    }
    cin >> m;
    for (int i = 0; i < m; ++ i) {
        int x; cin >> x;
        B.set(x - 1);
    }
    A = A | B;
    if (A.count() == n) cout << "I become the guy.\n";
    else cout << "Oh, my keyboard!\n";
    return 0;
}
