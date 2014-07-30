#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const int MAXN = 10001;

int A[MAXN][MAXN], N, M;

int main() {
	FILE *fin;
	fin = fopen("c.in", "rb");
	fread(&N, sizeof(N), 1, fin);
	fread(&M, sizeof(M), 1, fin);
	for (int i = 0;  i < N; ++ i) {
		fread(A[i], sizeof(int), M, fin);
	}
	int X, Y;
	while (fread(&X, sizeof(X), 1, fin) != 0) {
		fread(&Y, sizeof(Y), 1, fin);
		int ret = 0, l = 0, r = M - 1;
		for (int i = N - 1; i >= 0; -- i) {
			while (l < M && A[i][l] < X) l ++;
			ret -= l;
		}
		for (int i = 0; i < N; ++ i) {
			while (r >= 0 && A[i][r] > Y) r --;
			ret += r + 1;
		}
		printf("%d\n", ret);
	}
	fclose(fin);
	return 0;
}
