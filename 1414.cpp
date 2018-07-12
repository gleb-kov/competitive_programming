#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

struct stackvertex {
	bool flag;
	int col;
	map<char, stackvertex*> nextword;
	stackvertex() {
		flag = false;
		col = 0;
	}
};

string s;
char c, q;
stackvertex *p = new stackvertex;
stackvertex *cur;

void push() {
	cur = p;
	for (int i = 0; i < s.length(); i++) {
		c = s[i];
		if (cur->nextword[c] == NULL) {
			cur->nextword[c] = new stackvertex;
		}
		cur = cur->nextword[c];
		cur->col++;
	}
	cur->flag = true;
}

void findword(stackvertex* &cur, string now, int amount = 0) {
	if (cur->flag) {
		cout << "  " << now<<endl;
		amount++;
	}
	for (auto it = cur->nextword.begin(); it != cur->nextword.end() && amount<20; it++) {
		if (it->second != NULL) {
			findword(it->second, now + it->first, amount);
			amount += it->second->col;
		}
	}
}

int main()
{
	s = "sun";
	push();
	while (cin >> q >> s) {
		if (q == '?') {
			cout << s << endl;
			cur = p;
			for (int i = 0; i < s.length() && cur != NULL; i++) {
				cur = cur->nextword[s[i]];
			}
			if (cur != NULL) findword(cur, s);
		}
		else push();
	}
	return 0;
}