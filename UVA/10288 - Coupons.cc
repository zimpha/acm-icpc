#include <bits/stdc++.h>
using namespace std;

int len(long long n) {
    char st[100];
    sprintf(st, "%lld", n);
    return strlen(st);
}

int main() {
    long long A, B, N;
    while (cin >> N) {
        A = 0, B = 1;
        for (int i = 1; i <= N; ++ i) {
            A = A * i + B * N; B = B * i;
            long long g = __gcd(A, B);
            A /= g; B /= g;
        }
        if (B == 1) cout << A << endl;
        else {
            long long C = A / B; A %= B;
            for (int i = 0; i <= len(C); ++ i) cout << " ";
            cout << A << endl;
            cout << C << " ";
            for (int i = 0; i < len(B); ++ i) cout << "-";
            cout << endl;
            for (int i = 0; i <= len(C); ++ i) cout << " ";
            cout << B << endl;
        }
    }
    return 0;
}
