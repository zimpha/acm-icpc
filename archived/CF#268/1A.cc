#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    if (n <= 3) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        if (n == 4) {
            cout << "1 * 2 = 2" << endl;
            cout << "2 * 3 = 6" << endl;
            cout << "6 * 4 = 24" << endl;
        }
        else if (n == 5) {
            cout << "5 - 2 = 3" << endl;
            cout << "3 + 3 = 6" << endl;
            cout << "4 * 6 = 24" << endl;
            cout << "24 * 1 = 24" << endl;
        }
        else {
            cout << "2 * 3 = 6" << endl;
            cout << "6 * 4 = 24" << endl;
            cout << "6 - 5 = 1" << endl;
            cout << "1 - 1 = 0" << endl;
            for (int i = 7; i <= n; ++ i) {
                cout << i << " * 0 = 0" << endl;
            }
            cout << "0 + 24 = 24" << endl;
        }
    }
    return 0;
}
