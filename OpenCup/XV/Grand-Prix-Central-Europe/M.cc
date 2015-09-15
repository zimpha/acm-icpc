#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    int n = a << 8 | b, r = 0;
    for (int i = 0; i < 16; i += 2) {
        a = (n >> i) & 1;
        b = (n >> (i + 1)) & 1;
        if (a != b) {r = -1; break;}
        r += a << (i >> 1);
    }
    cout << r << endl;
    return 0;
}