#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[4];
    string s;
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    cin >> s;
    int ret = 0;
    for (auto x : s) ret += a[x - '1'];
    cout << ret << endl;
}
