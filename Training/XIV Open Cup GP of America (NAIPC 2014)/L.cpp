#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(const string &phone, const string &word) {
	if (word.length() < 4) return false;
	int cnt[26];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < (int)phone.length(); ++ i) cnt[phone[i] - 'A'] ++;
	for (int i = 0; i < (int)word.length(); ++ i) cnt[word[i] - 'A'] --;
	for (int i = 0; i < 26; ++ i) if (cnt[i] < 0) return false;
	for (int i = 0; i < (int)word.length(); ++ i) {
		if (word[i] == phone[4]) return true;
	}
	return false;
}

int main() {
	string phone, word;
	while (getline(cin, phone)) {
		if (phone == "0") break;
		int N; cin >> N; getline(cin, word);
		while (N --) {
			getline(cin, word);
			if (check(phone, word)) cout << word << " is valid\n";
			else cout << word << " is invalid\n";
		}
	}
	return 0;
}
