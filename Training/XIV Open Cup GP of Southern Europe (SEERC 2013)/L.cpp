#include <cstdio>

int main() {
	freopen("l.in", "r", stdin);
	int l, w, h, v;
	while (scanf("%d%d%d%d", &w, &h, &l, &v) == 4 && (w + h +l + v)) {
		if (!w) w = v / h / l;
		if (!h) h = v / w / l;
		if (!l) l = v / w / h;
		if (!v) v = w * h * l;
		printf("%d %d %d %d\n", w, h, l, v);
	}
	fclose(stdin); 
	return 0;
}
