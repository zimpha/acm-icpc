#include <bits/stdc++.h>
using namespace std;

int main() {
    double S, s3 = sqrt(3.0), s7 = sqrt(7.0);
    while (scanf("%lf", &S) == 1) {
        printf("%.10f %.10f %.10f %.10f\n", S * s3 / 2, S / (1 + 2 / s3), S / (s3 + 1 / s3), S / (2 / s3 + 4 / s7));
    }
    return 0;
}
