#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

char a[10], b[10];

inline void output_space(int n) {
	for (int i = 0; i < n; ++ i) printf("  ");
}

void solve(int cur, int n) {
	char d[100];
	output_space(cur);
	if (cur == n) {
		printf("writeln(");
		printf("%c", a[0]);
		for (int i = 1; i < n; ++ i) printf(",%c", a[i]);
		puts(")"); return;
	}
	char c = b[cur];
	a[cur] = b[cur];
	a[cur + 1] = '\0';
	strcpy(d, a);
	if (cur > 0) {
		printf("if %c < %c then\n", a[cur - 1], a[cur]);
		solve(cur + 1, n);
		for (int i = cur - 1; i > 0; -- i) {
			strcpy(a, d);
			output_space(cur);
			printf("else if %c < %c then\n", a[i - 1], a[cur]);
			for (int j = cur; j > i; -- j) a[j] = a[j - 1]; a[i] = c;
			solve(cur + 1, n);
		}
		strcpy(a, d);
		for (int j = cur; j > 0; -- j) a[j] = a[j - 1]; a[0] = c;
		output_space(cur);
		puts("else");
		solve(cur + 1, n);
	} else solve(cur + 1, n);
}

int main() {
	int T, N; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) b[i] = 'a' + i;
		puts("program sort(input,output);\nvar");
		printf("%c", b[0]);
		for (int i = 1; i < N; ++ i) printf(",%c", b[i]);
		puts(" : integer;\nbegin");
		printf("  readln(%c", b[0]);
		for (int i = 1; i < N; ++ i) printf(",%c", b[i]);
		printf(");\n");
		solve(0, N);
		printf("end.\n");
		if (T) puts("");
	}
	return 0;
}
