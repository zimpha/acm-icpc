#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
 
int t, n, sum;
char ci[105][105];
 
int cmp(const void *a, const void *b) {
    return strcmp((char*) a, (char*) b);
}
int main() {
    scanf("%d", &t);
    while (t --) {
    sum = 0;
    memset(ci, 0, sizeof(ci));
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i ++)
        scanf("%s", ci[i]);
    qsort(ci, n, sizeof(ci[0]), cmp);
    sum = strlen(ci[0]);
    for (int i = 1; i < n; i ++) {
        int len;
        for (len = 0; len < (int)strlen(ci[i]); len ++) {
        if (ci[i - 1][len] != ci[i][len])
            break;
        }
        sum += strlen(ci[i]) - len;
    }
    printf("%d\n", sum);
    for (int i = 0; i < n; i ++)
        printf("%s\n", ci[i]);
    }
    return 0;
}
