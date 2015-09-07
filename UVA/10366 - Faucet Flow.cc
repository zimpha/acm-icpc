#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 3000;

int leftx, rightx, delta;
int height[MAXN];

int main() {
	while (scanf("%d%d", &leftx, &rightx) == 2 && leftx != 0) {
		delta = -leftx;
		for (int i = leftx; i <= rightx; i += 2) scanf("%d", &height[i + delta]);

		int lm_id = -1, rm_id = 1;
		for (int i = -1; i >= leftx; i -= 2)
			if (height[i + delta] > height[lm_id + delta]) lm_id = i;
		for (int i = 1; i <= rightx; i += 2)
			if (height[i + delta] > height[rm_id + delta]) rm_id = i;
		int lmax = height[lm_id + delta], rmax = height[rm_id + delta];

		int lt = 0, rt = 0;
		for (int i = leftx, p = leftx; i <= lm_id; i += 2) {
			if (height[i + delta] >= height[p + delta]) {
				lt += (i - p) * height[p + delta];
				p = i;
			}
		}
		for (int i = rightx, p = rightx; i >= rm_id; i -= 2) {
			if (height[i + delta] >= height[p + delta]) {
				rt += (p - i) * height[p + delta];
				p = i;
			}
		}

		int ret = 0;
		if (lmax == rmax) ret = (rm_id - lm_id) * lmax + min(lt, rt) * 2;
		else if (lmax > rmax) {
			for (int i = -1; i >= leftx; i -= 2) {
				if (height[i + delta] >= rmax) {lm_id = i; lmax = height[i + delta]; break;}
			}
			if (lmax == rmax) {
				int tmp = 0;
				for (int i = lm_id; i >= leftx; i -= 2) 
					if (height[i + delta] > rmax) {lmax = height[i + delta]; tmp = i; break;}
				ret = (rm_id - lm_id) * rmax + min((lm_id - tmp) * rmax, rt) + rt;
			} else ret = (rm_id - lm_id) * rmax + rt;
		} else {
			for (int i = 1; i <= rightx; i += 2) {
				if (height[i + delta] >= lmax) {rm_id = i; rmax = height[i + delta]; break;}
			}
			if (lmax == rmax) {
				int tmp = 0;
				for (int i = rm_id; i <= rightx; i += 2) 
					if (height[i + delta] > lmax) {rmax = height[i + delta]; tmp = i; break;}
				ret = (rm_id - lm_id) * lmax + min((tmp - rm_id) * lmax, lt) + lt;
			} else ret = (rm_id - lm_id) * lmax + lt;
		}

		printf("%d\n", ret);
	}
	return 0;
}
