#include <bits/stdc++.h>
using namespace std;

const double PI = M_PI;

int main() {
    double f;
    while (scanf("%lf", &f) == 1) {
        printf("%.10f\n", f * sin(PI * 108 / 180) / sin(PI * 63 / 180));
    }
    return 0;
}
