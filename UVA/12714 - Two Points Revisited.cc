#include <cstdio>
#include <cstdlib>

int main() {
    int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
        int X1, X2, Y1, Y2;
		scanf("%d%d%d%d", &X1, &X2, &Y1, &Y2);
        int t1 = abs(Y2 - X2), t2 = abs(Y1 - X1);
        printf("Case %d: ", cas);
		if (X1 < Y1 && X2 < Y2) printf("%d 0 0 %d\n", t1, t2);
		else if (Y1 < X1 && Y2 < X2) printf("%d 0 0 %d\n", t1, t2);
		else if (X1 < Y1 && X2 > Y2) printf("0 0 %d %d\n", t1, t2);
		else if (Y1 < X1 && Y2 > X2) printf("0 0 %d %d\n", t1, t2);
		else printf("0 0 %d %d\n", t1, t2);
    }
    return 0;
}


