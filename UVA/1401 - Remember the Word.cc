#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MOD = 20071027;
const int SIZE = 400010;

struct Node {
	Node* ch[26];
	bool flag;
} pool[SIZE], *null, *cnt, *root;

char st[SIZE];
int dp[SIZE];

void init() {
	null = pool; null->flag = false;
	for (int i = 0; i < 26; ++ i) {
		null->ch[i] = null;
	}
	cnt = pool + 1;
}

Node* new_node() {
	for (int i = 0; i < 26; ++ i) {
		cnt->ch[i] = null;
	}
	cnt->flag = false;
	return cnt ++;
}

void insert(char s[]) {
	Node *p = root;
	for (int i = 0; s[i]; ++ i) {
		if (p->ch[s[i] - 'a'] == null) p->ch[s[i] - 'a'] = new_node();
		p = p->ch[s[i] - 'a'];
	}
	p->flag=true;
}

void query(char s[], int dp[], int t) {
	Node *p = root;
	for (int i = 0; s[i]; ++ i) {
		if (p->ch[s[i] - 'a'] == null) return;
		p = p->ch[s[i] - 'a'];
		if (p->flag) dp[t] = (dp[t] + dp[t + i +1]) % MOD;
	}
}

int main() {
	int S, n, cas = 0;
	while (scanf("%s", st) == 1) {
		scanf("%d", &S);
		init(); 
		root = new_node();
		n = strlen(st);
		for (int i = 0; i < S; ++ i) {
			char tmp[200]; scanf("%s", tmp);
			insert(tmp);
		}
		memset(dp, 0, sizeof(dp));
		dp[n] = 1;
		for (int i = n - 1; i >=0; -- i) {
			query(st + i, dp, i);
		}
		printf("Case %d: %d\n", ++ cas, dp[0]);
	}
	return 0;
}
