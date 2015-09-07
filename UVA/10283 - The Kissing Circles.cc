#include <bits/stdc++.h>
using namespace std;

const double PI = M_PI;

int main() {
    double R, N;
    while (scanf("%lf%lf", &R, &N) == 2) {
        if (N == 1) {
            printf("%.10f %.10f %.10f\n", R, 0.0, 0.0);
            continue;
        }
        if (N == 2) {
            printf("%.10f %.10f %.10f\n", R / 2, 0.0, PI * R * R / 2);
            continue;
        }
        double alpha = PI * 2 / N;
        double r = R / (1 + 1 / sin(alpha / 2));
        double a = 2 * r, r1 = a / (2 * sin(alpha / 2));
        double I = N / 2 * r1 * r1 * sin(alpha) - (N - 2) / 2 * PI * r * r;
        double E = PI * R * R - I - N * PI * r * r;
        printf("%.10f %.10f %.10f\n", r, I, E);
    }
    return 0;
}
