#include <cstdio>
#include <cstring>
#include <cstdlib>

const char* mahjong[] = {
"1T", "2T", "3T", "4T", "5T", "6T", "7T", "8T", "9T",
"1S", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S",
"1W", "2W", "3W", "4W", "5W", "6W", "7W", "8W", "9W",
"DONG", "NAN", "XI", "BEI",
"ZHONG", "FA", "BAI"
};

int ID(char *s) {
	for (int i = 0; i < 34; ++ i)
		if (strcmp(s, mahjong[i]) == 0) return i;
	return -1;
}

int cnt[34];

bool search(int dep) {
	for (int i = 0; i < 34; ++ i) 
		if (cnt[i] >= 3) {
			if (dep == 3) return true;
			cnt[i] -= 3;
			if (search(dep + 1)) return true;
			cnt[i] += 3;
		}
	for(int i = 0; i <= 24; ++ i) 
		if (i % 9 <= 6 && cnt[i] > 0 && cnt[i + 1] > 0 && cnt[i + 2] > 0) {
			if (dep == 3) return true;
			cnt[i] --, cnt[i + 1] --, cnt[i + 2] --;
			if (search(dep + 1)) return true;
			cnt[i] ++, cnt[i + 1] ++, cnt[i + 2] ++;
		}
	return false;
}

bool check() {
	for (int i = 0; i < 34; ++ i) {
		if (cnt[i] > 1) {
			cnt[i] -= 2;
			if (search(0)) return true;
			cnt[i] += 2;
		}
	}
	return false;
}

int main() {
	int cas = 0, mj[15];
	char st[100];
	while (scanf("%s", st) == 1 && st[0] != '0') {
		printf("Case %d:", ++ cas);
		mj[0] = ID(st);
		for (int i = 1; i < 13; ++ i) {
			scanf("%s", st);
			mj[i] = ID(st);
		}
		bool flag = false;
		for (int i = 0; i < 34; ++ i) {
			memset(cnt, 0, sizeof(cnt));
			for (int j = 0; j < 13; ++ j) cnt[mj[j]] ++;
			if (cnt[i] >= 4) continue;
			cnt[i] ++;
			if (check()) {
				flag = true;
				printf(" %s", mahjong[i]);
			}
			cnt[i] --;
		}
		if (flag) puts("");
		else puts(" Not ready");
	}
	return 0;
}
