#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

class Reference {
public:
	bool isBook;
	vector<vector<string> > author;
	vector<string> pages;
	string title, journal;
	int year, volume, number;

	bool operator < (const Reference &rhs) const {
		if (author != rhs.author) return author < rhs.author;
		if (title != rhs.title) return title < rhs.title;
		return volume < rhs.volume;
	}
};

vector<Reference> R;

int get(string str) {
	int ret = 0;
	for (int i = 0; i < (int)str.length(); ++ i) 
		ret = ret * 10 + str[i] - '0';
	return ret;
}

vector<string> split(string S, string T) {
	vector<string> Q;
	S += T; Q.clear();
	for (int i = 0, p = 0; i < (int)S.length(); ++ i) {
		if (S.substr(i, T.length()) == T) {
			Q.push_back(S.substr(p, i - p));
			p = i + T.length();
		}
	}
	return Q;
}

int main() {
	freopen("bibtex.in", "r", stdin);
	freopen("bibtex.out", "w", stdout);
	string head, col, name, line;
	char buffer[2000];
	R.clear();
	while (cin >> head) {
		cin >> col; 
		Reference now;
		now.volume = now.number = 0;
		now.pages.clear();
		now.isBook = (head == "@book");
		while (cin >> name && name != "}") {
			if (name == ",") continue;
			cin >> col;
			for (char ch; (ch = getchar()) != '"';);
			scanf("%[^\"]", buffer); getchar();
			line = (string)buffer;
			if (name == "author") {
				vector<string> tmp = split(line, " and ");
				now.author.clear();
				for (int i = 0; i < (int)tmp.size(); ++ i) {
					now.author.push_back(split(tmp[i], " "));
					vector<string> &vs = now.author.back();
					rotate(vs.begin(), vs.begin() + vs.size() - 1, vs.end());
				}
				sort(now.author.begin(), now.author.end());
			}
			else if (name == "title") {
				now.title = line;
			}
			else if (name == "journal" || name == "publisher") {
				now.journal = line;
			}
			else if (name == "year") {
				now.year = get(line);
			}
			else if (name == "volume") {
				now.volume = get(line);
			}
			else if (name == "number") {
				now.number = get(line);
			}
			else if (name == "pages") {
				now.pages = split(line, "--");
			}
		}
		R.push_back(now);
	}
	sort(R.begin(), R.end());
	for (int i = 0; i < (int)R.size(); ++ i) {
		printf("[%d] ", i + 1);
		for (int j = 0; j < (int)R[i].author.size(); ++ j) {
			if (j) printf(", ");
			vector<string> &vs = R[i].author[j];
			printf("%s", vs[0].c_str());
			for (int k = 1; k < (int)vs.size(); ++ k) {
				printf(" %c.", vs[k][0]);
			}
		}
		printf(" %s", R[i].title.c_str());
		if (R[i].isBook) {
			if (R[i].volume) printf(", Vol. %d", R[i].volume);
			printf(" -- %s, %d", R[i].journal.c_str(), R[i].year);
		}
		else {
			printf(" // %s", R[i].journal.c_str());
			if (R[i].volume) printf(", %d", R[i].volume);
			if (R[i].number) printf(" (%d)", R[i].number);
			printf(" -- %d", R[i].year);
			if ((int)R[i].pages.size() == 1) {
				printf(" -- p. %s", R[i].pages[0].c_str());
			}
			if ((int)R[i].pages.size() == 2) {
				printf(" -- pp. %s--%s", R[i].pages[0].c_str(), R[i].pages[1].c_str());
			}
		}
		puts("");
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
