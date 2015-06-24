#include <bits/stdc++.h>
using namespace std;

int cnt[10];

int main() {
    for (int i = 0; i < 6; ++ i) {
        int x; cin >> x; cnt[x] ++;
    }
    for (int i = 1; i < 10; ++ i) 
        if (cnt[i] >= 4) cnt[i] -= 4;
    vector<int> v;
    for (int i = 1; i < 10; ++ i) {
        while (cnt[i]) v.push_back(i), cnt[i] --;
    }
    if (v[0] > v[1]) swap(v[0], v[1]);
    if (v.size() != 2) cout << "Alien" << endl;
    else {
        if (v[0] != v[1]) cout << "Bear" << endl;
        else cout << "Elephant" << endl;
    }
    return 0;
}
