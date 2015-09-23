#include <bits/stdc++.h>
#include "kol.h"
using namespace std;
const int MAXN = 5000 + 10;
vector<int> user, G[MAXN];

int main() {
    srand(time(NULL));
    int n = 5000;
    user.resize(n);
    for (int i = 0; i < n; ++ i) user[i] = rand() % 10;
    for (int _ = 0; _ < 300000; ++ _) {
        int a, b; a = b = 1;
        while (user[a] == user[b]) {
            a = rand() % n;
            b = rand() % n;
        }
        if (a < b) swap(a, b);
        G[a].push_back(b);
    }
    init();
    for (int i = 0; i < n; ++ i) create(G[i]);
    answer(user);
    return 0;
}
