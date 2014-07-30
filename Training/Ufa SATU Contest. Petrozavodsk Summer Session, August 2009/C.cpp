#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    cout << N * (N - 1) / 2 << endl;
    for (int i = 0; i < N; ++ i) {
        for (int d = 1; d <= N / 2; ++ d) {
            int x = i + 1, y = (i + d) % N + 1, z = (i + d + d) % N + 1;
            cout << x << " " << y << " " << z << endl;
        }
    }
    return 0;
}
