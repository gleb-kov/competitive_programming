#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

struct stackvertex {
    map<string, stackvertex *> nextword;
};

string t, s;
char c, q;
stackvertex *p = new stackvertex;
stackvertex *cur;

void push() {
    cur = p;
    t = "";
    for (int i = 0; i < s.length(); i++) {
        if ((int) s[i] == 92) {
            if (cur->nextword[t] == NULL) {
                cur->nextword[t] = new stackvertex;
            }
            cur = cur->nextword[t];
            t = "";
        } else t += s[i];
    }
    if (cur->nextword[t] == NULL) {
        cur->nextword[t] = new stackvertex;
    }
}

void print(stackvertex *&cur, string now, int amount = 0) {
    for (int i = 0; i < amount - 1; i++) cout << " ";
    if (now != "") cout << now << endl;
    amount++;

    for (auto it = cur->nextword.begin(); it != cur->nextword.end(); it++) {
        if (it->second != NULL) {
            print(it->second, it->first, amount);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        push();
    }
    print(p, "");
    return 0;
}