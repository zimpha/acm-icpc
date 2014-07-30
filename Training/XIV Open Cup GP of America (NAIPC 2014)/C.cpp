#include <string>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const char lkey[4][10] = {
{'q','w','e','r','t','y','u','i','o','p'},
{'a','s','d','f','g','h','j','k','l',';'},
{'z','x','c','v','b','n','m',',','.','/'},
{'-','-',' ',' ',' ',' ',' ',' ','-','-'}
};

const char ukey[4][10] = {
{'Q','W','E','R','T','Y','U','I','O','P'},
{'A','S','D','F','G','H','J','K','L',':'},
{'Z','X','C','V','B','N','M','<','>','?'},
{'-','-',' ',' ',' ',' ',' ',' ','-','-'}
};

const int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

bool dp[200][4][10][4][10];
bool vis[4][10][4][10][2][2];
string text;

bool fitRange(int x, int y) {
	if (x < 0 || x > 3 || y < 0 || y > 9) return false;
	return true;
}

bool isShift(int x, int y) {
	if (x == 3 && (y < 2 || y > 7)) return true;
	return false;
}

bool checkPosition(char c, int x1, int y1, int x2, int y2) {
	if (x1 == x2 && y1 == y2) return false;
	if (isShift(x2, y2)) return c == ukey[x1][y1];
	else return c == lkey[x1][y1];
}

void expand(bool dp[4][10][4][10], char c, int x1, int y1, int x2, int y2, int p1, int p2) {
	if (p1 + p2 > 1) return;
	if (p1) dp[x1][y1][x2][y2] |= checkPosition(c, x1, y1, x2, y2);
	if (p2) dp[x1][y1][x2][y2] |= checkPosition(c, x2, y2, x1, y1);
	for (int i = 0; i < 8; ++ i) {
		int xx1 = x1 + dx[i], yy1 = y1 + dy[i];
		if (!fitRange(xx1, yy1)) continue;
		int p = (!isShift(xx1, yy1));
		if (!vis[xx1][yy1][x2][y2][p1 + p][p2]) {
			vis[xx1][yy1][x2][y2][p1 + p][p2] = true;
			expand(dp, c, xx1, yy1, x2, y2, p1 + p, p2);
		}
	}
	for (int i = 0; i < 8; ++ i) {
		int xx2 = x2 + dx[i], yy2 = y2 + dy[i];
		if (!fitRange(xx2, yy2)) continue;
		int p = (!isShift(xx2, yy2));
		if (!vis[x1][y1][xx2][yy2][p1][p2 + p]) {
			vis[x1][y1][xx2][yy2][p1][p2 + p] = true;
			expand(dp, c, x1, y1, xx2, yy2, p1, p2 + p);
		}
	}
}

int main() {
	while (getline(cin, text)) {
		if (text == "*") break;
		memset(dp, 0, sizeof(dp)); dp[0][3][0][3][9] = true;
		int N = text.length();
		for (int i = 0; i < N; ++ i) {
			for (int x1 = 0; x1 < 4; ++ x1) for (int y1 = 0; y1 < 10; ++ y1) {
				for (int x2 = 0; x2 < 4; ++ x2) for (int y2 = 0; y2 < 10; ++ y2) {
					if (dp[i][x1][y1][x2][y2]) {
						memset(vis, 0, sizeof(vis));
						expand(dp[i + 1], text[i], x1, y1, x2, y2, 0, 0);
					}
				}
			}
		}
		bool ret = false;
		for (int x1 = 0; x1 < 4; ++ x1) for (int y1 = 0; y1 < 10; ++ y1) {
			for (int x2 = 0; x2 < 4; ++ x2) for (int y2 = 0; y2 < 10; ++ y2) {
				ret |= dp[N][x1][y1][x2][y2];
			}
		}
		cout << (int)ret << endl;
	}
	return 0;
}
